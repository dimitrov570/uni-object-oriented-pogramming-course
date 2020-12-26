#pragma once
#include "StoreItem.h"
#include "Fruit.h"
#include "Vegetable.h"
#include <vector>

class Shop
{
public:
	Shop();
	~Shop();

	void addProduct(StoreItem * product);
	void removeProduct(unsigned int index);
	void setPriceOfProduct(unsigned int index, double Price);
	void setNameOfProduct(unsigned int index, const std::string Name);
	void print();
	void getProductWithMostCalories();

private:
	std::vector<StoreItem*> articles;
};