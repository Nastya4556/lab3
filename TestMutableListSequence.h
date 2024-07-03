#pragma once

#include <cassert>

#include "Sequence.h"
#include "MutableListSequence.h"
#include "LinkedList.h"

template<template<class>class MutableSequence>class TestMutableListSequence
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
		MutableListSequence<int> testList1(a, length);
		assert(testList1.GetLength() == length);
		for (int i = 0; i < length; i++)
		{
			assert(testList1.Get(i) == a[i]);
		}

		MutableListSequence<int> testList2;
		assert(testList2.GetLength() == 0);

		MutableListSequence<int> testList3(testList1);
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
		MutableListSequence<int> testList(a, length);
		assert(testList.GetFirst() == a[0]);
	}

	void testGetLast()
	{
		int a[6] = { 1, 2, 3, 4, 5, 6 };
		int length = 6;
		MutableListSequence<int> testList(a, length);
		assert(testList.GetLast() == a[length - 1]);
	}

	void testGet()
	{
		int a[6] = { 1, 2, 3, 4, 5, 6 };
		int length = 6;
		MutableListSequence<int> testList(a, length);
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
		MutableListSequence<int> testList(a, length);
		MutableListSequence<int>* result = testList.GetSubsequence(startIndex, endIndex);
		assert(result->GetLength() == endIndex - startIndex + 1);
		for (int i = 0; i < endIndex - startIndex + 1; i++)
		{
			assert(result->Get(i) == testList.Get(startIndex + i));
		}
	}

	void testGetSize()
	{
		int a[6] = { 1, 2, 3, 4, 5, 6 };
		int length = 6;
		MutableListSequence<int> testList(a, length);
		assert(testList.GetLength() == length);
	}

	void testAppend()
	{
		int a[6] = { 1, 2, 3, 4, 5, 6 };
		int length = 6;
		int value = 50;
		MutableListSequence<int> testList(a, length);
		testList.Append(value);
		assert(testList.GetLength() == length + 1);
		assert(testList.Get(testList.GetLength() - 1) == value);
	}

	void testPrepend()
	{
		int a[6] = { 1, 2, 3, 4, 5, 6 };
		int length = 6;
		int value = 50;
		MutableListSequence<int> testList(a, length);
		testList.Prepend(value);
		assert(testList.GetLength() == length + 1);
		assert(testList.Get(0) == value);
	}

	void testInsertAt()
	{
		int a[6] = { 1, 2, 3, 4, 5, 6 };
		int length = 6;
		int value = 50;
		int index = 2;
		MutableListSequence<int> testList(a, length);
		testList.InsertAt(index, value);
		assert(testList.GetLength() == length + 1);
		assert(testList.Get(index) == value);
	}
	void testConcat()
	{
		int a[6] = { 1, 2, 3, 4, 5, 6 };
		int length1 = 6;
		MutableListSequence<int> testList1(a, length1);
		int b[3] = { 7, 8, 9 };
		int length2 = 3;
		MutableListSequence<int> testList2(b, length2);
		MutableListSequence<int>* result = testList1.Concat(testList2);
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
