#include "pch.h"
#include "CppUnitTest.h"
#include "../CIS350Assignment4Question5/Header.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			//For heap sort

			// ARRANGE
			const int SIZE = 5000;
			vector<int> Svector;
			vector<int> expectedVector;
			generate_Random_Vector(Svector, SIZE);

			//ACT
			generate_Reverse_Vector(Svector, expectedVector, SIZE);
			bookheap_sort(Svector);


			//ASSERT
			Assert::IsTrue(Svector == expectedVector);

		}

		TEST_METHOD(TestMethod2)
		{
			// For merge sort

			// ARRANGE
			const int SIZE = 5000;
			list<int> Slist;
			list<int> sortedList;
			compareClass compare;
			generate_Random_List(Slist, SIZE);

			//ACT
			generate_SortedList(Slist, sortedList, SIZE);
			bookMergeSort<int, compareClass>(Slist, compare);


			//ASSERT
			Assert::IsTrue(Slist == sortedList);

		}

		TEST_METHOD(TestMethod3)
		{
			// For quick sort

			// ARRANGE
			const int SIZE = 5000;
			vector<int> Svector;
			vector<int> expectedVector;
			generate_Random_Vector(Svector, SIZE);

			//ACT
			generate_SortedVector(Svector, expectedVector, SIZE);
			bookQuickSort(Svector);


			//ASSERT
			Assert::IsTrue(Svector == expectedVector);

		}
	};
}
