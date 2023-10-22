/*
Suppose you are given an n-element array A containing distinct integers
that are listed in increasing order. Given a number k, describe a non-recursive
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

struct sumPair
{
	int firstPair = -1;
	int secondPair = -1;
};

// this is the nonrecursiveFindPair algorithm
// it starts at the begining of the array and add each number in the array afterward
// then compare if that is equal to the target.
// if it does not find the pair, the begining of the array is moved one spot to the right
sumPair nonRecursiveFindPair(int arr[], int n, int k)
{
	sumPair result;
	for (int i = 0; i < n; i++)
	{
		for (int j = (n - 1); j > i; j--)
		{
			if (arr[i] + arr[j] == k)
			{
				result.firstPair = i;
				result.secondPair = j;
				return result;
			}
		}

	}
};

int main()
{
	// needed variables to create the array, keep track of pair, and runtime
	srand(time(NULL));
	const int n = 10000;
	int arr[n];
	int k = 555;
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

	// sort the array ascending 
	sort(arr, arr + n);
	
	auto start1 =  steady_clock::now();
	sumPair dumpResult = nonRecursiveFindPair(arr, n, k);
	
	auto dur = steady_clock::now() - start1;

	//auto duration = duration_cast<microseconds>(end1 - start1);

	// a if else statement to print the pair if it was found or not
	if (dumpResult.firstPair != -1 && dumpResult.secondPair != -1)
	{
		cout << arr[dumpResult.firstPair] << endl;
		cout << arr[dumpResult.secondPair] << endl;
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