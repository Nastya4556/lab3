#pragma once
#include <iostream>

template <class T> class Sequence
{
public:
	virtual ~Sequence() = default;
	virtual T GetFirst() const = 0;
	virtual T GetLast() const = 0;
	virtual T& Get(int index) const = 0;
	virtual Sequence<T>* GetSubsequence(int startIndex, int endIndex) const = 0;
	virtual int GetLength() const = 0;
	virtual Sequence<T>* Concat(const Sequence<T>& other) const = 0;
	virtual const T& operator [] (int index) const = 0;
};



