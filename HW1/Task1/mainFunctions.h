#pragma once
#include <iostream>
#include "IntStack.h"
#define _CRTDBG_MAP_ALLOC
#include <cstdlib> 
#include <crtdbg.h> 
#ifdef _DEBUG 
#define new new ( _NORMAL_BLOCK , __FILE__ , __LINE__ ) 
#endif 

void fillStack(IntStack & stack)
{
	int number;

	//The problem here is that -1 can't be a value for some element
	while (true)
	{
		std::cout << "If you want to stop inserting, insert -1. Please insert a value: ";
		std::cin >> number;
		if (number == -1)
		{
			return;
		}
		stack.push(number);
	}
}

void Sort(int *arr, size_t arrSize)
{
	if (arr == nullptr)
	{
		return;
	}

	for (size_t i = 0; i < arrSize; i++)
	{
		size_t minInd = i;

		for (size_t j = i + 1; j < arrSize; j++)
		{
			if (arr[j] < arr[minInd])
				minInd = j;
		}
		std::swap(arr[i], arr[minInd]);
	}
}

//The idea here is to pop elements of the stack into an array and sort it, then push them back to the stack
IntStack sortStack(IntStack & stack)
{
	int sizeOfStack = stack.sizeOfStack();

	int* storage = new int[sizeOfStack];

	for (int i = 0; i < sizeOfStack; ++i)
	{
		storage[i] = stack.pop();
	}

	Sort(storage, sizeOfStack);

	for (int i = 0; i < sizeOfStack; ++i)
	{
		stack.push(storage[i]);
	}

	delete[] storage;

	return stack;
}