#pragma once

#include <iostream>
#include <stdexcept>
#include "Sequence.h"

#include "LinkedList.h"

template <class T> class DynamicArray
{
private:
	int size = 0;
	T* array = nullptr;

public:
	DynamicArray()
	{
		this->size = 0;
		this->array = new T[this->size];
	}
	DynamicArray(int size, T value)
	{
		if (size < 0) throw std::out_of_range("Invalid size\n");
		this->array = new T[size];
		this->size = size;
		std::cout << this->size;
		for (int i = 0; i < this->size; i++)
		{
			array[i] = value;
		}
	}
	DynamicArray(const T* items, int size)//Копировать элементы из переданного массива
	{
		/*int a = 1;
		int* ptra = &a;
		int* ptrb = new int;
		int* ptrc = new int[100500];
		ptra = ptrc;
		delete[] ptra;
		*/
		//T instance;
		//T* ptr = new T;
		//delete ptr;
		//T array3[100500];
		/*T* array4 = new T[100500];
		delete [] array4;*/
		if (size < 0) throw std::out_of_range("Invalid size\n");
		array = new T[size];
		for (int i = 0; i < size; i++) {
			array[i] = items[i];
		}
		this->size = size;
	}
	DynamicArray(int size)//Создать массив заданной длины
	{
		if (size < 0) throw std::out_of_range("Invalid size\n");
		this->array = new T[size];
		this->size = size;
	}
	DynamicArray(const DynamicArray<T> &other)//Копирующий конструктор
	{
		/*T* ptr1;
		const T* ptr2;
		T* const ptr3;
		const T* const ptr4;*/
		/*T a;
		T* ptr = &a;
		T& ref = a;
		cout << a;
		cout << (*ptr);
		cout << ref;*/
		this->size = other.size;
		/*int size1 = dynamicArray.size;*/
		this->array = new T[size];
		for (int i = 0; i < size; i++)
		{
			this->array[i] = other.array[i];
		}
	}
	~DynamicArray()
	{
		delete[] this->array;
	}
	T& operator[](int index)
	{
		if (index < 0 || index >= this->size) throw std::out_of_range("Index is invalid");
		return array[index];
	}
	T Get(int index) const//Получить элемент по индексу.
	{
		if (index < 0 || index >= this->size) throw std::out_of_range("Index out of range\n");
		return (this->array)[index];
	}
	int GetSize()//Получить размер массива
	{
		if (size < 0) throw std::out_of_range("Invalid size\n");
		return this->size;
	}
	void Set(int index, const T& value)//Задать элемент по индексу
	{
		if (index < 0 || index > this->size) throw std::out_of_range("Index out of range\n");
		this->array[index] = value;
	}
	void Resize(int newSize)//Изменить размер массива.
	{
		if (newSize < 0) throw std::out_of_range("Invalid size");
		int size1 = 0;
		if (newSize > size) 
		{
			size1 = this->size;
		}
		else 
		{
			size1 = newSize;
		}
		//newArray = new T[size1];
		/*	T* array1 = new T[size3];
		T array2[] = new T[size3];
		T instance*/
		T* newArray = new T[newSize];
		for (int i = 0; i < size1; i++)
		{
			newArray[i] = this->array[i];
		}

		delete[] this->array;
		this->array = newArray;
		this->size = newSize;
	}
	void Append(const T& value)//добавить элемент в конец списка
	{
		this->Resize(this->GetSize() + 1);
		array[size - 1] = value;
	}
};