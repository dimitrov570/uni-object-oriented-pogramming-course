#include "Entity.h"

int Entity::generateId()
{
	static int id = 0;
	return id++;
}

Entity::Entity(const std::string Name, Point2D* Location):id(generateId()), name(Name)
{
	Point3D* castTo3D = dynamic_cast<Point3D*>(Location);
	if (castTo3D != nullptr)
	{
		Point3D* point3D = new Point3D(*castTo3D);
		location = point3D;
	}
	else
	{
		location = new Point2D(*Location);
	}
	type = EntityType::def;
}

Entity::Entity(const Entity & obj):name(obj.name), id(generateId())
{
	location = new Point2D(*obj.location);
}

Entity & Entity::operator=(const Entity & obj)
{
	id = generateId();
	if (this != &obj)
	{
		delete location;
		location = new Point2D(*obj.location);
		name = obj.name;
	}

	return *this;
}

Entity::~Entity()
{
	delete location;
}

Point2D * Entity::getLocation() const
{
	return location;
}

bool Entity::isAlive() const
{
	return true;
}

double Entity::getDistanceTo2D(const Entity * entity) const
{
	return (*location).Point2D::getDistanceTo(*entity->getLocation());
}

double Entity::getDistanceTo(const Entity * entity) const
{
	Point3D *location3D_this = dynamic_cast<Point3D*>(location);
	Point3D *location3D_argument = dynamic_cast<Point3D*>((*entity).getLocation());

	if (location3D_this != nullptr && location3D_argument != nullptr)
	{
		return (*location3D_this).Point3D::getDistanceTo(*location3D_argument);
	}
	else
	{
		return getDistanceTo2D(entity);
	}
}

EntityType Entity::getType() const
{
	return type;
}

void Entity::moveTo(Point2D Location)
{
	location->setCoordinates(&Location); //setCoordinates() does required verification of location types
}

void Entity::moveTo(Point3D Location)
{
	location->setCoordinates(&Location); //setCoordinates() does required verification of location types
}

void Entity::moveTo(Entity * entity)
{
	Point3D* castTo3D = dynamic_cast<Point3D*>(entity->location);
	if (castTo3D != nullptr)
	{
		moveTo(*castTo3D); //goes to moveTo(Point3D Location)
		return;
	}
	moveTo(*(entity->location)); //goes to moveTo(Point2D Location)
}
