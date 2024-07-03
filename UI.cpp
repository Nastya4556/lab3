#include <iostream>
#include <iomanip>
#include "UI.h"
#include "Sequence.h"
#include "MutableListSequence.h"
#include "MutableArraySequence.h"
#include "ImmutableArraySequence.h"
#include "ImmutableListSequence.h"
#include "Vector.h"
#include "Queue.h"
#include "Complex.h"
#include "Person.h"

template <typename T> struct Queue_func
{
private:
	Queue<T>* queue = new Queue<T>;
public:
	void creatQueue()
	{
		int size = 0;
		T value{};
		std::cout << "Input size of queue: ";
		std::cin >> size;
		std::cout << "\nInput elements of queue: ";
		for (int i = 0; i < size; i++)
		{
			std::cin >> value;
			queue->Append(value);
		}
		std::cout << "\n";
	}
	void printQueue()
	{
		try
		{
			if (queue->GetLength() == 0)
			{
				std::cout << "Queue is empty\n";
			}
			else
			{
				for (int i = 0; i < queue->GetLength(); i++)
				{
					std::cout << queue->Get(i) << " ";
				}
				std::cout << "\n";
			}
		}
		catch (std::out_of_range& e)
		{
			std::cout << e.what();
		}
		std::cout << "\n";
	}
	void printSize()
	{
		try
		{
			std::cout << "Size: " << queue->GetLength();
		}
		catch (std::out_of_range& e)
		{
			std::cout << e.what();
		}
		std::cout << "\n";
	}
	void printGet()
	{
		int index = 0;
		std::cout << "Input index of element: ";
		std::cin >> index;
		try
		{
			std::cout << queue->Get(index);
		}
		catch (std::out_of_range& e)
		{
			std::cout << e.what();
		}
		std::cout << "\n";
	}
	void appendValue()
	{
		T value{};
		std::cout << "Input value: ";
		std::cin >> value;
		queue->Append(value);
	}
	void pop()
	{
		queue->Pop();
	}
	void concat()
	{
		int size = 0;
		T value{};
		std::cout << "Input size of sequence which you want to concat:";
		std::cin >> size;
		std::cout << "\n";
		for (int i = 0; i < size; i++)
		{
			std::cin >> value;
			queue->Append(value);
		}
	}
	void getSubsequence()
	{
		int startIndex = 0;
		int endIndex = 0;
		std::cout << "Input startIndex: ";
		std::cin >> startIndex;
		std::cout << "\nInput endIndex: ";
		std::cin >> endIndex;
		std::cout << "\n";
		MutableListSequence<T>* subsequence = queue->GetSubsequence(startIndex, endIndex);
		std::cout << "Subsequence: ";
		for (int i = 0; i < endIndex - startIndex + 1; i++)
		{
			std::cout << subsequence->Get(i);
		}
		std::cout << "\n";
	}
	void subsequenceSearch()
	{
		int size = 0;
		T value{};
		MutableListSequence<T> buf;
		std::cout << "Input size of sequence which you want to find in queue: ";
		std::cin >> size;
		for (int i = 0; i < size; i++)
		{
			std::cin >> value;
			buf.Append(value);
		}
		bool result = queue->SearchSubsequence(buf);
		if (result == 1)
		{
			std::cout << "\nThis sequence is not in the queue\n";
		}
		else
		{
			std::cout << "\nThis sequence if in the queue\n";
		}
	}
};
template <typename T> struct Vector_func
{
private:
	Vector<T>* vec = new Vector<T>;
public:
	void createVector()
	{
		int size = 0;
		T value{};
		std::cout << "Input size of Vector\n";
		std::cin >> size;
		std::cout << "Input elements of Vector:\n";
		for (int i = 0; i < size; i++)
		{
			std::cin >> value;
			vec->Append(value);
		}
		std::cout << "\n";
	}
	void printVector()
	{
		try
		{
			if (vec->GetSize() == 0)
			{
				std::cout << "Vector is empty\n";
			}
			else
			{
				for (int i = 0; i < vec->GetSize(); i++)
				{
					std::cout << vec->Get(i) << " ";
				}
				std::cout << "\n";
			}
		}
		catch (std::out_of_range& e)
		{
			std::cout << e.what();
		}
		std::cout << "\n";
	}
	void prinGet()
	{
		std::cout << "Input index of element: ";
		int index;
		std::cin >> index;
		try
		{
			std::cout << vec->Get(index);
		}
		catch (std::out_of_range& e)
		{
			std::cout << e.what();
		}
		std::cout << "\n";
	}
	void printSize()
	{
		try
		{
			std::cout << "Size: " << vec->GetSize();
		}
		catch (std::out_of_range& e)
		{
			std::cout << e.what();
		}
		std::cout << "\n";
	}
	void appendValue()
	{
		T value{};
		std::cout << "Enter the value: ";
		std::cin >> value;
		std::cout << "\n";
		vec->Append(value);
	}
	void sumOfVectors()
	{
		std::cout << "Input vector which you want to add to original vector:\n";
		T value{};
		Vector<T>* newVec = new Vector<T>;
		for (int i = 0; i < vec->GetSize(); i++)
		{
			std::cin >> value;
			newVec->Append(value);
		}
		try
		{
			vec->SumOfVectors(reinterpret_cast<Vector<T>&>(newVec));
		}
		catch (std::out_of_range& e)
		{
			std::cout << e.what();
		}
		std::cout << "\n";
	}
	void multByScalar()
	{
		std::cout << "Input the value by which you want to multiply the vector\n";
		T value{};
		std::cin >> value;
		vec->MultByScalar(value);
	}
	void getNormOfVector()
	{
		double result = vec->GetNormOfVector();
		std::cout << std::fixed << std::setprecision(3) << result << "\n";
	}
	void scalarProduct()
	{
		std::cout << "Input the vector with which you want to calculate the scalar product of the original vector:\n";
		Vector<T>* newVec = new Vector<T>;
		T value{};
		for (int i = 0; i < vec->GetSize(); i++)
		{
			std::cin >> value;
			newVec->Append(value);
		}
		T result = vec->ScalarProduct(reinterpret_cast<Vector<T>&>(newVec));
		std::cout << "Result of scalar product: " << result << "\n";
	}
};
template <typename T> struct Vector_funcForComplex
{
private:
	Vector<T>* vec = new Vector<T>;
public:
	void createVector()
	{
		int size = 0;
		T value{};
		std::cout << "Input size of Vector\n";
		std::cin >> size;
		std::cout << "Input elements of Vector:\n";
		for (int i = 0; i < size; i++)
		{
			std::cin >> value;
			vec->Append(value);
		}
		std::cout << "\n";
	}
	void printVector()
	{
		try
		{
			if (vec->GetSize() == 0)
			{
				std::cout << "Vector is empty\n";
			}
			else
			{
				for (int i = 0; i < vec->GetSize(); i++)
				{
					std::cout << vec->Get(i) << " ";
				}
				std::cout << "\n";
			}
		}
		catch (std::out_of_range& e)
		{
			std::cout << e.what();
		}
		std::cout << "\n";
	}
	void prinGet()
	{
		std::cout << "Input index of element: ";
		int index;
		std::cin >> index;
		try
		{
			std::cout << vec->Get(index);
		}
		catch (std::out_of_range& e)
		{
			std::cout << e.what();
		}
		std::cout << "\n";
	}
	void printSize()
	{
		try
		{
			std::cout << "Size: " << vec->GetSize();
		}
		catch (std::out_of_range& e)
		{
			std::cout << e.what();
		}
		std::cout << "\n";
	}
	void appendValue()
	{
		T value{};
		std::cout << "Enter the value: ";
		std::cin >> value;
		std::cout << "\n";
		vec->Append(value);
	}
	void sumOfVectors()
	{
		std::cout << "Input vector which you want to add to original vector:\n";
		T value{};
		Vector<T>* newVec = new Vector<T>;
		for (int i = 0; i < vec->GetSize(); i++)
		{
			std::cin >> value;
			newVec->Append(value);
		}
		try
		{
			vec->SumOfVectors(reinterpret_cast<Vector<T>&>(newVec));
		}
		catch (std::out_of_range& e)
		{
			std::cout << e.what();
		}
		std::cout << "\n";
	}
	void multByScalar()
	{
		std::cout << "Input the value by which you want to multiply the vector\n";
		T value{};
		std::cin >> value;
		vec->MultByScalar(value);
	}
	void getNormOfVector()
	{
		std::cout << "it is impossible to get a norm with complex numbers\n";
	}
	void scalarProduct()
	{
		std::cout << "Input the vector with which you want to calculate the scalar product of the original vector:\n";
		Vector<T>* newVec = new Vector<T>;
		T value{};
		for (int i = 0; i < vec->GetSize(); i++)
		{
			std::cin >> value;
			newVec->Append(value);
		}
		T result = vec->ScalarProduct(reinterpret_cast<Vector<T>&>(newVec));
		std::cout << "Result of scalar product: " << result << "\n";
	}
};

template <typename T> struct MutableListSequence_func
{
private:
	MutableListSequence<T>* sequence = new MutableListSequence<T>;
public:
	void createSequence()
	{
		int length = 0;
		T value{};
		std::cout << "Input size of Mutable Linked List\n";
		std::cin >> length;
		std::cout << "Input elements of Mutable Linked List:\n";
		for (int i = 0; i < length; i++)
		{
			std::cin >> value;
			sequence->Append(value);
		}
		std::cout << "\n";
	}
	void printSequence()
	{
		try
		{
			if (sequence->GetLength() == 0)
			{
				std::cout << "Mutable Linked List is empty\n";
			}
			else
			{
				for (int i = 0; i < sequence->GetLength(); i++)
				{
					std::cout << sequence->Get(i) << " ";
				}
				std::cout << "\n";
			}
		}
		catch (std::out_of_range& e)
		{
			std::cout << e.what();
		}
		std::cout << "\n";
	}
	void printFirst()
	{
		try
		{
			std::cout << sequence->GetFirst();
		}
		catch(std::out_of_range& e)
		{
			std::cout << e.what();
		}
		std::cout << "\n";
	}
	void printLast()
	{
		try
		{
			std::cout << sequence->GetLast();
		}
		catch (std::out_of_range& e)
		{
			std::cout << e.what();
		}
		std::cout << "\n";
	}
	void printGet()
	{
		std::cout << "Input index of element: ";
		int index;
		std::cin >> index;
		try
		{
			std::cout << sequence->Get(index);
		}
		catch(std::out_of_range& e)
		{
			std::cout << e.what();
		}
		std::cout << "\n";
	}
	void printSubsequence()
	{
		int startIndex;
		int endIndex;
		try
		{
			std::cout << "Input startIndex of subsequence: ";
			std::cin >> startIndex;
			std::cout << "input endIndex of subsequence: ";
			std::cin >> endIndex;
			Sequence<T>* subsequence = sequence->GetSubsequence(startIndex, endIndex);
			for (int i = 0; i < subsequence->GetLength(); i++)
			{
				std::cout << subsequence->Get(i) << " ";
			}
			std::cout << "\n";
			delete subsequence;
		}
		catch (std::out_of_range& e)
		{
			std::cout << e.what();
		}
		std::cout << "\n";
	}
	void printLength()
	{
		try
		{
			std::cout << "Size: " << sequence->GetLength();
		}
		catch (std::out_of_range& e)
		{
			std::cout << e.what();
		}
		std::cout << "\n";
	}
	void appendValue()
	{
		T value{};
		std::cout << "Enter the value: ";
		std::cin >> value;
		std::cout << "\n";
		sequence->Append(value);
	}
	void prependValue()
	{
		T value{};
		std::cout << "Enter the value: ";
		std::cin >> value;
		std::cout << "\n";
		sequence->Prepend(value);
	}
	void insertAtValue()
	{
		int index;
		std::cout << "Enter the index of element: ";
		std::cin >> index;
		std::cout << "Enter the value of element number: ";
		try {
			T item{};
			std::cin >> item;
			sequence->InsertAt(index, item);
		}
		catch (const std::out_of_range& e) {
			std::cout << e.what();
		}
		std::cout << "\n";
	}
	void concatSequence()
	{
		int length;
		std::cout << "Input length of sequence which you want to concat:\n"; 
		std::cin >> length;
		T value{};
		std::cout << "Input elements of sequence which you want to concat:\n";
		for (int i = 0; i < length; i++)
		{
			std::cin >> value;
			sequence->Append(value);
		}
	}
};

template <typename T> struct ImmutableListSequence_func
{
private:
	ImmutableListSequence<T>* sequence = new ImmutableListSequence<T>;
public:
	void createSequence()
	{
		int length = 0;
		T value{};
		std::cout << "Input size of Immutable Linked List\n";
		std::cin >> length;
		std::cout << "Input elements of Immutable Linked List:\n";
		for (int i = 0; i < length; i++)
		{
			std::cin >> value;
			sequence->Append(value);
		}
		std::cout << "\n";
	}
	void printSequence()
	{
		try
		{
			if (sequence->GetLength() <= 0)
			{
				std::cout << "Immutable Linked List is empty\n";
			}
			else
			{
				for (int i = 0; i < sequence->GetLength(); i++)
				{
					std::cout << sequence->Get(i) << " ";
				}
				std::cout << "\n";
			}
		}
		catch (std::out_of_range& e)
		{
			std::cout << e.what();
		}
		std::cout << "\n";
	}
	void printFirst()
	{
		try
		{
			std::cout << sequence->GetFirst();
		}
		catch (std::out_of_range& e)
		{
			std::cout << e.what();
		}
		std::cout << "\n";
	}
	void printLast()
	{
		try
		{
			std::cout << sequence->GetLast();
		}
		catch (std::out_of_range& e)
		{
			std::cout << e.what();
		}
		std::cout << "\n";
	}
	void printGet()
	{
		std::cout << "Input index of element: ";
		int index;
		std::cin >> index;
		try
		{
			std::cout << sequence->Get(index);
		}
		catch (std::out_of_range& e)
		{
			std::cout << e.what();
		}
		std::cout << "\n";
	}
	void printSubsequence()
	{
		int startIndex;
		int endIndex;
		try
		{
			std::cout << "Input startIndex of subsequence: ";
			std::cin >> startIndex;
			std::cout << "input endIndex of subsequence: ";
			std::cin >> endIndex;
			Sequence<T>* subsequence = sequence->GetSubsequence(startIndex, endIndex);
			for (int i = 0; i < subsequence->GetLength(); i++)
			{
				std::cout << subsequence->Get(i) << " ";
			}
			std::cout << "\n";
			delete subsequence;
		}
		catch (std::out_of_range& e)
		{
			std::cout << e.what();
		}
		std::cout << "\n";
	}
	void printLength()
	{
		try
		{
			std::cout << "Size: " << sequence->GetLength();
		}
		catch (std::out_of_range& e)
		{
			std::cout << e.what();
		}
		std::cout << "\n";
	}
};

template <typename T> struct MutableArraySequence_func
{
private:
	MutableArraySequence<T>* sequence = new MutableArraySequence<T>;
public:
	void createSequence()
	{
		int length = 0;
		T value{};
		std::cout << "Input size of Mutable Dynamic Array\n";
		std::cin >> length;
		std::cout << "Input elements of Mutable Dynamic Array:\n";
		for (int i = 0; i < length; i++)
		{
			std::cin >> value;
			sequence->Append(value);
		}
		std::cout << "\n";
	}
	void printSequence()
	{
		try
		{
			if (sequence->GetLength() <= 0)
			{
				std::cout << "Mutable Dynamic Array is empty\n";
			}
			else
			{
				for (int i = 0; i < sequence->GetLength(); i++)
				{
					std::cout << sequence->Get(i) << " ";
				}
				std::cout << "\n";
			}
		}
		catch (std::out_of_range& e)
		{
			std::cout << e.what();
		}
		std::cout << "\n";
	}
	void printFirst()
	{
		try
		{
			std::cout << sequence->GetFirst();
		}
		catch (std::out_of_range& e)
		{
			std::cout << e.what();
		}
		std::cout << "\n";
	}
	void printLast()
	{
		try
		{
			std::cout << sequence->GetLast();
		}
		catch (std::out_of_range& e)
		{
			std::cout << e.what();
		}
		std::cout << "\n";
	}
	void printGet()
	{
		std::cout << "Input index of element: ";
		int index;
		std::cin >> index;
		try
		{
			std::cout << sequence->Get(index);
		}
		catch (std::out_of_range& e)
		{
			std::cout << e.what();
		}
		std::cout << "\n";
	}
	void printSubsequence()
	{
		int startIndex;
		int endIndex;
		try
		{
			std::cout << "Input startIndex of subsequence: ";
			std::cin >> startIndex;
			std::cout << "input endIndex of subsequence: ";
			std::cin >> endIndex;
			Sequence<T>* subsequence = sequence->GetSubsequence(startIndex, endIndex);
			for (int i = 0; i < subsequence->GetLength(); i++)
			{
				std::cout << subsequence->Get(i) << " ";
			}
			std::cout << "\n";
			delete subsequence;
		}
		catch (std::out_of_range& e)
		{
			std::cout << e.what();
		}
		std::cout << "\n";
	}
	void printLength()
	{
		try
		{
			std::cout << "Size: " << sequence->GetLength();
		}
		catch (std::out_of_range& e)
		{
			std::cout << e.what();
		}
		std::cout << "\n";
	}
	void appendValue()
	{
		T value{};
		std::cout << "Enter the value: ";
		std::cin >> value;
		std::cout << "\n";
		sequence->Append(value);
	}
	void prependValue()
	{
		T value{};
		std::cout << "Enter the value: ";
		std::cin >> value;
		std::cout << "\n";
		sequence->Prepend(value);
	}
	void insertAtValue()
	{
		int index;
		T value{};
		std::cout << "Enter the value: ";
		std::cin >> value;
		std::cout << "Enter the index: ";
		std::cin >> index;
		std::cout << "\n";
		sequence->InsertAt(index, value);
	}
	void concatSequence()
	{
		int length;
		std::cout << "Input length of sequence which you want to concat:\n";
		std::cin >> length;
		T value{};
		std::cout << "Input elements of sequence which you want to concat:\n";
		for (int i = 0; i < length; i++)
		{
			std::cin >> value;
			sequence->Append(value);
		}
	}
};

template <typename T> struct ImmutableArraySequence_func
{
private:
	ImmutableListSequence<T>* sequence = new ImmutableListSequence<T>;
public:
	void createSequence()
	{
		int length = 0;
		T value{};
		std::cout << "Input size of Immutable Dynamic Array\n";
		std::cin >> length;
		std::cout << "Input elements of Immutable Dynamic Array:\n";
		for (int i = 0; i < length; i++)
		{
			std::cin >> value;
			sequence->Append(value);
		}
		std::cout << "\n";
	}
	void printSequence()
	{
		try
		{
			if (sequence->GetLength() <= 0)
			{
				std::cout << "Immutable array is empty\n";
			}
			else
			{
				for (int i = 0; i < sequence->GetLength(); i++)
				{
					std::cout << sequence->Get(i);
				}
				std::cout << "\n";
			}
		}
		catch (std::out_of_range& e)
		{
			std::cout << e.what();
		}
		std::cout << "\n";
	}
	void printFirst()
	{
		try
		{
			std::cout << sequence->GetFirst();
		}
		catch (std::out_of_range& e)
		{
			std::cout << e.what();
		}
		std::cout << "\n";
	}
	void printLast()
	{
		try
		{
			std::cout << sequence->GetLast();
		}
		catch (std::out_of_range& e)
		{
			std::cout << e.what();
		}
		std::cout << "\n";
	}
	void printGet()
	{
		std::cout << "Input index of element: ";
		int index;
		std::cin >> index;
		try
		{
			std::cout << sequence->Get(index);
		}
		catch (std::out_of_range& e)
		{
			std::cout << e.what();
		}
		std::cout << "\n";
	}
	void printSubsequence()
	{
		int startIndex;
		int endIndex;
		try
		{
			std::cout << "Input startIndex of subsequence: ";
			std::cin >> startIndex;
			std::cout << "input endIndex of subsequence: ";
			std::cin >> endIndex;
			Sequence<T>* subsequence = sequence->GetSubsequence(startIndex, endIndex);
			for (int i = 0; i < subsequence->GetLength(); i++)
			{
				std::cout << subsequence->Get(i) << " ";
			}
			std::cout << "\n";
			delete subsequence;
		}
		catch (std::out_of_range& e)
		{
			std::cout << e.what();
		}
		std::cout << "\n";
	}
	void printLength()
	{
		try
		{
			std::cout << "Size: " << sequence->GetLength();
		}
		catch (std::out_of_range& e)
		{
			std::cout << e.what();
		}
		std::cout << "\n";
	}
};
template <typename T> class Queue_UI
{
private:
	void Choosing()
	{
		Queue_func<T> userQueue;
		int choose = 0;
		std::cout << "Choose what you want to do with sequence:\n";
		std::cout << "0: finist the program\n";
		std::cout << "1: create queue\n";
		std::cout << "2: print queue\n";
		std::cout << "3: print size of queue\n";
		std::cout << "4: print an element at the specified index\n";
		std::cout << "5: append value\n";
		std::cout << "6: pop element\n";
		std::cout << "7: concat queue\n";
		std::cout << "8: get subsequence\n";
		std::cout << "9: search subsequence\n";
		std::cin >> choose;
		while (choose < 0 || choose > 9)
		{
			std::cout << "The wrong number was entered. Try again\n";
			std::cin >> choose;
		}
		while (choose != 0)
		{
			switch(choose)
			{
				case 1:
					userQueue.creatQueue();
					break;
				case 2:
					userQueue.printQueue();
					break;
				case 3:
					userQueue.printSize();
					break;
				case 4:
					userQueue.printGet();
					break;
				case 5:
					userQueue.appendValue();
					break;
				case 6:
					userQueue.pop();
					break;
				case 7:
					userQueue.concat();
					break;
				case 8:
					userQueue.getSubsequence();
						break;
				case 9:
					userQueue.subsequenceSearch();
					break;
			}
			std::cout << "Enter the number of action again:\n";
			std::cin >> choose;
			while (choose < 0 || choose > 9)
			{
				std::cout << "The wrong number was entered. Try again\n";
			}
		}
	}
public:
	void start()
	{
		int choose1 = 0;
		Choosing();
		std::cout << "You have finished the program\n";
	}
};
template <typename T> class Vector_UI
{
private:
	void Choosing()
	{
		Vector_func<T> userVector;
		int choose = 0;
		std::cout << "Choose what you want to do with sequence:\n";
		std::cout << "0: finish the program\n";
		std::cout << "1: create vector\n";
		std::cout << "2: print Vector\n";
		std::cout << "3: print an element at the specified index\n";
		std::cout << "4: print size of vector\n";
		std::cout << "5: append value\n";
		std::cout << "6: adding vectors\n";
		std::cout << "7: multiplication by scalar\n";
		std::cout << "8: get norm of vector\n";
		std::cout << "9: scalar production\n";
		std::cin >> choose;
		while (choose < 0 || choose > 9)
		{
			std::cout << "The wrong number was entered. Try again\n";
			std::cin >> choose;
		}
		while (choose != 0)
		{
			switch (choose)
			{
			case 1:
				userVector.createVector();
				break;
			case 2:
				userVector.printVector();
				break;
			case 3:
				userVector.prinGet();
				break;
			case 4:
				userVector.printSize();
				break;
			case 5:
				userVector.appendValue();
				break;
			case 6:
				userVector.sumOfVectors();
				break;
			case 7: 
				userVector.multByScalar();
				break;
			case 8:
				userVector.getNormOfVector();
				break;
			case 9:
				userVector.scalarProduct();
				break;
			}
			std::cout << "Enter the number of action again:\n";
			std::cin >> choose;
			while (choose < 0 || choose > 9)
			{
				std::cout << "The wrong number was entered. Try again\n";
			}
		}
	}
public:
	void start()
	{
		int choose1 = 0;
		Choosing();
		std::cout << "You have finished the program";
	}
};

template <typename T> class Vector_UIForComplex
{
private:
	void Choosing()
	{
		Vector_funcForComplex<T> userVector;
		int choose = 0;
		std::cout << "Choose what you want to do with sequence:\n";
		std::cout << "0: finish the program\n";
		std::cout << "1: create vector\n";
		std::cout << "2: print Vector\n";
		std::cout << "3: print an element at the specified index\n";
		std::cout << "4: print size of vector\n";
		std::cout << "5: append value\n";
		std::cout << "6: adding vectors\n";
		std::cout << "7: multiplication by scalar\n";
		std::cout << "8: get norm of vector\n";
		std::cout << "9: scalar production\n";
		std::cin >> choose;
		while (choose < 0 || choose > 9)
		{
			std::cout << "The wrong number was entered. Try again\n";
			std::cin >> choose;
		}
		while (choose != 0)
		{
			switch (choose)
			{
			case 1:
				userVector.createVector();
				break;
			case 2:
				userVector.printVector();
				break;
			case 3:
				userVector.prinGet();
				break;
			case 4:
				userVector.printSize();
				break;
			case 5:
				userVector.appendValue();
				break;
			case 6:
				userVector.sumOfVectors();
				break;
			case 7:
				userVector.multByScalar();
				break;
			case 8:
				userVector.getNormOfVector();
				break;
			case 9:
				userVector.scalarProduct();
				break;
			}
			std::cout << "Enter the number of action again:\n";
			std::cin >> choose;
			while (choose < 0 || choose > 9)
			{
				std::cout << "The wrong number was entered. Try again\n";
			}
		}
	}
public:
	void start()
	{
		int choose1 = 0;
		Choosing();
		std::cout << "You have finished the program";
	}
};
template <typename T> class MutableArraySequence_UI
{
private:
	void Choosing()
	{
		MutableArraySequence_func<T> userSequence;
		int choose = 0;
		std::cout << "Choose what you want to do with sequence:\n";
		std::cout << "0: finish the program\n";
		std::cout << "1: create sequence\n";
		std::cout << "2: print sequence\n";
		std::cout << "3: print first element of sequence\n";
		std::cout << "4: print last element of sequence\n";
		std::cout << "5: print an element at the specified index\n";
		std::cout << "6: print subsequence\n";
		std::cout << "7: print size of sequence\n";
		std::cout << "8: append value\n";
		std::cout << "9: prepend value\n";
		std::cout << "10: insert at value\n";
		std::cout << "11: concat sequence\n";
		std::cin >> choose;
		while (choose < 0 || choose > 11)
		{
			std::cout << "The wrong number was entered. Try again\n";
			std::cin >> choose;
		}
		while (choose != 0)
		{
			switch (choose)
			{
			case 1:
				userSequence.createSequence();
				break;
			case 2:
				userSequence.printSequence();
				break;
			case 3:
				userSequence.printFirst();
				break;
			case 4:
				userSequence.printLast();
				break;
			case 5:
				userSequence.printGet();
				break;
			case 6:
				userSequence.printSubsequence();
				break;
			case 7:
				userSequence.printLength();
				break;
			case 8:
				userSequence.appendValue();
				break;
			case 9:
				userSequence.prependValue();
				break;
			case 10:
				userSequence.insertAtValue();
				break;
			case 11:
				userSequence.concatSequence();
			}
			std::cout << "Enter the number of action again:\n";
			std::cin >> choose;
			while (choose < 0 || choose > 11)
			{
				std::cout << "The wrong number was entered. Try again\n";
				std::cin >> choose;
			}
		}
	}
public:
	void start()
	{
		int choose1 = 0;
		Choosing();
		std::cout << "You have finished the program";
	}
};

template <typename T> class MutableListSequence_UI
{
private:
	void Choosing()
	{
		MutableListSequence_func<T> userSequence;
		int choose = 0;
		std::cout << "Choose what you want to do with sequence:\n";
		std::cout << "0: finish the program\n";
		std::cout << "1: create sequence\n";
		std::cout << "2: print sequence\n";
		std::cout << "3: print first element of sequence\n";
		std::cout << "4: print last element of sequence\n";
		std::cout << "5: print an element at the specified index\n";
		std::cout << "6: print subsequence\n";
		std::cout << "7: print size of sequence\n";
		std::cout << "8: append value\n";
		std::cout << "9: prepend value\n";
		std::cout << "10: insert at value\n";
		std::cout << "11: concat sequence\n";
		std::cin >> choose;
		while (choose < 0 || choose > 11)
		{
			std::cout << "The wrong number was entered. Try again\n";
			std::cin >> choose;
		}
		while (choose != 0)
		{
			switch (choose)
			{
			case 1:
				userSequence.createSequence();
				break;
			case 2:
				userSequence.printSequence();
				break;
			case 3:
				userSequence.printFirst();
				break;
			case 4:
				userSequence.printLast();
				break;
			case 5:
				userSequence.printGet();
				break;
			case 6:
				userSequence.printSubsequence();
				break;
			case 7:
				userSequence.printLength();
				break;
			case 8:
				userSequence.appendValue();
				break;
			case 9:
				userSequence.prependValue();
				break;
			case 10:
				userSequence.insertAtValue();
				break;
			case 11:
				userSequence.concatSequence();
				break;
			}
			std::cout << "Enter the number of action again:\n";
			std::cin >> choose;
			while (choose < 0 || choose > 11)
			{
				std::cout << "The wrong number was entered. Try again\n";
				std::cin >> choose;
			}
		}
	}
public:
	void start()
	{
		int choose1 = 0;
		Choosing();
		std::cout << "You have finished the program";
	}
};


template <typename T> class ImmutableArraySequence_UI
{
private:
	void Choosing()
	{
		ImmutableArraySequence_func<T> userSequence;
		int choose = 0;
		std::cout << "Choose what you want to do with sequence:\n";
		std::cout << "0: finish the program\n";
		std::cout << "1: create sequence\n";
		std::cout << "2: print sequence\n";
		std::cout << "3: print first element of sequence\n";
		std::cout << "4: print last element of sequence\n";
		std::cout << "5: print an element at the specified index\n";
		std::cout << "6: print subsequence\n";
		std::cout << "7: print size of sequence\n";
		std::cin >> choose;
		while (choose < 0 || choose > 7)
		{
			std::cout << "The wrong number was entered. Try again\n";
			std::cin >> choose;
		}
		while (choose != 0)
		{
			switch (choose)
			{
			case 1:
				userSequence.createSequence();
				break;
			case 2:
				userSequence.printSequence();
				break;
			case 3:
				userSequence.printFirst();
				break;
			case 4:
				userSequence.printLast();
				break;
			case 5:
				userSequence.printGet();
				break;
			case 6:
				userSequence.printSubsequence();
				break;
			case 7:
				userSequence.printLength();
				break;
			}
			std::cout << "Enter the number of action again:\n";
			std::cin >> choose;
			while (choose < 0 || choose > 7)
			{
				std::cout << "The wrong number was entered. Try again\n";
				std::cin >> choose;
			}
		}
	}
public:
	void start()
	{
		int choose1 = 0;
		Choosing();
		std::cout << "You have finished the program";
	}
};


template <typename T> class ImmutableListSequence_UI
{
private:
	void Choosing()
	{
		ImmutableListSequence_func<T> userSequence;
		int choose = 0;
		std::cout << "Choose what you want to do with sequence:\n";
		std::cout << "0: finish the program\n";
		std::cout << "1: create sequence\n";
		std::cout << "2: print sequence\n";
		std::cout << "3: print first element of sequence\n";
		std::cout << "4: print last element of sequence\n";
		std::cout << "5: print an element at the specified index\n";
		std::cout << "6: print subsequence\n";
		std::cout << "7: print size of sequence\n";
		std::cin >> choose;
		while (choose < 0 || choose > 7)
		{
			std::cout << "The wrong number was entered. Try again\n";
			std::cin >> choose;
		}
		while (choose != 0)
		{
			switch (choose)
			{
			case 1:
				userSequence.createSequence();
				break;
			case 2:
				userSequence.printSequence();
				break;
			case 3:
				userSequence.printFirst();
				break;
			case 4:
				userSequence.printLast();
				break;
			case 5:
				userSequence.printGet();
				break;
			case 6:
				userSequence.printSubsequence();
				break;
			case 7:
				userSequence.printLength();
				break;
			}
			std::cout << "Enter the number of action again:\n";
			std::cin >> choose;
			while (choose < 0 || choose > 7)
			{
				std::cout << "The wrong number was entered. Try again\n";
				std::cin >> choose;
			}
		}
	}
public:
	void start()
	{
		int choose1 = 0;
		Choosing();
		std::cout << "You have finished the program";
	}
};


int selectType1()
{
	int selectedType = 0;
	std::cout << "Choose:\n";
	std::cout << "MutableSequence - enter 1\n";
	std::cout << "ImmutableSequence - enter 2\n";
	std::cout << "Vector - enter 3\n";
	std::cout << "Queue - enter 4\n";
	std::cin >> selectedType;
	while (selectedType < 1 || selectedType > 4)
	{
		std::cout << "The wrong number was entered. Try again\n";
		std::cin >> selectedType;
	}
	std::cout << "\n";
	return selectedType;
}
int selectType2()
{
	int selectedType = 0;
	std::cout << "Choose:\n";
	std::cout << "Array sequence - enter 1\n";
	std::cout << "List sequence - enter 2\n";
	std::cin >> selectedType;
	while (selectedType < 1 || selectedType > 2)
	{
		std::cout << "The wrong number was entered. Try again\n";
		std::cin >> selectedType;
	}
	std::cout << "\n";
	return selectedType;
}
int selectType3()
{
	int selectedType = 0;
	std::cout << "Choose type of elements in sequence:\n";
	std::cout << "int - enter 1\n";
	std::cout << "double - enter 2\n";
	std::cout << "char - enter 3\n";
	std::cout << "complex - enter 4\n";
	std::cout << "person - enter 5\n";
	std::cin >> selectedType;
	while (selectedType < 1 || selectedType> 5)
	{
		std::cout << "The wrong number was entered. Try again\n";
		std::cin >> selectedType;
	}
	std::cout << "\n";
	return selectedType;
}
void startUI()
{
	std::cout << "Let's start work with sequence\n";
	int selectedType1 = selectType1();
	int selectedType2{};
	if (selectedType1 == 1 || selectedType1 == 2)
	{
		int selectedType2 = selectType2();

	}
	int selectedType3 = selectType3();
	if (selectedType1 == 1)
	{
		if (selectedType2 == 1)
		{
			if (selectedType3 == 1)
			{
				MutableArraySequence_UI<int> sequence;
				sequence.start();
			}
			if (selectedType3 == 2)
			{
				MutableArraySequence_UI<double> sequence;
				sequence.start();
			}
			if (selectedType3 == 3)
			{
				MutableArraySequence_UI<char> sequence;
			}
		}
		if (selectedType2 == 2)
		{
			if (selectedType3 == 1)
			{
				MutableListSequence_UI<int> sequence;
				sequence.start();
			}
			if (selectedType3 == 2)
			{
				MutableListSequence_UI<double> sequence;
				sequence.start();
			}
			if (selectedType3 == 3)
			{
				MutableListSequence_UI<char> sequence;
				sequence.start();
			}
		}
	}
	if (selectedType1 == 2)
	{
		if (selectedType2 == 1)
		{
			if (selectedType3 == 1)
			{
				ImmutableArraySequence_UI<int> sequence;
				sequence.start();
			}
			if (selectedType3 == 2)
			{
				ImmutableArraySequence_UI<double> sequence;
				sequence.start();
			}
			if (selectedType3 == 3)
			{
				ImmutableArraySequence_UI<char> sequence;
			}
		}
		if (selectedType2 == 2)
		{
			if (selectedType3 == 1)
			{
				ImmutableListSequence_UI<int> sequence;
				sequence.start();
			}
			if (selectedType3 == 2)
			{
				ImmutableListSequence_UI<double> sequence;
				sequence.start();
			}
			if (selectedType3 == 3)
			{
				ImmutableListSequence_UI<char> sequence;
				sequence.start();
			}
		}
	}
	if (selectedType1 == 3)
	{
		if (selectedType3 == 1)
		{
			Vector_UI<int> vec;
			vec.start();
		}
		if (selectedType3 == 2)
		{
			Vector_UI<double> vec;
			vec.start();
		}
		if (selectedType3 == 3)
		{
			Vector_UI<char> vec;
			vec.start();
		}
		if (selectedType3 == 4)
		{
			Vector_UIForComplex<Complex> vec;
			vec.start();
		}
	}
	if (selectedType1 == 4)
	{
		if (selectedType3 == 1)
		{
			Queue_UI<int> queue;
			queue.start();
		}
		if (selectedType3 == 2)
		{
			Queue_UI<double> queue;
			queue.start();
		}
		if (selectedType3 == 3)
		{
			Queue_UI<char> queue;
			queue.start();
		}
		if (selectedType3 == 4)
		{
			Queue_UI<Complex> queue;
			queue.start();
		}
		if (selectedType3 == 5)
		{
			Queue_UI<Person> queue;
			queue.start();
		}
	}
}
