#pragma once

#include "Sequence.h"

template <class T> class ImmutableSequence: public Sequence<T>
{
public:
	virtual ~ImmutableSequence() = default;
	virtual ImmutableSequence<T>* Append(const T& item) const = 0;
	virtual ImmutableSequence<T>* Prepend(const T& item) const = 0;
	virtual ImmutableSequence<T>* InsertAt(int index, const T& item) const = 0;
	virtual ImmutableSequence<T>* Set(int index, const T& item) const = 0;
};