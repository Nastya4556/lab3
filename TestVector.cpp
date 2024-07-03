#include <cassert>
#include <stdexcept>
#include <cmath>
#include "TestVector.h"
#include "Vector.h"

void TestVector::allTests()
{
	testConstructors();
	testGet();
	testGetSize();
	testResize();
	testAppend();
	testSumOfVectors();
	testMultByScalar();
	testGetNormOfVector();
	testScalarProduct();
}

void TestVector::testConstructors()
{
	Vector<int> testVector1;
	assert(testVector1.GetSize() == 0);

	int length = 6;
	int value = 3;
	Vector<int> testVector2(length, value);
	assert(testVector2.GetSize() == length);
	for (int i = 0; i < length; i++)
	{
		assert(testVector2.Get(i) == value);
	}

	int a[6] = { 1, 2, 3, 4, 5, 6 };
	Vector<int> testVector3(a, length);
	assert(testVector3.GetSize() == length);
	for (int i = 0; i < length; i++)
	{
		assert(testVector3.Get(i) == a[i]);
	}

	Vector<int> testVector4(testVector3);
	assert(testVector3.GetSize() == testVector4.GetSize());
	for (int i = 0; i < testVector4.GetSize(); i++)
	{
		assert(testVector4.Get(i) == testVector3.Get(i));
	}
}
void TestVector::testGet()
{
	int a[6] = { 1, 2, 3, 4, 5, 6 };
	int length = 6;
	Vector<int> testVector(a, length);
	for (int i = 0; i < testVector.GetSize(); i++)
	{
		assert(testVector.Get(i) == a[i]);
	}
}

void TestVector::testGetSize()
{
	int a[6] = { 1, 2, 3, 4, 5, 6 };
	int length = 6;
	Vector<int> testVector(a, length);
	assert(testVector.GetSize() == length);
}

void TestVector::testResize()
{
	int a[6] = { 1, 2, 3, 4, 5, 6 };
	int length = 6;
	int newSize1 = 3;
	Vector<int> testVector1(a, length);
	testVector1.Resize(newSize1);
	assert(testVector1.GetSize() == newSize1);

	int newSize2 = 10;
	Vector<int> testVector2(a, length);
	testVector2.Resize(newSize2);
	assert(testVector2.GetSize() == newSize2);
}

void TestVector::testAppend()
{
	int a[6] = { 1, 2, 3, 4, 5, 6 };
	int length = 6;
	int value = 50;
	Vector<int> testVector(a, length);
	testVector.Append(value);
	assert(testVector.GetSize() == length + 1);
	assert(testVector.Get(length) == value);
}

void TestVector::testSumOfVectors()
{
	int a[6] = { 1, 2, 3, 4, 5, 6 };
	int length = 6;
	Vector<int> testVector1(a, length);
	int b[6] = { 6, 5, 4, 3, 2, 1 };
	Vector<int> testVector2(b, length);
	testVector1.SumOfVectors(testVector2);
	for (int i = 0; i < testVector1.GetSize(); i++)
	{
		assert(testVector1.Get(i) == a[i] + b[i]);
	}
}

void TestVector::testMultByScalar()
{
	int a[6] = { 1, 2, 3, 4, 5, 6 };
	int length = 6;
	int value = 5;
	Vector<int> testVector(a, length);
	testVector.MultByScalar(value);
	for (int i = 0; i < testVector.GetSize(); i++)
	{
		assert(testVector.Get(i) == a[i] * value);
	}
}

void TestVector::testGetNormOfVector()
{
	int a[6] = { 1, 2, 3, 4, 5, 6 };
	int length = 6;
	Vector<int> testVector(a, length);
	double result = testVector.GetNormOfVector();
	double summa = 0;
	for (int i = 0; i < length; i++)
	{
		double buf = testVector.Get(i) * testVector.Get(i);
		summa += buf;
	}
	summa = sqrt(summa);
	if (summa >= result)
	{
		assert(summa - result < 0.00000000001);
	}
	else
	{
		assert(result - summa < 0.00000000001);
	}
}

void TestVector::testScalarProduct()
{
	int a[6] = { 1, 2, 3, 4, 5, 6 };
	int length = 6;
	Vector<int> testVector1(a, length);
	
	int b[6] = { 6, 5, 4, 3, 2, 1 };
	Vector<int> testVector2(b, length);

	int result = testVector1.ScalarProduct(testVector2);

	int result1 = 0;
	for (int i = 0; i < testVector1.GetSize(); i++)
	{
		int buf = testVector1.Get(i) * testVector2.Get(i);
		result1 += buf;
	}
	assert(result == result1);
}
