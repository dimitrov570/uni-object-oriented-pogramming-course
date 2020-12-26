#include "Vegetable.h"

Vegetable::Vegetable(unsigned int Calories, double Price, const std::string Name, const std::string VegetableType) :StoreItem(Calories, Price)
{
	vegetableName = Name;
	vegetableType = VegetableType;
	type = VEGETABLE;
}

bool Vegetable::operator==(const Vegetable & obj)
{
	if (this->vegetableType == obj.vegetableType)
	{
		return true;
	}
	return false;
}

std::string Vegetable::getName() const
{
	return vegetableName;
}

void Vegetable::setName(const std::string Name)
{
	vegetableName = Name;
}

void Vegetable::setVegetableType(const std::string VegetableType)
{
	vegetableType = VegetableType;
}

void Vegetable::print()
{
	std::cout << "Vegetable name: " << vegetableName << '\n' << "Vegetable type: " << vegetableType << '\n'
		<< "Vegetable Price: " << price << '\n' << "Vegetable calories: " << calories << '\n';
}