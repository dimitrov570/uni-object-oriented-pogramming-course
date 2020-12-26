#pragma once
#include "StoreItem.h"
#include "string"
#include <iostream>

class Vegetable: public StoreItem
{
public:
	Vegetable(unsigned int Calories = 0, double Price = 0, const std::string Name = "", const std::string VegetableType = "");
	
	bool operator==(const Vegetable & obj);

	std::string getName() const;
	void setName(const std::string Name = "");
	void setVegetableType(const std::string VegetableType = "");
	void print() override;

private:
	std::string vegetableName;
	std::string vegetableType;
};