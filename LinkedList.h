#pragma once

#include <iostream>
#include <stdexcept>
#include "Sequence.h"

template <typename T> class LinkedList
{
public:
	class Element
	{
	public:
		T element{};
		Element* next{};
		Element() : next(nullptr) {}
		Element(T element) : next(nullptr), element(element) {}
	};
private:
	Element* head = nullptr;
	Element* tail = nullptr;
	int size = 0;

	Element& getElement(int index) const//получить полный доступ к i-му элементу, сделать приватной!!!!
	{
		if (index < 0 || index >= size) throw std::out_of_range("Index is out of range");
		Element* current = this->head;
		for (int i = 0; i < index; i++)
		{
			current = current->next;
		}
		return *current;
	}

	void deleteList()
	{
		Element* current = this->head;
		while (current != 0)
		{
			current = current->next;
			delete this->head;
			this->head = current;
		}
		delete this->head;
	}
public:
	LinkedList(const T* other, int size)//Копировать элементы из переданного массива
	{
		if (size < 0) throw std::out_of_range("Invalid size\n");
		for (int i = 0; i < size; i++)
		{
			this->Append(other[i]);
		}
	}
	LinkedList()//Создать пустой список
	{

	}
	LinkedList(const LinkedList<T>& other)//Копирующий конструктор
	{
		//Element* current = other.head;
		//while (current != nullptr) {
		//	// do something with current->element
		//	current = current->next;
		//}
		/*for (int i = 0; i < other.GetLength; i++)
		{
			this->Append(other[i]);
		}*/
		for (Element* current = other.head; current != nullptr; current = current->next) {
			// do something with current->element
			this->Append(current->element);
		}
	}
	LinkedList(int size)
	{
		if (size < 0) throw std::out_of_range("Size is invalid\n");
		if (size > 0)
		{
			head = new Element;
			this->tail = this->head;
		}
		for (int i = 0; i < size; i++)
		{
			this->tail->next = new Element;
			this->tail = this->tail->next;
		}
		this->size = size;
	}
	~LinkedList()
	{
		deleteList();
	}
	T GetFirst() const//Получить первый элемент в списке
	{
		if (this->head == NULL || this->size < 0) throw std::out_of_range("The list is empty\n");
		//return head->element;
		Element* current = this->head;
		return current->element;
	}
	T GetLast() const//Получить последний элемент в списке
	{
		if (this->head == NULL || this->size < 0) throw std::out_of_range("The list is empty\n");
		Element* current = this->tail;
		return current->element;
	}
	T& operator[](int index) {
		return getElement(index).element;
	}
	const T& operator[](int index) const {
		return getElement(index).element;
	}
	T Get(int index) const//Получить элемент по индексу.
	{
		if (this->head == NULL || this->size < 0) throw std::out_of_range("The list is empty\n");
		return const_cast<T&>((const_cast<LinkedList<T>&>(*this))[index]);
	}
	LinkedList<T>* GetSubList(int startIndex, int endIndex)//Получить список из всех элементов, начиная с startIndex и заканчивая endIndex.
	{
		if (this->size < 0 || endIndex < 0 || startIndex < 0 || endIndex >= this->size || startIndex >= this->size || startIndex > endIndex) throw std::out_of_range("Index out of range\n");
		LinkedList<T>* newList = new LinkedList<T>;
		Element* current = &getElement(startIndex);
		for (int i = startIndex; i <= endIndex; i++)
		{
			newList->Append(current->element);
			current = current->next;
		}
		return newList;
		/*for (int i = startIndex; i < endIndex; i++)
		{
			newList->Append(this[i]);
		}
		return newList;*/
	}
	void Append(const T& item)//Добавляет элемент в конец списка
	{
		if (this->size == 0)
		{
			this->head = new Element(item);
			this->tail = this->head;
			this->size += 1;
		}
		else
		{
			this->tail->next = new Element(item);
			this->tail = this->tail->next;
			this->size += 1;
		}
	}
	void Prepend(const T& item)//Добавляет элемент в начало списка
	{
		if (this->size == 0)
		{
			this->head = new Element(item);
			this->tail = this->head;
		}
		else
		{
			this->size += 1;
			Element* buf = new Element(item);
			buf->next = this->head;
			this->head = buf;
		}
	}

	void InsertAt(int index, T item)//Вставляет элемент в заданную позицию
	{
		if (index < 0 || index > this->GetLength()) throw std::out_of_range("Index is invalid\n");
		if (index == 0)
		{
			this->Prepend(item);
		}
		else if (index == this->size)
		{
			this->Append(item);
		}
		else
		{
			Element* buf = new Element(item);
			buf->next = &getElement(index);
			getElement(index - 1).next = buf;
			this->size += 1;
		}
	}
	LinkedList<T>* Concat(LinkedList<T>* other)//Сцепляет два списка
	{
		LinkedList<T>* newList = new LinkedList<T>(*this);
		for (int i = 0; i < other->GetLength(); i++)
		{
			newList->Append(other->Get(i));
		}
		return newList;
	}
	int GetLength()
	{
		if (this->size < 0) throw std::out_of_range("Size is invalid");
		return this->size;
	}
	void Set(int index, const T& value)
	{
		if (index < 0 || index > this->GetLength()) throw std::out_of_range("Index is invalid\n");
		(*this)[index] = value;
	}

};