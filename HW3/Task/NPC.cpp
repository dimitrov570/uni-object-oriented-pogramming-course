#include "NPC.h"

NPC::NPC(const std::string Name, Point2D * Location) : Entity(Name, Location)
{
	type = EntityType::npc;
}

NPC::NPC(const NPC & obj) : Entity(obj.name, obj.location)
{
	type = EntityType::npc;
}

bool NPC::isAlive() const
{
	return true;
}
