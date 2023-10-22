/*
Suppose you are given an n-element array A containing distinct integers
that are listed in increasing order. Given a number k, describe a recursive
algorithm to find two integers in A that sum to k, if such a pair exists.
What is the runtime of the algorithm?
*/

#include <iostream>
#include <algorithm>
#include <time.h>
#include <stdlib.h>
#include <chrono>
using namespace std;
using namespace chrono;

// using a struct so that we can return a pair of integer and a bool to print them
struct sumPair
{
	int firstPair;
	int secondPair;
	bool findPair = false;
};

// the function that hold the recursive algorithm to get the pair in the array
sumPair recursiveFindPair(int arr[], int n, int k)
{
	// create an object called result
	sumPair result;
	if (n < 2)
	{
		// if the number of elements in the array is just 1, we know that there is not a pair
		// so just return the result object
		return result;
	}

	// a for loop that iterate at the the end of the array towards the begining of the array
	for (int i = (n-1); i > 1; i--)
	{
		// check if the first element of the array and the last element of the array equal to the target k
		if (arr[0] + arr[i] == k)
		{
			// sets the value in the struct to the value of the array and checks true for the bool value
			result.firstPair = arr[0];
			result.secondPair = arr[i];
			result.findPair = true;

			// if we do find it just return the object result
			return result;
		}
	}

	// call the function again but with an smaller array that starts with the next element of the array.
	return recursiveFindPair(arr + 1, n - 1, k);
}

int main()
{
	// value that are needed to create the array, target, and run time
	srand(time(NULL));
	const int n = 10000;
	int arr[n];
	int k = 5000;
	int value;
	
	
	// this is to create an array that have distinct values.
	for (int i = 0; i < n; i++)
	{
		// a check for distinct numbers
		bool distinct;
		do
		{
			distinct = true;
			// create a random number from 1 to 100000
			value = rand() % 100000 + 1;
			
			// a for loop to check if the value that was generated is a duplicate 
			for (int j = 0; j < i; j++)
			{
				// if it is a dupe, set distinct to false and break
				if (arr[j] == value)
				{
					distinct = false;
					break;
				}
			}
		} while (!distinct);
		
		// set the value it generated to the array element
		arr[i] = value;
	}

	// to sort the array in ascending order
	sort(arr, arr + n);

	auto start1 = steady_clock::now();
	// call the recursive function 
	sumPair dumpResult = recursiveFindPair(arr, n, k);
	
	auto dur = steady_clock::now() - start1;

	// a check to print out the pairs or to tell the user there
	// was no pair found
	if (dumpResult.findPair == true)
	{
		cout << dumpResult.firstPair << endl;
		cout << dumpResult.secondPair << endl;
	}
	else
	{
		cout << "No pair was found!" << endl;
	}
	cout << "The runtime in microseconds is: ";
	cout << duration_cast<microseconds>(dur).count() << endl;

	
	// exit the main function
	system("pause");
	return 0;
}