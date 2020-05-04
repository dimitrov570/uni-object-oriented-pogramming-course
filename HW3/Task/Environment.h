#pragma once
#include "Entity.h"
#include "Player.h"
#include "Mob.h"
#include "NPC.h"
#include <vector>
#include <iostream>

class Environment
{
private:
	std::vector<Entity*> entities;

public:
	Environment(int numberOfEntities = 0); //numberOfEntities == how much entities to be generated at the beginning
	~Environment();

	void add(Entity* entity);
	Entity* getAt(int index); //const?
	void removeAt(int index);
	void generateEntities(int numberOfEntities);
	void destroyEntities();
	Entity* getClosestAliveEntity(const Player & player, EntityType Type) const;
	void sortByDistanceTo(Entity* entity); //sorts the whole Environment from closest to furthest from given *entity

	int size() const;

private:

};