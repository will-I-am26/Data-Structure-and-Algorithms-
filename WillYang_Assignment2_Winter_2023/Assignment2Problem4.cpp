/*
traversing nodes in a binary tree T and creating algorithms to return the node after the specified node
*/
#include <iostream>
using namespace std;

template<class ItemType>
struct NodeType
{
	ItemType info;
	NodeType* left;
	NodeType* right;
	NodeType* parent;
	

	NodeType(ItemType info)
	{
		this->info = info;
		this->right = nullptr;
		this->left = nullptr;
		this->parent = nullptr;
	}
};

template<class ItemType>
class binaryTree
{
private:

	

public:

	NodeType<ItemType>* root;

	binaryTree() 
	{
		root = nullptr;
	}

	void addNode(ItemType info)
	{
		NodeType<ItemType>* newNode = new NodeType<ItemType>(info);

		if (root == nullptr)
		{
			root = newNode;
		}
		else
		{
			NodeType<ItemType>* nodePointer = root;
			NodeType<ItemType>* parent;

			while (true)
			{
				parent = nodePointer;
				newNode->parent = parent;

				if (info < nodePointer->info)
				{
					nodePointer = nodePointer->left;
					if (nodePointer == nullptr)
					{
						parent->left = newNode;
						return;
					}
				}
				else
				{
					nodePointer = nodePointer->right;
					if (nodePointer == nullptr)
					{
						parent->right = newNode;
						return;
					}
				}
			}
		}
	}


	void preOrderTraversal(NodeType<ItemType>* root)
	{
		if (root != nullptr)
		{
			cout << root->info << " ";
			preOrderTraversal(root->left);
			preOrderTraversal(root->right);
		}
	}

	void inOrderTraversal(NodeType<ItemType>* root)
	{
		if (root == NULL)
		{
			return;
		}
		
		inOrderTraversal(root->left);

		cout << root->info << " ";

		inOrderTraversal(root->right);

	}

	void postOrderTraversal(NodeType<ItemType>* root)
	{
		if (root == NULL)
		{
			return;
		}
			
		// first recur on left subtree
		postOrderTraversal(root->left);

		// then recur on right subtree
		postOrderTraversal(root->right);

		// print the node info
		cout << root->info << " ";
	}

	void preorderNext(NodeType<ItemType>* root, int v)
	{
		// checks if the root is null
		if (root == nullptr)
		{
			return;
		}
		// find the node with the target value
		if (root->info == v)
		{
			// print the value in the left node that the current node is pointing to
			if (root->left != nullptr)
			{
				cout << "The value after " << v << " is " << root->left->info << endl;
			}
			// if there is no left node then print the right one.
			else if (root->right != nullptr)
			{
				cout << "The value after " << v << " is " << root->right->info << endl;
			}
			// if it's a node with no child
			else
			{
				// loops while the current node parent is not null
				while (root->parent != nullptr) 
				{
					// checks if the current node is it's parents left node
					if (root == root->parent->left) 
					{
						// prints the parents right node if it's not null 
						if (root->parent->right != nullptr) {
							cout << "The value after " << v << " is " << root->parent->right->info << endl;
							return;
						}
						// sets the current node to it's parent node
						else {
							root = root->parent;
						}
					}
					else {
						// the current node parent's parents is null just return nothing
						if (root->parent->parent == nullptr) {
							return;
						}
						// checks if the current node's parent is the current node's parents parents left node. It travels up and checks
						else if (root->parent == root->parent->parent->left) {
							// prints the value if the current node parent parent right node is not null. It travels up and checks
							if (root->parent->parent->right != nullptr) {
								cout << "The value after " << v << " is "  << root->parent->parent->right->info << endl;
								return;
							}
							else {
								// travels up the tree
								root = root->parent;
								
							}
						}
						else {
							// travels up the tree
							root = root->parent;
						}
					}
				}

			}
			
		}
		// this searches through the binary tree for the targeted value
		else
		{
			preorderNext(root->left, v);
			preorderNext(root->right, v);
		}
		
	}

	void inorderNext(NodeType<ItemType>* root, int v)
	{
		// checks if there is a node
		if (root == nullptr)
		{
			return;
		}
		// if the node with the targeted value is found
		if (root->info == v)
		{
			// if the current node right child is not null
			if (root->right != nullptr)
			{
				// set the current node to the right child
				root = root->right;
				
				// if the current node left pointer is not null 
				// go through the left children of the current node and it's descendants
				// to check if there is a lower value
				while (root->left != nullptr)
				{
					root = root->left;
				}
				cout << "The next value after " << v << " is " << root->info << endl;
			}
			// if the current node right child is null
			else
			{
				// this while loop goes up the binary tree
				while (root->parent != nullptr && root->parent->right == root)
				{
					root = root->parent;
				}
				// if the current node parent is not null
				if (root->parent != nullptr)
				{
					// print out the current node's parents info
					cout << "The next value after " << v << " is " << root->parent->info << endl;
				}
				else
				{
					// once it reach the end of the inOrder traversal
					cout << "There is no next node" << endl;
				}
			}
		}
		// this searches through the binary tree for the targeted value
		else
		{
			inorderNext(root->left, v);
			inorderNext(root->right, v);
		}
	}

};


int main()
{
	binaryTree<int> T;

	// Binary tree
	T.addNode(25);
	T.addNode(15);
	T.addNode(10);
	T.addNode(4);
	T.addNode(12);
	T.addNode(22);
	T.addNode(18);
	T.addNode(24);
	T.addNode(50);
	T.addNode(35);
	T.addNode(31);
	T.addNode(44);
	T.addNode(70);
	T.addNode(66);
	T.addNode(90);

	cout << "The preorder traversal is: ";
	T.preOrderTraversal(T.root);
	cout << endl;
	T.preorderNext(T.root, 24);
	cout << endl;
	cout << endl;

	cout << "The inorder traversal is: ";
	T.inOrderTraversal(T.root);
	cout << endl;
	T.inorderNext(T.root, 15);
	cout << endl;


	system("pause");
	return 0;
}
