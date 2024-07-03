#pragma once

#include <stdexcept>
#include <iostream>

#include "Sequence.h"
#include "ImmutableSequence.h"
#include "DynamicArray.h"
#include "LinkedList.h"

template <class T> class ImmutableArraySequence: public ImmutableSequence<T>
{
private:
	DynamicArray<T>* array;
public:
	ImmutableArraySequence(const T* items, int size) : array(new DynamicArray<T>(items, size)) {}
	ImmutableArraySequence(int size) : array(new DynamicArray<T>(size)) {}
	ImmutableArraySequence() : array(new DynamicArray<T>()) {}
	ImmutableArraySequence(const DynamicArray<T>& other) : array(new DynamicArray<T>(other)) {}
	ImmutableArraySequence(const LinkedList<T>& other) : array(new DynamicArray<T>(other)) {}
	ImmutableArraySequence(const Sequence<T>& other) : array(new DynamicArray<T>(other)) {}
	ImmutableArraySequence(const ImmutableArraySequence<T>& other) : array(new DynamicArray<T>(*other.array)) {}
	~ImmutableArraySequence() override
	{
		delete array;
	}
	const T& operator[](int index) const override
	{
		return (*array)[index];
	}
	T GetFirst() const override //Получить первый элемент в списке
	{
		return static_cast<T>(this->array->Get(0));
	}
	T GetLast() const override
	{
		return static_cast<T>(this->array->Get(this->array->GetSize() - 1));
	}
	T& Get(int index) const override//Получить элемент по индексу.
	{
		return (*this->array)[index];
	}
	ImmutableArraySequence<T>* GetSubsequence(int startIndex, int endIndex) const override//Получить список из всех элементов, начиная с startIndex и заканчивая endIndex.
	{
		ImmutableArraySequence<T>* result = new ImmutableArraySequence<T>(endIndex - startIndex + 1);
		for (int i = 0; i < result->GetLength(); i++)
		{
			result->array->Set(i, Get(i + startIndex));
		}
		return result;
	}
	int GetLength() const override//Получить длину списка
	{
		return this->array->GetSize();
	}
	ImmutableArraySequence<T>* Append(const T& item) const override//Добавляет элемент в конец списка
	{
		ImmutableArraySequence<T>* result = new ImmutableArraySequence<T>(*this);
		result->array->Append(item);
		return result;
	}
	ImmutableArraySequence<T>* Prepend(const T& item) const override//Добавляет элемент в начало списка
	{
		ImmutableArraySequence<T>* result = new ImmutableArraySequence<T>(this->GetLength() + 1);
		for (int i = this->GetLength(); i > 0; i--)
		{
			result->array->Set(i, this->Get(i - 1));
		}
		result->array->Set(0, item);
		return result;
	}
	ImmutableArraySequence<T>* InsertAt(int index, const T& item) const override//Вставляет элемент в заданную позицию
	{
		ImmutableArraySequence<T>* result = new ImmutableArraySequence<T>(this->GetLength() + 1);
		for (int i = 0; i < index; i++)
		{
			result->array->Set(i, this->Get(i));
		}
		result->array->Set(index, item);
		for (int i = index; i < this->GetLength(); i++)
		{
			result->array->Set(i + 1, this->Get(i));
		}
		return result;
	}
	ImmutableArraySequence<T>* Concat(const Sequence<T>& other) const //Сцепляет два списка
	{
		ImmutableArraySequence<T>* result = new ImmutableArraySequence<T>(*this);
		for (int i = 0; i < other.GetLength(); i++)
		{
			result->array->Append(other.Get(i));
		}
		return result;
	}
	ImmutableArraySequence<T>* Set(int index, const T& item) const
	{
		ImmutableArraySequence<T>* result = new ImmutableArraySequence<T>(*this);
		result->array->Set(index, item);
		return result;
	}
};