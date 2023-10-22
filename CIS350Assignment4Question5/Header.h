#pragma once

#include <iostream>
#include <array>
#include <list>
#include <vector>
#include <algorithm>
#include <time.h>
#include <stdlib.h>
using namespace std;

void generate_Random_Vector(vector<int>& Svector, int SIZE)
{
	srand(time(NULL));
	int randomValue;

	for (int i = 0; i < SIZE; i++)
	{
		randomValue = rand() % 100000 + 1;
		Svector.push_back(randomValue);
	}

}

void generate_Random_List(list<int>& Slist, int SIZE)
{
	srand(time(NULL));
	int randomValue;

	for (int i = 0; i < SIZE; i++)
	{
		randomValue = rand() % 100000 + 1;
		Slist.push_back(randomValue);
	}

}


void generate_SortedList(list<int>& Slist, list<int>& sortedList, int SIZE)
{

	sortedList = Slist;

	sortedList.sort();

}

void generate_SortedVector(vector<int>& Svector, vector<int>& sortedVector, int SIZE)
{

	sortedVector = Svector;

	sort(sortedVector.begin(), sortedVector.end());

}

void generate_Reverse_Vector(vector<int>& Svector, vector<int>& reverseVector, int SIZE)
{
	reverseVector = Svector;
	sort(reverseVector.begin(), reverseVector.end(), greater<int>());

}

vector<int> bookQuickSort(vector<int>& Svector)
{
	if (Svector.size() <= 1)
	{
		return Svector;
	}
	else {
		vector<int> L;
		vector<int> E;
		vector<int> G;
		int p = Svector.back();

		while (!Svector.empty())
		{
			if (Svector.back() < p)
			{
				L.push_back(Svector.back());
				Svector.pop_back();
			}
			else if (Svector.back() == p)
			{
				E.push_back(Svector.back());
				Svector.pop_back();
			}
			else
			{
				G.push_back(Svector.back());
				Svector.pop_back();
			}
		}

		bookQuickSort(L);
		bookQuickSort(G);


		while (!L.empty())
		{
			Svector.push_back(L.at(0));
			L.erase(L.begin());
		}
		while (!E.empty())
		{
			Svector.push_back(E.at(0));
			E.erase(E.begin());
		}
		while (!G.empty())
		{
			Svector.push_back(G.at(0));
			G.erase(G.begin());
		}
		return Svector;
	}
}

class compareClass
{
public:
	bool operator()(const int S1, const int S2) const
	{
		return (S1 < S2);
	}
};

template <typename E, typename C>
void bookMerge(list<E>& S1, list<E>& S2, list<E>& S, const C& less)
{
	typedef typename list<E>::iterator Itor;
	Itor p1 = S1.begin();
	Itor p2 = S2.begin();
	while (p1 != S1.end() && p2 != S2.end())
	{
		if (less(*p1, *p2))
		{
			S.push_back(*p1++);
		}
		else
		{
			S.push_back(*p2++);
		}
	}

	while (p1 != S1.end())
	{
		S.push_back(*p1++);
	}

	while (p2 != S2.end())
	{
		S.push_back(*p2++);
	}
}

template <typename E, typename C>
void bookMergeSort(list<E>& S, const C& less)
{
	typedef typename list<E>::iterator Itor;
	int n = S.size();
	if (n <= 1)
	{
		return;
	}
	list <E> S1, S2;
	Itor p = S.begin();
	for (int i = 0; i < (n / 2); i++)
	{
		S1.push_back(*p++);
	}
	for (int i = (n / 2); i < n; i++)
	{
		S2.push_back(*p++);
	}
	S.clear();
	bookMergeSort(S1, less);
	bookMergeSort(S2, less);
	bookMerge(S1, S2, S, less);
}



void heapifydown(vector<int>& arr, int i, int heap_size) {
	
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < heap_size && arr[left] > arr[largest])
		largest = left;
	if (right < heap_size && arr[right] > arr[largest])
		largest = right;

	if (largest != i) {
		swap(arr[i], arr[largest]);
		heapifydown(arr, largest, heap_size);
	}
}

void bookHeapify(vector<int>& arr, int i)
{
	int parent = (i - 1) / 2;

	if (arr[i] > arr[parent])
	{
		swap(arr[i], arr[parent]);
		bookHeapify(arr, parent);
	}
}

void ourBuildingHeap(vector<int>& arr)
{
	int n = arr.size();

	for (int i = 1; i < n; i++)
	{
		bookHeapify(arr, i);
	}
}


void bookheap_sort(vector<int>& arr) {
	// Build a heap from the input array
	ourBuildingHeap(arr);

	// Repeat until the heap contains only one element
	for (int i = arr.size() - 1; i > 0; i--) {
		// Swap the root element with the last element
		swap(arr[0], arr[i]);


		// Remove the last element (which is now in the correct position)
		int heap_size = i;
		heapifydown(arr, 0, i);
	}
	// Reverse the sorted array and return it
	reverse(arr.begin(), arr.end());
}
