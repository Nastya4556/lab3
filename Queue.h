#pragma once

#include "MutableListSequence.h"
#include "Sequence.h"

template <typename T> class Queue
{
private:
	MutableListSequence<T>* queue;
public:
	Queue()
	{
		this->queue = new MutableListSequence<T>;
	}
	Queue(const T* other, int size)
	{
		this->queue = new MutableListSequence<T>;
		for (int i = 0; i < size; i++)
		{
			this->queue->Append(other[i]);
		}
	}
	Queue(const Queue<T>& other)
	{
		this->queue = new MutableListSequence<T>;
		for (int i = 0; i < other.GetLength(); i++)
		{
			this->queue->Append(other.Get(i));
		}
	}
	~Queue()
	{
		delete queue;
	}
	int GetLength() const
	{
		return this->queue->GetLength();
	}
	T& Get(int index) const
	{
		return queue->Get(index);
	}
	void Append(const T& value)
	{
		this->queue->Append(value);
	}
	void Pop()
	{
		MutableListSequence<T>* result = new MutableListSequence<T>;
		for (int i = 1; i < this->GetLength(); i++)
		{
			result->Append(this->Get(i));
		}
		delete[] this->queue;
		this->queue = result;
	}
	void Map(T mupFunc(T arg))
	{
		this->queue = this->queue->Map(mupFunc);
	}
	void Where(bool (*whereFunc)(T))
	{
		this->queue = this->queue->Where(whereFunc);
	}
	void Concat(const Sequence<T>& other)
	{
		this->queue = this->queue->Concat(other);
	}
	MutableListSequence<T>* GetSubsequence(int startIndex, int endIndex)
	{
		return this->queue->GetSubsequence(startIndex, endIndex);
	}
	bool SearchSubsequence(const Sequence<T>& other)
	{
		bool buf = this->queue->SearchSubsequence(other);
		return buf;
	}
	T Reduce(T reduceFunc(T arg, T buf))
	{
		T result = this->queue->Reduce(reduceFunc);
		return result;
	}
};