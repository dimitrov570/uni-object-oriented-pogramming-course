#pragma once
#include <iostream>
#define _CRTDBG_MAP_ALLOC
#include <cstdlib> 
#include <crtdbg.h> 
#ifdef _DEBUG 
#define new new ( _NORMAL_BLOCK , __FILE__ , __LINE__ ) 
#endif 

struct StackElement
{
	int value;
	StackElement * previous;
};

class IntStack
{
	StackElement* top;

public: 

	IntStack();

	IntStack(IntStack & copyFrom);

	bool isEmpty() const;

	int peek() const;

	void push(int Value);

	int pop();

	void unload();

	//Function for copy constructor and operator=
	void copyStack(const IntStack & copyFrom);

	IntStack & operator=(const IntStack & object);

	void print() const;

	int sizeOfStack();

	~IntStack();

};