#pragma once
#include <iostream>

class GameCharacter 
{
	char *Name=nullptr;
	int HP;
	int MP;
	int AP;
	int DP;

public:

	GameCharacter(const char *name, int hp, int mp, int ap, int dp);
	GameCharacter(const GameCharacter & copyFrom);
	GameCharacter & operator=(const GameCharacter & copyFrom);

	void getAttacked(int points);

	//making destructor pure virtual fucntion so that GameCharacter object can't be created
	virtual ~GameCharacter() = 0;

};