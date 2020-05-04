#pragma once
#include "Entity.h"

class NPC: public Entity
{
public:
	NPC(const std::string Name = "", Point2D* Location = nullptr);
	NPC(const NPC & obj);

	bool isAlive() const;
};