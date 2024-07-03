#pragma once
#include "MutableArraySequence.h"
#include <stdexcept>
#include <cmath>

template <typename T> class Vector
{
private:
	T* vec= nullptr;
	int size = 0;
public:
	Vector()
	{
		this->vec = nullptr;
		this->size = 0;
	}
	Vector(int size, const T& value)
	{
		if (size < 0) throw std::out_of_range("Invalid size\n");
		this->size = size;
		this->vec = new T[size];
		for (int i = 0; i < size; i++)
		{
			vec[i] = value;
		}
	}
	Vector(const T* other, int size)
	{
		this->size = size;
		this->vec = new T[size];
		for (int i = 0; i < size; i++)
		{
			vec[i] = other[i];
		}
	}
	Vector(const Vector<T>& other)
	{
		this->size = other.size;
		this->vec = new T[other.size];
		for (int i = 0; i < this->GetSize(); i++)
		{
			this->vec[i] = other.vec[i];
		}
	}
	~Vector()
	{
		delete[] vec;
	}
	T& Get(int index)
	{
		if (index < 0 || index >= this->GetSize()) throw std::out_of_range("Invalid index\n");
		return vec[index];
	}
	T& operator[](int index)
	{
		if (index < 0 || index >= this->GetSize()) throw std::out_of_range("Invalid index\n");
		return vec[index];
	}
	const T& operator[](int index) const
	{
		if (index < 0 || index >= this->GetSize()) throw std::out_of_range("Invalid index\n");
		return vec[index];
	}
	int GetSize() const
	{
		if (this->size < 0) throw std::out_of_range("Invalid size\n");
		return this->size;
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
		T* newVec = new T[newSize];
		for (int i = 0; i < size1; i++)
		{
			newVec[i] = this->vec[i];
		}

		delete[] this->vec;
		this->vec = newVec;
		this->size = newSize;
	}
	void Append(const T& value)//добавить элемент в конец списка
	{
		this->Resize(this->GetSize() + 1);
		vec[this->GetSize() - 1] = value;
	}
	void SumOfVectors(const Vector<T>& other)
	{
		if (other.GetSize() != this->GetSize()) throw std::out_of_range("The sizes of the vectors are different\n");
		T* result = new T[this->GetSize()];
		for (int i = 0; i < this->GetSize(); i++)
		{
			T buf = this->vec[i];
			buf = buf + other[i];
			result[i] = buf;
		}
		delete[] this->vec;
		this->vec = result;
	}
	void MultByScalar(const T& value)
	{
		T* result = new T[this->GetSize()];
		for (int i = 0; i < this->GetSize(); i++)
		{
			T buf = value * this->Get(i);
			result[i] = buf;
		}
		delete[] this->vec;
		this->vec = result;

	}
	double GetNormOfVector()
	{
		double summa = 0;
		for (int i = 0; i < this->GetSize(); i++)
		{
			double buf = this->Get(i) * this->Get(i);
			summa += buf;
		}
		summa = sqrt(summa);
		return summa;
	}
	const T& ScalarProduct(Vector<T>& other)
	{
		if (other.GetSize() != this->GetSize()) throw std::out_of_range("The sizes of the vectors are different\n");
		T result = T();
		for (int i = 0; i < this->GetSize(); i++)
		{
			T buf = this->Get(i) * other[i];
			result = result + buf;
		}
		return result;
	}
};