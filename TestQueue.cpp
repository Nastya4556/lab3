#include <stdexcept>
#include <cassert>

#include "Queue.h"
#include "TestQueue.h"
#include "Sequence.h"
#include <iostream>

void TestQueue::allTests()
{
	testConstructors();
	testGetLength();
	testGet();
	testAppend();
	testPop();
	testMap();
	testWhere();
	testConcat();
	testGetSubsequence();
	testSearchSubsequence();
	testReduceFunc();
}
void TestQueue::testConstructors()
{
	Queue<int> testQueue1;
	assert(testQueue1.GetLength() == 0);

	int a[6] = { 1, 2, 3, 4, 5, 6 };
	int size = 6;
	Queue<int> testQueue2(a, size);
	assert(testQueue2.GetLength() == size);
	for (int i = 0; i < size; i++)
	{
		assert(testQueue2.Get(i) == a[i]);
	}

	Queue<int> testQueue3(testQueue2);
	assert(testQueue3.GetLength() == testQueue2.GetLength());
	for (int i = 0; i < testQueue3.GetLength(); i++)
	{
		assert(testQueue3.Get(i) == testQueue2.Get(i));
	}
}
void TestQueue::testGetLength()
{
	int a[6] = { 1, 2, 3, 4, 5, 6 };
	int size = 6;
	Queue<int> testQueue(a, size);
	assert(testQueue.GetLength() == size);
}
void TestQueue::testGet()
{
	int a[6] = { 1, 2, 3, 4, 5, 6 };
	int size = 6;
	Queue<int> testQueue(a, size);
	for (int i = 0; i < testQueue.GetLength(); i++)
	{
		assert(testQueue.Get(i) == a[i]);
	}
}
void TestQueue::testAppend()
{
	int a[6] = { 1, 2, 3, 4, 5, 6 };
	int size = 6;
	int value = 50;
	Queue<int> testQueue(a, size);
	testQueue.Append(value);
	assert(testQueue.GetLength() == size + 1);
	assert(testQueue.Get(size) == value);
}
void TestQueue::testPop()
{
	int a[6] = { 1, 2, 3, 4, 5, 6 };
	int size = 6;
	Queue<int> testQueue(a, size);
	testQueue.Pop();
	assert(testQueue.GetLength() == size - 1);
	for (int i = 0; i < testQueue.GetLength(); i++)
	{
		assert(testQueue.Get(i) == a[i + 1]);
	}
}
void TestQueue::testMap()
{
	int a[6] = { 1, 2, 3, 4, 5, 6 };
	int size = 6;
	Queue<int> testQueue(a, size);
	testQueue.Map([](int x) { return x + 1; });
	for (int i = 0; i < testQueue.GetLength(); i++)
	{
		assert(testQueue.Get(i) == a[i] + 1);
	}
}
void TestQueue::testWhere()
{
	int a[6] = { 1, 2, 3, 4, 5, 6 };
	int size = 6;
	Queue<int> testQueue(a, size);
	testQueue.Where([](int x) {return x % 2 == 0; });
	assert(testQueue.GetLength() == 3);
	assert(testQueue.Get(0) == a[1]);
	assert(testQueue.Get(1) == a[3]);
	assert(testQueue.Get(2) == a[5]);
}
void TestQueue::testConcat()
{
	int a[6] = { 1, 2, 3, 4, 5, 6 };
	int size1 = 6;
	Queue<int> testQueue1(a, size1);

	int b[4] = { 7, 8, 9, 10 };
	int size2 = 4;
	MutableListSequence<int> testQueue2(b, size2);
	testQueue1.Concat(testQueue2);
	assert(testQueue1.GetLength() == size1 + size2);
	for (int i = 0; i < size1; i++)
	{
		assert(testQueue1.Get(i) == a[i]);
	}
	for (int i = size1; i < size1 + size2; i++)
	{
		assert(testQueue1.Get(i) == b[i - size1]);
	}
}
void TestQueue::testGetSubsequence()
{
	int a[6] = { 1, 2, 3, 4, 5, 6 };
	int size = 6;
	int startIndex = 1; 
	int endIndex = 4;
	Queue<int> testQueue(a, size);
	MutableListSequence<int>* result = testQueue.GetSubsequence(startIndex, endIndex);
	assert(result->GetLength() == endIndex - startIndex + 1);
	for (int i = 0; i < endIndex - startIndex + 1; i++)
	{
		assert(result->Get(i) == testQueue.Get(i + startIndex));
	}
}
void TestQueue::testSearchSubsequence()
{
	int a[6] = { 1, 2, 3, 4, 5, 6 };
	int size1 = 6;
	Queue<int> testQueue1(a, size1);

	int b[3] = { 1, 2, 3 };
	int size2 = 3;
	MutableListSequence<int> testQueue2(b, size2);

	int c[3] = { 2, 5, 9 };
	int size3 = 3;
	MutableListSequence<int> testQueue3(c, size3);

	bool result1 = testQueue1.SearchSubsequence(testQueue2);
	assert(result1 == true);

	bool result2 = testQueue1.SearchSubsequence(testQueue3);
	assert(result2 == false);
}
void TestQueue::testReduceFunc()
{
	int a[6] = { 1, 2, 3, 4, 5, 6 };
	int size = 6;
	Queue<int> testQueue(a, size);
	int result = testQueue.Reduce([](int b, int result) {return b + result; });
	int summa = 0;
	for (int i = 0; i < testQueue.GetLength(); i++)
	{
		summa += testQueue.Get(i);
	}
	assert(result == summa);
}