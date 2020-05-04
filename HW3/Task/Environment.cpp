#include "Environment.h"

Environment::Environment(int numberOfEntities)
{
	generateEntities(numberOfEntities);
}

Environment::~Environment()
{
	destroyEntities();
}

void Environment::add(Entity * entity)
{
	Player* castToPlayer = dynamic_cast<Player*>(entity);
	if (castToPlayer != nullptr)
	{
		Entity* tmp = new Player(*castToPlayer);
		entities.push_back(tmp);
		return;
	}

	Mob* castToMob = dynamic_cast<Mob*>(entity);
	if (castToMob != nullptr)
	{
		Entity* tmp = new Mob(*castToMob);
		entities.push_back(tmp);
		return;
	}

	NPC* castToNPC = dynamic_cast<NPC*>(entity);
	if (castToNPC != nullptr)
	{
		Entity* tmp = new NPC(*castToNPC);
		entities.push_back(tmp);
		return;
	}
}

Entity * Environment::getAt(int index)
{
	if (index<0 || index> entities.size())
	{
		return nullptr;
	}
	return entities.at(index);
}

void Environment::removeAt(int index)
{
	if (index<0 || index> entities.size())
	{
		return;
	}
	delete entities.at(index);
	std::vector<Entity*>::iterator it = entities.begin() + index;

	entities.erase(it);
}

void Environment::generateEntities(int numberOfEntities)
{
	int i = 0;
	while (i < numberOfEntities)
	{
		//every time it gets in the scope it generates new Entity* objects in the heap and stores their addresses in the vector
		Entity* player = new Player;
		entities.push_back(player);
		if (i >= numberOfEntities)
		{
			break;
		}

		Entity* mob = new Mob;
		entities.push_back(mob);
		if (i >= numberOfEntities)
		{
			break;
		}

		Entity* npc = new NPC;
		entities.push_back(npc);
		if (i >= numberOfEntities)
		{
			break;
		}
	}
}

void Environment::destroyEntities()
{
	for (int i = entities.size() - 1; i >= 0; --i)
	{
		delete entities.at(i);
		entities.pop_back();
	}
}

Entity * Environment::getClosestAliveEntity(const Player & player, EntityType Type) const
{
	int minInd = 0; //Index of minimum remote entity*
	//finding first entity* that is alive and matches Type
	while (!entities.at(minInd)->isAlive() || entities.at(minInd)->getType() != Type || minInd >= entities.size())
	{
		++minInd;
	}

	for (int i = minInd; i < entities.size(); i++) //checking if there's another entity* of the same type closer to the player
	{
		if (!entities.at(i)->isAlive() || entities.at(i)->getType() != Type)
		{
			continue;
		}
		else if (entities.at(i)->getDistanceTo(&player) < entities.at(minInd)->getDistanceTo(&player))
		{
			minInd = i;
		}
	}

	if (entities.at(minInd)->isAlive() && entities.at(minInd)->getType() == Type) //Last check
	{
		return entities.at(minInd);
	}
	return nullptr;
}

void Environment::sortByDistanceTo(Entity * entity)
{
	for (size_t i = 0; i < entities.size(); i++)
	{
		size_t minInd = i;

		for (size_t j = i + 1; j < entities.size(); j++)
		{
			if (getAt(j)->getDistanceTo(entity) < getAt(minInd)->getDistanceTo(entity))
			{
				minInd = j;
			}
		}
		
		//swapping two elements of a vector
		std::vector<Entity*>::iterator it1 = entities.begin() + i;
		std::vector<Entity*>::iterator it2 = entities.begin() + minInd;
		std::iter_swap(it1, it2);
	}
}

int Environment::size() const
{
	return entities.size();
}
