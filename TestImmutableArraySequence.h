#pragma once

#include <cassert>

#include "DynamicArray.h"
#include "Sequence.h"
#include "ImmutableArraySequence.h"

template<template<class>class ImmutableSequence>
class TestImmutableArraySequence
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
		ImmutableArraySequence<int> testArray1(a, length);
		assert(testArray1.GetLength() == length);
		for (int i = 0; i < 6; i++)
		{
			assert(testArray1.Get(i) == a[i]);
		}
		
		ImmutableArraySequence<int> testArray2;
		assert(testArray2.GetLength() == 0);
		
		ImmutableArraySequence<int> testArray3(testArray1);
		assert(testArray3.GetLength() == length);
		for (int i = 0; i < testArray3.GetLength(); i++)
		{
		assert(testArray3.Get(i) == testArray1.Get(i));
		}
	}

	void testGetFirst()
	{
		int a[6] = { 1, 2, 3, 4, 5, 6 };
		int length = 6;
		ImmutableArraySequence<int> testArray(a, length);
		assert(testArray.GetFirst() == a[0]);
	}

	void testGetLast()
	{
		int a[6] = { 1, 2, 3, 4, 5, 6 };
		int length = 6;
		ImmutableArraySequence<int> testArray(a, length);
		assert(testArray.GetLast() == a[length - 1]);
	}

	void testGet()
	{
		int a[6] = { 1, 2, 3, 4, 5, 6 };
		int length = 6;
		ImmutableArraySequence<int> testArray(a, length);
		for (int i = 0; i < length; i++)
		{
			assert(testArray.Get(i) == a[i]);
		}
	}

	void testGetSubsequence()
	{
		int a[6] = { 1, 2, 3, 4, 5, 6 };
		int length = 6;
		int startIndex = 2;
		int endIndex = 5;
		ImmutableArraySequence<int> testArray(a, length);
		ImmutableArraySequence<int>* result = testArray.GetSubsequence(startIndex, endIndex);
		assert(result->GetLength() == endIndex - startIndex + 1);
		for (int i = 0; i < endIndex - startIndex + 1; i++)
		{
			assert(result->Get(i) == testArray.Get(startIndex + i));
		}
	}

	void testGetSize()
	{
		int a[6] = { 1, 2, 3, 4, 5, 6 };
		int length = 6;
		ImmutableArraySequence<int> testArray(a, length);
		assert(testArray.GetLength() == 6);
	}

	void testAppend()
	{
		int a[6] = { 1, 2, 3, 4, 5, 6 };
		int length = 6;
		int value = 50;
		ImmutableArraySequence<int> testArray(a, length);
		ImmutableArraySequence<int>* result = testArray.Append(value);
		assert(result->GetLength() == length + 1);
		assert(result->Get(result->GetLength() - 1) == value);
	}

	void testPrepend()
	{
		int a[6] = { 1, 2, 3, 4, 5, 6 };
		int length = 6;
		int value = 50;
		ImmutableArraySequence<int> testArray(a, length);
		ImmutableArraySequence<int>* result = testArray.Prepend(value);
		assert(result->GetLength() == length + 1);
		assert(result->Get(0) == value);
	}

	void testInsertAt()
	{
		int a[6] = { 1, 2, 3, 4, 5, 6 };
		int length = 6;
		int value = 50;
		int index = 2;
		ImmutableArraySequence<int> testArray(a, length);
		ImmutableArraySequence<int>* result = testArray.InsertAt(index, value);
		assert(result->GetLength() == length + 1);
		assert(result->Get(index) == value);
	}
	void testConcat()
	{
		int a[6] = { 1, 2, 3, 4, 5, 6 };
		int length1 = 6;
		ImmutableArraySequence<int> testList1(a, length1);
		int b[3] = { 7, 8, 9 };
		int length2 = 3;
		ImmutableArraySequence<int> testList2(b, length2);
		ImmutableArraySequence<int>* result = testList1.Concat(testList2);
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
