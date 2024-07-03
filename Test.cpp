#include "Test.h"
#include "TestDynamicArray.h"
#include "TestLinkedList.h"
#include "TestImmutableArraySequence.h"
#include "TestImmutableListSequence.h"
#include "TestMutableArraySequence.h"
#include "TestMutableListSequence.h"
#include "TestVector.h"
#include "TestQueue.h"

void Test::allTests()
{
	testQueue();
	testVector();
	testDynamicArray();
	testLinkedList();
	testImmutableArraySequence();
	testImmutableListSequence();
	testMutableArraySequence();
	testMutableListSequence();
}

void Test::testQueue()
{
	TestQueue testQueue;
	testQueue.allTests();
}
void Test::testVector()
{
	TestVector testVector;
	testVector.allTests();
}


void Test::testDynamicArray()
{
	TestDynamicArray testDynamicArray;
	testDynamicArray.allTests();
}

void Test::testLinkedList()
{
	TestLinkedList testLinkedList;
	testLinkedList.allTests();
}

void Test::testImmutableArraySequence()
{
	TestImmutableArraySequence<ImmutableArraySequence> testImmutableArraySequence;
	testImmutableArraySequence.allTests();
}

void Test::testImmutableListSequence()
{
	TestImmutableListSequence<ImmutableListSequence> testImmutableListSequence;
	testImmutableListSequence.allTests();
}

void Test::testMutableArraySequence()
{
	TestMutableArraySequence<MutableArraySequence> testMutableArraySequence;
	testMutableArraySequence.allTests();
}

void Test::testMutableListSequence()
{
	TestMutableListSequence<MutableListSequence> testMutableListSequence;
	testMutableListSequence.allTests();
}