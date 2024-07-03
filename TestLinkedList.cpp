#include <cassert>
#include <stdexcept>

#include "LinkedList.h"
#include "TestLinkedList.h"

void TestLinkedList::allTests()
{
	testConstructors();
	testGetFirst();
	testGetLast();
	testGet();
	testGetSubList();
	testGetLength();
	testAppend();
	testPrepend();
	testInsertAt();
	testConcat();
}

void TestLinkedList::testConstructors()
{
	int a[6] = { 1, 2, 3, 4, 5, 6 };
	int length = 6;
	LinkedList<int> testList1(a, length);
	assert(testList1.GetLength() == length);
	for (int i = 0; i < length; i++)
	{
		assert(testList1.Get(i) == a[i]);
	}
	
	LinkedList<int> testList2;
	assert(testList2.GetLength() == 0);

	LinkedList<int> testList3(testList1);
	assert(testList3.GetLength() == length);
	for (int i = 0; i < length; i++)
	{
		assert(testList1.Get(i) == testList3.Get(i));
	}
}

void TestLinkedList::testGetFirst()
{
	int a[6] = { 1, 2, 3, 4, 5, 6 };
	int length = 6;
	LinkedList<int> testList(a, length);
	assert(testList.GetFirst() == a[0]);
}

void TestLinkedList::testGetLast()
{
	int a[6] = { 1, 2, 3, 4, 5, 6 };
	int length = 6;
	LinkedList<int> testList(a, length);
	assert(testList.GetLast() == a[length - 1]);
}

void TestLinkedList::testGet()
{
	int a[6] = { 1, 2, 3, 4, 5, 6 };
	int length = 6;
	LinkedList<int> testList(a, length);
	for (int i = 0; i < testList.GetLength(); i++)
	{
		assert(testList.Get(i) == a[i]);
	}
}

void TestLinkedList::testGetSubList()
{
	int a[6] = {1, 2, 3, 4, 5, 6};
	int length = 6;
	int startIndex = 2; 
	int endIndex = 4;
	LinkedList<int> testList(a, length);
	try
	{
		LinkedList<int>* result = testList.GetSubList(startIndex, endIndex);
		assert(result->GetLength() == endIndex - startIndex + 1);
		for (int i = startIndex; i <= endIndex; i++)
		{
			assert(result->Get(i - startIndex) == testList.Get(i));
		}
	}
	catch (std::out_of_range& e)
	{
		std::cout << "Mistake in test: Get Subsequence in test of Linked List: " << e.what() << "\n";
		assert(false);
	}
}

void TestLinkedList::testGetLength()
{
	int a[6] = { 1, 2, 3, 4, 5, 6 };
	int length = 6;
	LinkedList<int> testList(a, length);
	assert(testList.GetLength() == length);
}

void TestLinkedList::testAppend()
{
	int a[6] = { 1, 2, 3, 4, 5, 6 };
	int length = 6;
	int value = 50;
	LinkedList<int> testList(a, length);
	testList.Append(value);
	assert(testList.GetLength() == length + 1);
	assert(testList.Get(testList.GetLength() - 1) == value);
}

void TestLinkedList::testPrepend()
{
	int a[6] = { 1, 2, 3, 4, 5, 6 };
	int length = 6;
	int value = 50;
	LinkedList<int> testList(a, length);
	testList.Prepend(value);
	assert(testList.GetLength() == length + 1);
	assert(testList.Get(0) == value);
}

void TestLinkedList::testInsertAt()
{
	int a[6] = { 1, 2, 3, 4, 5, 6 };
	int length = 6;
	int index = 2;
	int value = 50;
	LinkedList<int> testList(a, length);
	try
	{
		testList.InsertAt(index, value);
		assert(testList.GetLength() == length + 1);
		assert(testList.Get(index) == value);
	}
	catch (std::out_of_range& e)
	{
		std::cout << "Mistake in test: Insert At in test of Linked List: " << e.what() << "\n";
		assert(false);
	}
}

void TestLinkedList::testConcat()
{
	int a[6] = { 1, 2, 3, 4, 5, 6 };
	int length1 = 6;
	LinkedList<int> testList1(a, length1);
	int b[3] = { 7, 8, 9 };
	int length2 = 3;
	LinkedList<int> testList2(b, length2);
	LinkedList<int>* result = testList1.Concat(&testList2);
	assert(result->GetLength() == length1 + length2);
	for (int i = 0; i < length1; i++)
	{
		assert(result->Get(i) == a[i]);
	}
	for (int i = length1; i < length1 + length2; i++)
	{
		assert(result->Get(i) == b[i - length1]);
	}
	delete result;
}