#include "Player.h"

Player::Player(const std::string Name, Point2D* Location,  int Damage, int Health) :Entity(Name, Location), damage(Damage), health(Health)
{
	type = EntityType::player;
}

Player::Player(const Player & obj) : Entity(obj.name, obj.location), damage(obj.damage), health(obj.health)
{
	type = EntityType::player;
}

bool Player::isAlive() const
{
	if (health > 0)
	{
		return true;
	}
	return false;
}

void Player::attack(Player * player)
{
	if (getDistanceTo(player) < 5)
	{
		player->health -= damage;
	}
}

void Player::attack(Mob * mob)
{
	if (getDistanceTo(mob) < 5)
	{
		mob->health -= damage;
	}
}