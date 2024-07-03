#pragma once

#include <cassert>

#include "ImmutableListSequence.h"
#include "LinkedList.h"
#include "Sequence.h"

template<template<class>class ImmutableSequence> class TestImmutableListSequence
{
public:
	void allTests()
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
		testConcat();
	}

	void testConstructors()
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

	void testGetFirst()
	{
		int a[6] = { 1, 2, 3, 4, 5, 6 };
		int length = 6;
		ImmutableListSequence<int> testList(a, length);
		assert(testList.GetFirst() == a[0]);
	}

	void testGetLast()
	{
		int a[6] = { 1, 2, 3, 4, 5, 6 };
		int length = 6;
		ImmutableListSequence<int> testList(a, length);
		assert(testList.GetLast() == a[length - 1]);
	}

	void testGet()
	{
		int a[6] = { 1, 2, 3, 4, 5, 6 };
		int length = 6;
		ImmutableListSequence<int> testList(a, length);
		for (int i = 0; i < length; i++)
		{
			assert(testList.Get(i) == a[i]);
		}
	}

	void testGetSubsequence()
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
		delete result;
	}

	void testGetSize()
	{
		int a[6] = { 1, 2, 3, 4, 5, 6 };
		int length = 6;
		ImmutableListSequence<int> testList(a, length);
		assert(testList.GetLength() == length);
	}

	void testAppend()
	{
		int a[6] = { 1, 2, 3, 4, 5, 6 };
		int length = 6;
		int value = 50;
		ImmutableListSequence<int> testList(a, length);
		ImmutableListSequence<int>* result = testList.Append(value);
		assert(result->GetLength() == length + 1);
		assert(result->Get(length) == value);
	}

	void testPrepend()
	{
		int a[6] = { 1, 2, 3, 4, 5, 6 };
		int length = 6;
		int value = 50;
		ImmutableListSequence<int> testList(a, length);
		ImmutableListSequence<int>* result = testList.Prepend(value);
		assert(result->GetLength() == length + 1);
		assert(result->Get(0) == value);
	}

	void testInsertAt()
	{
		int a[6] = { 1, 2, 3, 4, 5, 6 };
		int length = 6;
		int value = 50;
		int index = 2;
		ImmutableListSequence<int> testList(a, length);
		ImmutableListSequence<int>* result = testList.InsertAt(index, value);
		assert(result->GetLength() == length + 1);
		assert(result->Get(index) == value);
	}
	void testConcat()
	{
		int a[6] = { 1, 2, 3, 4, 5, 6 };
		int length1 = 6;
		ImmutableListSequence<int> testList1(a, length1);
		int b[3] = { 7, 8, 9 };
		int length2 = 3;
		ImmutableListSequence<int> testList2(b, length2);
		ImmutableListSequence<int>* result = testList1.Concat(testList2);
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
};