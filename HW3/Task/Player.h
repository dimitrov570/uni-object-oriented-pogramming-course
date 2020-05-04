#pragma once
#include "Entity.h"
#include "Mob.h"

class Player: public Entity
{
	friend class Mob;

private:
	int damage;
	int health;

public:
	Player(const std::string Name = "", Point2D* Location = nullptr ,  int Damage = 0, int Health = 0);
	Player(const Player & obj);

	bool isAlive() const;

	void attack(Player * player);
	void attack(Mob * mob);
};