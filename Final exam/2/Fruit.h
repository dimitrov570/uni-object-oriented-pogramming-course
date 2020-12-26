#pragma once
#include "StoreItem.h"
#include "string"
#include <iostream>

class Fruit: public StoreItem
{
public:
	Fruit(unsigned int Calories = 0, double Price = 0, const std::string Name = "", const std::string Colour = "");

	bool operator>(const Fruit & obj);

	std::string getName();
	void setName(const std::string Name = "");
	void setColour(const std::string Colour = "");
	void print() override;

private:
	std::string fruitName;
	std::string fruitColour;
};