#pragma once
#include <stdexcept>
#include <iostream>

using namespace std;

template<typename T>
class Array
{
public:
	explicit Array(size_t length);
	~Array();

	void insert(T item);
	void print();
private:
	T* items;
	int count;
	int capacity;
	T& operator[](size_t index);

	void resize();
	bool isFull();
};

template<typename T>
Array<T>::Array(size_t length)
{
	items = new T[length];
	this->capacity = length;
	this->count = 0;
}

template<typename T>
Array<T>::~Array()
{
	delete[] items;
	items = nullptr;
}

template<typename T>
inline void Array<T>::insert(T item)
{
	if (isFull())
		resize();

	items[count] = item;
	count++;
}

template<typename T>
inline void Array<T>::print()
{
	for (int i = 0; i < count; i++)
	{
		cout << items[i] << endl;
	}
}

template<typename T>
T& Array<T>::operator[](size_t index)
{
	if (index >= count)
		throw std::invalid_argument("index");

	return items[index];
}


template<typename T>
inline void Array<T>::resize()
{
	int* newArray = new T[count * 2];

	for (int i = 0; i < count; i++)
		newArray[i] = items[i];

	delete[] items;
	items = newArray;
}

template<typename T>
inline bool Array<T>::isFull()
{
	return capacity == count;
}

