#pragma once
#include "GameCharacter.h"

class Warrior: public GameCharacter
{

public:
	Warrior(const char * name="Warrior", int hp=20, int mp=5, int ap=4, int dp=1); //Parameter list in case there is need for a warrior with different points
	
private:

};
