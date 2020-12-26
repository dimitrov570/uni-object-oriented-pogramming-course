#pragma once

enum ItemType
{
	FRUIT,
	VEGETABLE,
	DEFAULT
};

class StoreItem
{
public:
	StoreItem(unsigned int Calories = 0, double Price = 0);
	virtual ~StoreItem() = 0;

	unsigned int getCalories() const;
	unsigned int getPrice() const;
	ItemType getType() const;
	void setCalories(unsigned int Calories);
	void setPrice(double Price);
	virtual void print() = 0; //makes class abstract and allows us to easily print products in the Shop
							  //without casting	every time					
protected:
	ItemType type;
	unsigned int calories;
	double price;
};