#include "StoreItem.h"

StoreItem::StoreItem(unsigned int Calories, double Price):calories(Calories), price(Price), type(DEFAULT)
{}

StoreItem::~StoreItem()
{}

unsigned int StoreItem::getCalories() const
{
	return calories;
}

unsigned int StoreItem::getPrice() const
{
	return price;
}

ItemType StoreItem::getType() const
{
	return type;
}

void StoreItem::setCalories(unsigned int Calories)
{
	calories = Calories;
}

void StoreItem::setPrice(double Price)
{
	price = Price;
}
