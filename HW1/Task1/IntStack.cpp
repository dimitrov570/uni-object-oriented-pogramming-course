#include "IntStack.h"


IntStack::IntStack()
{
	top = nullptr;
}

IntStack::IntStack(IntStack & copyFrom)
{
	copyStack(copyFrom);
}

bool IntStack::isEmpty() const
{
	return (top==nullptr);
}

int IntStack::peek() const
{
	if (isEmpty())
	{
		std::cout << "The stack is empty!";
		return -1;
		std::cout << std::endl;
	}
	return top->value;
}

void IntStack::push(int Value)
{
	StackElement* newElement = new StackElement;
	(*newElement).value = Value;
	(*newElement).previous = top;
	top = newElement;
}

int IntStack::pop()
{
	if (isEmpty())
	{
		std::cout << "The stack is empty!" << std::endl;
		return -1; //The value of an element can be -1, but the message above prevents such a confusion
	}

	int value = peek(); //Need to save the value before deleting the last element
	StackElement* last = top;
	top=(*top).previous;
	delete last;
	return value;

}

void IntStack::unload()
{
	while (top != nullptr)
	{
		pop();
	}
}

void IntStack::copyStack(const IntStack & copyFrom)
{
	top = nullptr;
	StackElement* helper = copyFrom.top;
	IntStack storage; //Place for storing elements of copyFrom in reverse

	//Filling storage 
	while (helper != nullptr)
	{
		storage.push((*helper).value);
		helper = (*helper).previous;
	}

	//Writing elements of storage in destination stack
	while (!storage.isEmpty())
	{
		push(storage.pop());
	}
}

IntStack & IntStack::operator=(const IntStack & object)
{
	if (this != &object)
	{
		unload();
		copyStack(object);
	}

	return *this;
}

void IntStack::print() const
{
	//Helper pointer to access all the elements without changing the original pointer
	StackElement* helper = top;
	int i = 1;

	std::cout << "Printing from TOP to BOTTOM: " << std::endl;

	while (helper!=nullptr)
	{
		std::cout << "Element " << i++ << " - " << (*helper).value << std::endl;
		helper = (*helper).previous;
	}
}


int IntStack::sizeOfStack()
{
	//Making copy of original object (tmp) to assure that original object is untouched
	IntStack tmp = *this;
	int counter = 0;
	while (tmp.top != nullptr)
	{
		tmp.pop();
		++counter;
	}
	return counter;
}


IntStack::~IntStack()
{
	unload();
}
