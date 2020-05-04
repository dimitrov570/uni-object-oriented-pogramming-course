#pragma once
#include "Entity.h"
#include "Player.h"

class Mob:public Entity
{
	friend class Player;

private:
	int damage;
	int health;
	
public:
	Mob(const std::string Name = "", Point2D* Location = nullptr, int Damage = 0, int Health = 0);
	Mob(const Mob & obj);

	bool isAlive() const;
	
	void attack(Player & player);

};