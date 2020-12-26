#include "Shop.h"

Shop::Shop()
{}

Shop::~Shop()
{
	for (unsigned int i = 0; i < articles.size(); i++)
	{
		delete articles[i];
	}
}

void Shop::addProduct(StoreItem * product)
{
	Fruit* castToFruit = dynamic_cast<Fruit*>(product);
	if (castToFruit != nullptr)
	{
		StoreItem* item = new Fruit(*castToFruit);
		articles.push_back(item);
	}

	Vegetable* castToVegetable = dynamic_cast<Vegetable*>(product);
	if (castToVegetable != nullptr)
	{
		StoreItem* item = new Vegetable(*castToVegetable);
		articles.push_back(item);
	}
}

void Shop::removeProduct(unsigned int index)
{
	if ((index >= 0) && (index < articles.size()))
	{
		articles.erase(articles.begin() + index);
		return;
	}
	std::cout << "Such product does not exist! \n";
}

void Shop::setPriceOfProduct(unsigned int index, double Price)
{
	if ((index >= 0) && (index < articles.size()))
	{
		articles[index]->setPrice(Price);
		return;
	}
	std::cout << "Such product does not exist! \n";
}

void Shop::setNameOfProduct(unsigned int index, const std::string Name)
{
	if ((index >= 0) && (index < articles.size()))
	{
		Fruit* castToFruit = dynamic_cast<Fruit*>(articles[index]);
		if (castToFruit != nullptr)
		{
			castToFruit->setName(Name);
		}

		Vegetable* castToVegetable = dynamic_cast<Vegetable*>(articles[index]);
		if (castToVegetable != nullptr)
		{
			castToVegetable->setName(Name);
		}
		return;
	}
	std::cout << "Such product does not exist! \n";
}

void Shop::print()
{
	for (unsigned int i = 0; i < articles.size(); i++)
	{
		std::cout << "Article " << i + 1 << ". " << '\n';
		articles[i]->print();
		std::cout << std::endl;
	}
}

void Shop::getProductWithMostCalories()
{
	unsigned int maxInd = 0;//finding the index of that product
	for (unsigned int i = 1; i < articles.size(); i++)
	{
		if (articles[maxInd] < articles[i])
		{
			maxInd = i;
		}
	}

	articles[maxInd]->print();
}
