#include <iostream>
#include "Warrior.h"
#include "Guardian.h"
#include "Wizard.h"


int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);


	Warrior war1;
	Wizard wiz1;
	Guardian guard1;

	war1.getAttacked(19);
	war1.getAttacked(250);

	wiz1.getAttacked(2);
	wiz1.getAttacked(15);

	guard1.getAttacked(2);
	guard1.getAttacked(20);

	return 0;
}