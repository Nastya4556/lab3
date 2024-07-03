#include <cassert>
#include <stdexcept>

#include "DynamicArray.h"
#include "TestDynamicArray.h"

void TestDynamicArray::allTests()
{
	testConstructors();
	testGet();
	testGetSize();
	testSet();
	testResize();
	testAppend();
}

void TestDynamicArray::testConstructors()
{
	DynamicArray<int> testArray1;
	assert(testArray1.GetSize() == 0);

	int a[6] = { 1, 2, 3, 4, 5, 6 };
	int length = 6;
	DynamicArray<int> testArray2(a, length);
	assert(testArray2.GetSize() == length);
	for (int i = 0; i < 6; i++)
	{
		assert(testArray2.Get(i) == a[i]);
	}

	DynamicArray<int> testArray3(length);
	assert(testArray3.GetSize() == length);

	DynamicArray<int> testArray4(testArray2);
	assert(testArray4.GetSize() == length);
	for (int i = 0; i < testArray4.GetSize(); i++)
	{
		assert(testArray2.Get(i) == testArray4.Get(i));
	}
}

void TestDynamicArray::testGet()
{
	int a[6] = { 1, 2, 3, 4, 5, 6 };
	int length = 6;
	DynamicArray<int> testArray(a, length);
	for (int i = 0; i < length; i++)
	{
		assert(testArray.Get(i) == a[i]);
	}
}

void TestDynamicArray::testGetSize()
{
	int a[6] = { 1, 2, 3, 4, 5, 6 };
	int length = 6;
	DynamicArray<int> testArray(a, length);
	assert(testArray.GetSize() == length);
}

void TestDynamicArray::testSet()
{
	int a[6] = { 1, 2, 3, 4, 5, 6 };
	int length = 6;
	int index = 2;
	int value = 50;
	DynamicArray<int> testArray(a, length);
	try
	{
		testArray.Set(index, value);
		assert(testArray.GetSize() == length);
		assert(testArray.Get(index) == value);
	}
	catch (std::out_of_range& e)
	{
		std::cout << "Mistake in test: Set in test of Dynamic Array: " << e.what() << "\n";
		assert(false);
	}
}

void TestDynamicArray::testResize()
{
	int a[6] = { 1, 2, 3,4 ,5, 6 };
	int length = 6;
	int newSize1 = 4;
	DynamicArray<int> testArray1(a, length);
	try
	{
		testArray1.Resize(newSize1);
		assert(testArray1.GetSize() == newSize1);
	}
	catch (std::out_of_range& e)
	{
		std::cout << "Mistake in test: Resize in test of Dynamic Array: " << e.what() << "\n";
		assert(false);
	}

	int newSize2 = 10;
	DynamicArray<int> testArray2(a, length);
	try
	{
		testArray2.Resize(newSize2);
		assert(testArray2.GetSize() == newSize2);
	}
	catch (std::out_of_range& e)
	{
		std::cout << "Mistake in test: Resize in test of Dynamic Array: " << e.what() << "\n";
		assert(false);
	}
}

void TestDynamicArray::testAppend()
{
	int a[6] = { 1, 2, 3, 4, 5, 6 };
	int length = 6;
	int value = 50;
	DynamicArray<int> testArray(a, length);
	testArray.Append(value);
	assert(testArray.GetSize() == length + 1);
	assert(testArray.Get(length) == value);
}


