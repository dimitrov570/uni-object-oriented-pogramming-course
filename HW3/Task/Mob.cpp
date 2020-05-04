#include "Mob.h"

Mob::Mob(const std::string Name, Point2D* Location, int Damage, int Health) :Entity(Name, Location), damage(Damage), health(Health)
{
	type = EntityType::mob;
}

Mob::Mob(const Mob & obj) : Entity(obj.name, obj.location), damage(obj.damage), health(obj.health)
{
	type = EntityType::mob;
}

bool Mob::isAlive() const
{
	if (health > 0)
	{
		return true;
	}
	return false;
}

void Mob::attack(Player & player)
{
	if (getDistanceTo(&player) < 5)
	{
		player.health -= damage;
	}
}
