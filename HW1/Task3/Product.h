#pragma once
#include <iostream>
#define _CRTDBG_MAP_ALLOC
#include <cstdlib> 
#include <crtdbg.h> 
#ifdef _DEBUG 
#define new new ( _NORMAL_BLOCK , __FILE__ , __LINE__ ) 
#endif 

//Choosen product is car
class Product 
{
	unsigned int SKU;
	char* Brand;
	char* Model;
	char* Category;
	char* Color;
	unsigned int Price;
	unsigned int Count;

public: 

	Product(unsigned int sku = 0, const char* brand = "", const char* model = "", const char* category = "",
			const char* color = "", unsigned int price = 0, unsigned int count = 0);
	Product(const Product & copyFrom);

	Product & operator=(const Product & object);

	unsigned int getSKU() const;
	const char* getBrand() const;
	const char* getModel() const;
	const char* getCategory() const;
	const char* getColor() const;
	unsigned int getPrice() const;
	unsigned int getCount() const;

	void setSKU(unsigned int sku);
	void setBrand(const char* brand);
	void setModel(const char* model);
	void setCategory(const char* category);
	void setColor(const char* color);
	void setPrice(unsigned int price);
	void setCount(unsigned int count);
	
	friend std::istream & operator>>(std::istream & stream, Product & product);
	friend std::ostream & operator<<(std::ostream & stream, const Product & product);

	friend bool operator==(Product & product1, Product & product2);

	friend bool compareNames(const char* name1, const char* name2);

	friend void copy(Product & product1,const Product & product2);

	~Product();
};