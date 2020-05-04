#include "MagicBox.hpp"
#include <iostream>

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	MagicBox <double> box;
	box.insert(1.2);
	box.insert(3.58);
	box.insert(7/3.0);
	box.insert(1.25);
	box.insert(5.02);
	box.insert(9/2.0/3.0);
	box.insert(6);
	box.insert(35.32);
	box.insert(21);

	box.list();

	std::cout << '\n' << "Random element: " << box.pop() << "\n\n";

	box.list();

	return 0;
}