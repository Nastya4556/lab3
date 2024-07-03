#pragma once

#include "Sequence.h"

template <class T> class MutableSequence: public Sequence<T>
{
public:
	virtual ~MutableSequence() = default;
	virtual void Append(const T& item) = 0;
	virtual void Prepend(const T& item) = 0;
	virtual void InsertAt(int index, const T& item) = 0;
	virtual void Set(int index, const T& item) = 0;
};



