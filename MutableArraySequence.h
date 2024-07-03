#pragma once

#include <stdexcept>
#include <iostream>

#include "Sequence.h"
#include "MutableSequence.h"
#include "DynamicArray.h"
#include "LinkedList.h"

template <class T> class MutableArraySequence : public MutableSequence<T>
{
private:
	DynamicArray<T>* array;
public:
	MutableArraySequence(const T* items, int size) : array(new DynamicArray<T>(items, size)) {}
	MutableArraySequence(int size) : array(new DynamicArray<T>(size)) {}
	MutableArraySequence() : array(new DynamicArray<T>()) {}
	MutableArraySequence(const DynamicArray<T>& other) : array(new DynamicArray<T>(other)) {}
	MutableArraySequence(const LinkedList<T>& other) : array(new DynamicArray<T>(other)) {}
	MutableArraySequence(const Sequence<T>& other) : array(new DynamicArray<T>(other)) {}
	MutableArraySequence(const MutableArraySequence<T>& other) : array(new DynamicArray<T>(*other.array)) {}
	~MutableArraySequence() override
	{
		delete array;
	}
	const T& operator [] (int index) const override
	{
		return this->array->Get(index);
	}
	T GetFirst() const override//Получить первый элемент в списке
	{
		return this->array->Get(0);
	}
	T GetLast() const override
	{
		return (*this->array)[this->GetLength() - 1];
	}
	T& Get(int index) const override//Получить элемент по индексу.
	{
		return (*this->array)[index];
	}
	MutableArraySequence<T>* GetSubsequence(int startIndex, int endIndex) const override//Получить список из всех элементов, начиная с startIndex и заканчивая endIndex.
	{
		MutableArraySequence<T>* result = new MutableArraySequence<T>(endIndex - startIndex + 1);
		for (int i = 0; i < result->GetLength(); i++)
		{
			result->array->Set(i, this->Get(i + startIndex));
		}
		return result;
	}
	int GetLength() const override//Получить длину списка
	{
		return this->array->GetSize();
	}
	void Append(const T& item) override//Добавляет элемент в конец списка
	{
		this->array->Append(item);
	}
	//void Prepend(const T& item) override//Добавляет элемент в начало списка
	//{
	//	this->array->Prepend(item);
	//}
	//void InsertAt(int index, const T& item) override//Вставляет элемент в заданную позицию
	//{
	//	this->array->InsertAt(index, item);
	//}
	void Prepend(const T& item)
	{
		MutableArraySequence<T>* result = new MutableArraySequence<T>(this->GetLength() + 1);
		result->array->Set(0, item);
		for (int i = 0; i < this->GetLength(); i++)
		{
			result->array->Set(i + 1, this->array->Get(i));
		}
		this->array = result->array;
	}
	void InsertAt(int index, const T& item)
	{
		MutableArraySequence<T>* result = new MutableArraySequence<T>(this->GetLength() + 1);
		for (int i = 0; i < index; i++)
		{
			result->array->Set(i, this->array->Get(i));
		}
		result->array->Set(index, item);
		for (int i = index; i < this->GetLength(); i++)
		{
			result->array->Set(i + 1, this->array->Get(i));
		}
		this->array = result->array;
	}
	MutableArraySequence<T>* Concat(const Sequence<T>& other) const //Сцепляет два списка
	{
		MutableArraySequence<T>* result = new MutableArraySequence<T>(*this);
		for (int i = 0; i < other.GetLength(); i++)
		{
			result->array->Append(other.Get(i));
		}
		return result;
	}
	void Set(int index, const T& item) override
	{
		(*array)[index] = item;
	}
	void Resize(int newSize)
	{
		if (newSize < 0) throw std::out_of_range("New size is invalid\n");
		this->array->Resize(newSize);
	}
};