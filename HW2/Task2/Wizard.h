#pragma once
#include "GameCharacter.h"

class Wizard : public GameCharacter
{

public:
	Wizard(const char * name = "Wizard", int hp = 30, int mp = 30, int ap = 2, int dp = 2); //Parameter list in case there is
																							//need for a wizard with different points

private:

};