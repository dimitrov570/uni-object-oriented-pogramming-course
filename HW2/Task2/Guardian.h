#pragma once

#include "GameCharacter.h"

class Guardian : public GameCharacter
{

public:
	Guardian(const char * name = "Guardian", int hp = 40, int mp = 25, int ap = 1, int dp = 3); //Parameter list in case there is 
																								//need for a guardian with different points

private:

};