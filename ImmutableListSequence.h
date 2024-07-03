#pragma once

#include <stdexcept>
#include <iostream>

#include "Sequence.h"
#include "ImmutableSequence.h"
#include "LinkedList.h"
#include "DynamicArray.h"

template <class T> class ImmutableListSequence: public ImmutableSequence<T>
{
private:
	LinkedList<T>* list;
public:
	ImmutableListSequence(const T* items, int size) : list(new LinkedList<T>(items, size)) {}
	ImmutableListSequence() : list(new LinkedList<T>()) {}
	ImmutableListSequence(int size) : list(new LinkedList<T>(size)) {}
	ImmutableListSequence(const LinkedList<T>& other) : list(new LinkedList<T>(other)) {}
	ImmutableListSequence(const DynamicArray<T>& other) : list(new LinkedList<T>(other)) {}
	ImmutableListSequence(const Sequence<T>& other) : list(new LinkedList<T>(other)) {}
	ImmutableListSequence(const ImmutableListSequence<T>& other) : list(new LinkedList<T>(*other.list)) {}
	~ImmutableListSequence() override
	{
		delete this->list;
	}
	const T& operator[] (int index) const override
	{
		return (*list)[index];
	}
	T GetFirst() const override
	{
		return this->list->GetFirst();
	}
	T GetLast() const override
	{
		return this->list->GetLast();
	}
	T& Get(int index) const override
	{
		return (*list)[index];
	}
	ImmutableListSequence<T>* GetSubsequence(int startIndex, int endIndex) const override
	{
		ImmutableListSequence<T>* result = new ImmutableListSequence<T>();
		for (int i = startIndex; i <= endIndex; i++)
		{
			result->list->Append(this->Get(i));
		}
		return result;
	}
	int GetLength() const override
	{
		return this->list->GetLength();
	}
	ImmutableListSequence<T>* Append(const T& item) const override
	{
		ImmutableListSequence<T>* result = new ImmutableListSequence<T>(*this);
		result->list->Append(item);
		return result;
	}
	ImmutableListSequence<T>* Prepend(const T& item) const override
	{
		ImmutableListSequence<T>* result = new ImmutableListSequence<T>(*this);
		result->list->Prepend(item);
		return result;
	}
	ImmutableListSequence<T>* InsertAt(int index, const T& item) const override
	{
		ImmutableListSequence<T>* result = new ImmutableListSequence<T>(*this);
		result->list->InsertAt(index, item);
		return result;
	}
	ImmutableListSequence<T>* Concat(const Sequence<T>& other) const 
	{
		ImmutableListSequence<T>* result = new ImmutableListSequence<T>(*this);
		for (int i = 0; i < other.GetLength(); i++)
		{
			result->list->Append(other.Get(i));
		}
		return result;
	}
	ImmutableListSequence<T>* Set(int index, const T& item) const
	{
		ImmutableListSequence<T>* result = new ImmutableListSequence<T>(*this);
		result->list->Set(index, item);
		return result;
	}
};

