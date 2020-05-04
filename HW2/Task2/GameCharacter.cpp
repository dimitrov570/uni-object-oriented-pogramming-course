#include "GameCharacter.h"

GameCharacter::GameCharacter(const char * name, int hp, int mp, int ap, int dp): HP(hp), MP(mp), AP(ap), DP(dp)
{
	if (name != nullptr)
	{
		Name = new char[strlen(name) + 1];
		strcpy(Name, name);
	}
}

GameCharacter::GameCharacter(const GameCharacter & copyFrom) : HP(copyFrom.HP), MP(copyFrom.MP), AP(copyFrom.AP), DP(copyFrom.DP)
{
	delete[] Name;
	Name = new char[strlen(copyFrom.Name) + 1];
	strcpy(Name, copyFrom.Name);
}

GameCharacter & GameCharacter::operator=(const GameCharacter & copyFrom)
{
	if (this != &copyFrom)
	{
		if (copyFrom.Name != nullptr)
		{
			delete[] Name;
			Name = new char[strlen(copyFrom.Name) + 1];
			strcpy(Name, copyFrom.Name);
		}
		HP = copyFrom.HP;
		MP = copyFrom.MP;
		AP = copyFrom.AP;
		DP = copyFrom.DP;
	}
	return *this;
}

void GameCharacter::getattacked(int points)
{
	if (points <= 0)
	{
		return;
	}
	else if (points <= DP)
	{
		DP -= points;
		return;
	}

	HP -= abs(DP - points);

	DP = 0; 

	if (HP < 0)
	{
		HP = 0;
	}
}

GameCharacter::~GameCharacter()
{
	delete[] Name;
}
