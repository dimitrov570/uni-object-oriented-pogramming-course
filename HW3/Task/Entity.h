#pragma once
#include <string>
#include "Point2D.h"
#include "Point3D.h"

	enum class EntityType
	{
		player,
		npc,
		mob,
		def
	};

class Entity
{

protected:
	int id;
	std::string name;
	Point2D* location;
	EntityType type;

	int generateId();

public:

	Entity(const std::string Name = "", Point2D* Location = &Point2D(0, 0));
	Entity(const Entity & obj);
	Entity & operator=(const Entity & obj);
	virtual ~Entity() = 0;

	Point2D* getLocation() const;
	virtual bool isAlive() const;
	double getDistanceTo2D(const Entity * entity) const;
	double getDistanceTo(const Entity * entity) const;
	EntityType getType() const;

	void moveTo(Point2D Location);
	void moveTo(Point3D Location);
	void moveTo(Entity * entity);
};