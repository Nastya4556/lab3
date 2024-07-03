#include <cassert>

#include "TestImmutableListSequence.h"
#include "ImmutableListSequence.h"


void TestImmutableListSequence::allTests()
{
	testConstructors();
	testGetFirst();
	testGetLast();
	testGet();
	testGetSubsequence();
	testGetSize();
	testAppend();
	testPrepend();
	testInsertAt();
}

void TestImmutableListSequence::testConstructors()
{
	int a[6] = { 1, 2, 3, 4, 5, 6 };
	int length = 6;
	ImmutableListSequence<int> testList1(a, length);
	assert(testList1.GetLength() == length);
	for (int i = 0; i < length; i++)
	{
		assert(testList1.Get(i) == a[i]);
	}

	ImmutableListSequence<int> testList2;
	assert(testList2.GetLength() == 0);

	ImmutableListSequence<int> testList3(testList1);
	assert(testList3.GetLength() == length);
	for (int i = 0; i < length; i++)
	{
		assert(testList1.Get(i) == testList3.Get(i));
	}
}

void TestImmutableListSequence::testGetFirst()
{
	int a[6] = { 1, 2, 3, 4, 5, 6 };
	int length = 6;
	ImmutableListSequence<int> testList(a, length);
	assert(testList.GetFirst() == a[0]);
}

void TestImmutableListSequence::testGetLast()
{
	int a[6] = { 1, 2, 3, 4, 5, 6 };
	int length = 6;
	ImmutableListSequence<int> testList(a, length);
	assert(testList.GetLast() == a[length - 1]);
}

void TestImmutableListSequence::testGet()
{
	int a[6] = { 1, 2, 3, 4, 5, 6 };
	int length = 6;
	ImmutableListSequence<int> testList(a, length);
	for (int i = 0; i < length; i++)
	{
		assert(testList.Get(i) == a[i]);
	}
}

void TestImmutableListSequence::testGetSubsequence()
{
	int a[6] = { 1, 2, 3, 4, 5, 6 };
	int length = 6;
	int startIndex = 2;
	int endIndex = 5;
	ImmutableListSequence<int> testList(a, length);
	ImmutableListSequence<int>* result = testList.GetSubsequence(startIndex, endIndex);
	assert(result->GetLength() == endIndex - startIndex + 1);
	for (int i = 0; i < endIndex - startIndex + 1; i++)
	{
		assert(result->Get(i) == testList.Get(startIndex + i));
	}
}

void TestImmutableListSequence::testGetSize()
{
	int a[6] = { 1, 2, 3, 4, 5, 6 };
	int length = 6;
	ImmutableListSequence<int> testList(a, length);
	assert(testList.GetLength() == length);
}

void TestImmutableListSequence::testAppend()
{
	int a[6] = { 1, 2, 3, 4, 5, 6 };
	int length = 6;
	int value = 50;
	ImmutableListSequence<int> testList(a, length);
	ImmutableListSequence<int>* result = testList.Append(value);
	assert(result->GetLength() == length + 1);
	assert(result->Get(result->GetLength() - 1) == a[length - 1]);
}

void TestImmutableListSequence::testPrepend()
{
	int a[6] = { 1, 2, 3, 4, 5, 6 };
	int length = 6;
	int value = 50;
	ImmutableListSequence<int> testList(a, length);
	ImmutableListSequence<int>* result = testList.Prepend(value);
	assert(result->GetLength() == length + 1);
	assert(result->Get(0) == a[0]);
}

void TestImmutableListSequence::testInsertAt()
{
	int a[6] = { 1, 2, 3, 4, 5, 6 };
	int length = 6;
	int value = 50;
	int index = 2;
	ImmutableListSequence<int> testList(a, length);
	ImmutableListSequence<int>* result = testList->InsertAt(value, index);
	assert(result->GetLength() == length + 1);
	assert(result->Get(index + 1) == value);
}