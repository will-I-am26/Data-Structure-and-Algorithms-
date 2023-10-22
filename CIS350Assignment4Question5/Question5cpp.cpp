/*
Comparing sorting algorithm
*/

#include <iostream>
#include <array>
#include <list>
#include <vector>
#include <algorithm>
#include <time.h>
#include <stdlib.h>
#include "Header.h"
using namespace std;



int main()
{
	const int SIZE = 5000;
	vector<int> Svector;
	vector<int> originalSvector;
	vector<int> sortedVector;
	vector<int> reverseVector;

	list<int> Slist;
	list<int> sortedList;
	compareClass compare;

	generate_Random_Vector(Svector, SIZE);

	for (int i = 0; i < SIZE; i++)
	{
		cout << "This is the original list: " << Svector.at(i) << endl;
	}
	cout << endl;
	generate_Reverse_Vector(Svector, reverseVector, SIZE);
	
	bookheap_sort(Svector);


	for (int i = 0; i < SIZE; i++)
	{
		cout << "THis is Svector after heap sort " << Svector.at(i) << endl;

		cout << "This is the reverse generate one: " << reverseVector.at(i) << endl;
	}
		

	//generate_Random_List(Slist, SIZE);
	//generate_SortedList(Slist, sortedList, SIZE);
	//bookMergeSort<int, compareClass>(Slist, compare);
	//cout << Slist.front() << endl;
	//cout << sortedList.front() << endl;
	

	//generate_Reverse_Vector(Svector, reverseVector, SIZE);


	/*
	originalSvector = Svector;
	cout << "Before the bookquickSort, Svector is: " << originalSvector.at(0) << endl;
	bookQuickSort(Svector);
	cout << "after book quickSort: " << Svector.at(0) << endl;
	cout << "The already sorted one: " << sortedVector.at(0) << endl;
	*/
	


	system("pause");
	return 0;
}

