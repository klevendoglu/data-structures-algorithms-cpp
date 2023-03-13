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
	void insertAt(T item, int indexFrom);
	void removeAt(int indexFrom);
	void reverse();
	void print();

	int indexOf(T item);
	int max();
	T* intersect(T* items, size_t size);
private:
	T* items;
	int count;
	int capacity;
	T& operator[](size_t index);

	void resize();
	void shift(int index);
	bool isFull();
	bool isOutOfRange(int index);
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

//O(n) operation.
template<typename T>
inline void Array<T>::insertAt(T item, int indexFrom)
{
	if (isOutOfRange(indexFrom))
		throw std::invalid_argument("indexFrom");

	if (isFull())
		resize();

	for (int i = count - 1; i >= indexFrom; i--)
	{
		items[i + 1] = items[i];
	}

	items[indexFrom] = item;
	count++;
}

template<typename T>
inline int Array<T>::indexOf(T item)
{
	for (int i = 0; i < count; i++)
		if (items[i] == item) return i;

	return -1;
}

template<typename T>
inline int Array<T>::max()
{
	if (count == 0)
		throw "there's no items!";

	auto max = 0;
	for (int i = 0; i < count; i++)
		if (items[i] > max) max = items[i];

	return max;
}

template<typename T>
inline T* Array<T>::intersect(T* itemsToIntersect, size_t size)
{
	Array<T> intersection{ size };

	for (int i = 0; i < size; i++)
	{
		if (indexOf(itemsToIntersect[i]) >= 0)
			intersection.insert(itemsToIntersect[i]);
	}

	cout << "intersection:" << endl;
	intersection.print();

	return intersection.items;
}

template<typename T>
inline void Array<T>::reverse()
{
	//Array<T> reversed{ sizeof(count - 1) / sizeof(int) };
	int* reversed = new T[count];

	//for (int i = count - 1; i >= 0; i--)
	//{
	//	//reversed.insert(items[i]);
	//	reversed[i] = items[i];
	//}

	for (int i = 0; i < count; i++)
		reversed[i] = items[count - i - 1];

	cout << "reversed:" << endl;
	delete[] items;
	items = reversed;
}

template<typename T>
inline void Array<T>::removeAt(int index)
{
	if (isOutOfRange(index))
		throw std::invalid_argument("index");

	shift(index);

	count--;
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

//O(n) operation.
template<typename T>
inline void Array<T>::resize()
{
	int* newArray = new T[count * 2];

	for (int i = 0; i < count; i++)
		newArray[i] = items[i];

	delete[] items;
	items = newArray;
}

//O(n) operation.
template<typename T>
inline void Array<T>::shift(int indexFrom)
{
	for (int i = indexFrom; i < count; i++)
	{
		items[i] = items[i + 1];
	}
}

//O(1) operation.
template<typename T>
inline bool Array<T>::isFull()
{
	return capacity == count;
}

template<typename T>
inline bool Array<T>::isOutOfRange(int index)
{
	return index < 0 || index >= count;
}

