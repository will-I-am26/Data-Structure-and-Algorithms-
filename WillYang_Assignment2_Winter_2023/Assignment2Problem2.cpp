/*
Calculate a postfix expression
*/

#include <iostream>	
#include <string>
#include <stack>
#include <sstream>
using namespace std;

const int MAXITEM = 10;

template<class ItemType>
struct NodeType
{
    ItemType info;
    NodeType* next;
};

template<class ItemType>
class stack2
{
private:
    NodeType<ItemType>* topPtr; // It points to a singly-linked list
public:

    // default constructor: Stack2 is created and empty
    stack2() {
        topPtr = NULL;
    }

    // copy constructor: implicitly called for a  
    //  deep copy
    stack2(const stack2<ItemType>& x) {
        // creates two pointers of NodeType
        NodeType<ItemType>* p1, * p2;

        // checks if the linked list we are copying from is NULL
        if (x.topPtr == NULL)
        {
            this->topPtr = NULL;
        }
        else
        {
            // creates a new node and copy the info
            topPtr = new NodeType<ItemType>();
            topPtr->info = x.topPtr->info;

            // then set p1 as the next node of the linked list we are copying from
            p1 = x.topPtr->next;

            // and then set p2 as the top pointer of the current linked list we are creating
            p2 = topPtr;

            // this populates the new linked list we are creating
            while (p1 != NULL)
            {
                p2->next = new NodeType<ItemType>();
                p2 = p2->next;
                p2->info = p1->info;
                p1 = p1->next;
            }
            // sets the last node next pointer to null;
            p2->next = NULL;
        }

    }

    // Stack2 is made empty; you should deallocate all the 
    //  the nodes of the linked list
    void MakeEmpty() {
        // makes a pointer
        NodeType<ItemType>* makeEmptyNode;

        // iterates through the linked list and delete each node until we reach NULL pointer
        while (topPtr != NULL)
        {
            makeEmptyNode = topPtr->next;
            delete topPtr;
            topPtr = makeEmptyNode;
        }
    }

    // test if the Stack2 is empty
    bool IsEmpty()
    {
        // if topPtr is null then the stack is empty.
        if (topPtr == NULL)
        {
            return true;
        }
        else
            return false;
    }

    // test if the Stack2 is full; assume MAXITEM=5
    bool IsFull()
    {
        // we need to count the elements of the linked list
        int count = 0;

        // make a tempory pointer so we can return topPtr to  
        // it's orginal location
        NodeType<ItemType>* tempPtr = topPtr;

        // go through the linked list and count the elements inside
        while (topPtr != NULL)
        {
            count++;
            topPtr = topPtr->next;
        }

        // return topPtr to the orginal location
        topPtr = tempPtr;

        // check if the number of elements if less then the max item
        if (count < MAXITEM)
        {
            return false;
        }
        else
        {
            return true;
        }
    }

    // return the number of elements in the Stack2
    int length()
    {
        // a counter to count the number of elements
        int count = 0;

        // a pointer to return topPtr to the orginal location
        NodeType<ItemType>* tempPtr = topPtr;

        // iterate through the linked list to count the elements until topPtr hits NULL
        while (topPtr != NULL)
        {
            count++;
            topPtr = topPtr->next;
        }
        // return topPtr to the orginal location
        topPtr = tempPtr;

        // return the number of elements of the linked list
        return count;
    }


    // print the value of all elements in the Stack2 in the sequence 
    // from the top to bottom
    void Print() {
        // a check to see if the linked list is empty of has elements.
        if (topPtr == NULL)
        {
            cout << "Nothing to print." << endl;
        }
        else
        {
            // just iterate through the linked list printing each element
            // then return the topPtr back to it's orginal location
            NodeType<ItemType>* tempPtr = topPtr;
            while (topPtr != NULL)
            {
                cout << topPtr->info << endl;
                topPtr = topPtr->next;
            }
            topPtr = tempPtr;
        }

    }

    // insert x onto the Stack2 
    void Push(ItemType x)
    {
        // creates a new node
        NodeType<ItemType>* n = new NodeType<ItemType>();

        // then insert the data we want it to have and set the address to the previous node
        n->info = x;
        n->next = topPtr;

        // set the top of the stack to the newly created node.
        topPtr = n;
    }

    // delete the top element from the Stack2
    // Precondition: the Stack2 is not empty
    void Pop(ItemType& x)
    {
        // checks if topPtr is not null
        if (topPtr != NULL)
        {
            // creates a temp pointer
            NodeType<ItemType>* temp = topPtr;

            // set x to the info inside of what the pointer is pointing to
            x = temp->info;

            // sets the topPtr to the node below the top of the stack
            topPtr = topPtr->next;

            // then deletes the node that was the top of the stack
            delete (temp);
        }
        else
        {
            cout << "Nothing to pop. List is empty." << endl;
        }
    }

    ItemType Top()
    {
        return topPtr->info;
    }

    // Destructor: memory for nodes needs to be deallocated
    ~stack2()
    {
        // creates a pointer to delete every node
        NodeType<ItemType>* nextNode;

        // iterate until topPtr hits NULL
        while (topPtr != NULL)
        {
            // set the nexNode pointer to the next node of topPtr
            nextNode = topPtr->next;

            // then delete topPtr
            delete topPtr;

            // then set the TopPtr to the next node.
            topPtr = nextNode;
        }
    }
};

class PostfixEvaluator
{
private:
    
    string postfixExpression;
    stack2 <int> digitStack;
    int y;
    int x;
    int tempDigit;
    int finalResult;

public:

    PostfixEvaluator()
    {

    }

    PostfixEvaluator(string postfixExpression)
    {
        this->postfixExpression = postfixExpression;
        this->postfixExpression.append(")");
    }

    void evaluatePostfixExpression()
    {
        for (int i = 0; i < postfixExpression.length(); i++)
        {
            if (postfixExpression.at(i) == '0' || postfixExpression.at(i) == '1' || postfixExpression.at(i) == '2' || postfixExpression.at(i) == '3' || postfixExpression.at(i) == '4' || postfixExpression.at(i) == '5'
                || postfixExpression.at(i) == '6' || postfixExpression.at(i) == '7' || postfixExpression.at(i) == '8' || postfixExpression.at(i) == '9')
            {
                tempDigit = (int(postfixExpression.at(i) - '0'));
                digitStack.Push(tempDigit);
            }
            else if (isOperator(postfixExpression.at(i)))
            {
                digitStack.Pop(x);
                digitStack.Pop(y);
                calculate(x, y, postfixExpression.at(i));

            }
            else if (postfixExpression.at(i) == ')')
            {
                digitStack.Pop(finalResult);
            }
        }
    }

    bool isOperator(char c)
    {


        return c == '+' || c == '-' || c == '*' ||
            c == '/' || c == '^' || c == '%';

      
    }

    bool precedence(char operator1, char operator2)
    {


        if (operator1 == '^')
        {
            return false;
        }
        else if (operator2 == '^')
        {
            return true;
        }
        else if (operator1 == '*' || operator1 == '/' || operator1 == '%')
        {
            return false;
        }
        else if (operator2 == '*' || operator2 == '/' || operator2 == '%')
        {
            return true;
        }
        else
        {
            return false;
        }

      
    }

    void calculate(int x, int y, char expressionOperator)
    {
        int result;

        if (expressionOperator == '*')
        {
            result = (y * x);
        }
        else if (expressionOperator == '/')
        {
            result = (y / x);
        }
        else if (expressionOperator == '+')
        {
            result = (y + x);
        }
        else if (expressionOperator == '-')
        {
            result = (y - x);
        }
        else if (expressionOperator == '^')
        {
            result = pow(y, x);
        }
        else if (expressionOperator == '%')
        {
            result = (y % x);
        }

        digitStack.Push(result);

    }

    string getPostfixExpression()
    {
        return postfixExpression;
    }

    int getFinalResult()
    {
        return finalResult;
    }

};


int main()
{
    
    string postfixExpression = "62+5*84/-";
    PostfixEvaluator Result(postfixExpression);

    cout << "The postfix expression is: " << postfixExpression << endl;
    Result.evaluatePostfixExpression();
    cout << "The result of this postfix expression is: " << Result.getFinalResult() << endl;

    

    




    system("pause");
    return 0;
}