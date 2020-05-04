#pragma once 
#include <iostream>
#include <ctime>

const int INITIAL_SIZE = 8;
const int EXPAND_FACTOR = 2;

template <class T>
class MagicBox
{
	T* elements;
	int size;
	int numberOfElements;

public:

	MagicBox();
	MagicBox(const MagicBox & copyFrom);
	MagicBox & operator=(const MagicBox & object);

	void insert(T element);
	T pop();
	void list();

	void resize();

	bool isFull();
	bool isEmpty();

	~MagicBox();
};


template <class T>
MagicBox<T>::MagicBox() :size(INITIAL_SIZE), numberOfElements(0)
{
	elements = new T[size];
}


template <class T>
MagicBox<T>::MagicBox(const MagicBox & copyFrom) : size(copyFrom.size), numberOfElements(copyFrom.numberOfElements)
{
	elements = new T[size];
	for (int i = 0; i < numberOfElements; ++i)
	{
		elements[i] = copyFrom.elements[i];
	}
}

template <class T>
MagicBox<T> & MagicBox<T>::operator=(const MagicBox & object)
{
	if (this != &object)
	{
		size = object.size;
		numberOfElements = object.numberOfElements;

		delete[] elements;

		elements = new T[size];
		for (int i = 0; i < numberOfElements; ++i)
		{
			elements[i] = object.elements[i];
		}

	}
	return *this;
}

template <class T>
void MagicBox<T>::insert(T element)
{
	if (isFull())
	{
		resize();
	}
	elements[numberOfElements++] = element;
}

template <class T>
T MagicBox<T>::pop()
{
	if (isEmpty())
	{
		std::cout << "The Box is empty! \n";
		return NULL;
	}
	srand(time(0)); //seeding random function
	int randomIndex = rand() % numberOfElements;

	T randomElement = elements[randomIndex];

	//extracting random selected element from the list
	for (int i = randomIndex; i < numberOfElements - 1; ++i)
	{
		elements[i] = elements[i + 1];
	}
	--numberOfElements;
	return randomElement;
}

template <class T>
void MagicBox<T>::list()
{
	for (int i = 0; i < numberOfElements; ++i)
	{
		std::cout << i + 1 << ". element: " << elements[i] << '\n';
	}
}

template <class T>
void MagicBox<T>::resize()
{
	int new_size = size * EXPAND_FACTOR;
	T* tmp = new T[new_size];
	for (int i = 0; i < size; ++i)
	{
		tmp[i] = elements[i];
	}
	delete[] elements;
	elements = tmp;
	size = new_size;
}

template <class T>
bool MagicBox<T>::isFull()
{
	if (size == numberOfElements)
	{
		return true;
	}

	return false;
}

template <class T>
bool MagicBox<T>::isEmpty()
{
	if (numberOfElements == 0)
	{
		return true;
	}
	return false;
}

template <class T>
MagicBox<T>::~MagicBox()
{
	delete[] elements;
}