#include "Fruit.h"

Fruit::Fruit(unsigned int Calories, double Price, const std::string Name, const std::string Colour):StoreItem(Calories, Price)
{
	fruitName = Name;
	fruitColour = Colour;
	type = FRUIT;
}

bool Fruit::operator>(const Fruit & obj)
{
	if (this->getCalories() > obj.getCalories())
	{
		return true;
	}
	return false;
}

std::string Fruit::getName()
{
	return fruitName;
}

void Fruit::setName(const std::string Name)
{
	fruitName = Name;
}

void Fruit::setColour(const std::string Colour)
{
	fruitColour = Colour;
}

void Fruit::print()
{
	std::cout << "Fruit name: " << fruitName << '\n' << "Fruit colour: " << fruitColour << '\n'
		<< "Fruit Price: " << price << '\n' << "Fruit calories: " << calories << '\n';;
}
