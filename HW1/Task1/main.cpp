#include <iostream>
#include "IntStack.h"
#include "mainFunctions.h"

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	IntStack stack;
	fillStack(stack);
	stack.print();

	std::cout << std::endl;

	std::cout << "Sorted stack: " << std::endl;

	sortStack(stack);

	stack.print();

	return 0;
}