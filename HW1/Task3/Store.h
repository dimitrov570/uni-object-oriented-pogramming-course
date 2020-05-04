#pragma once
#include <iostream>
#include "Product.h"
#define _CRTDBG_MAP_ALLOC
#include <cstdlib> 
#include <crtdbg.h> 
#ifdef _DEBUG 
#define new new ( _NORMAL_BLOCK , __FILE__ , __LINE__ ) 
#endif 


const int INITIAL_SIZE = 10;
const int EXPAND_FACTOR = 2;

class Store
{
	Product *products;
	int size;
	int numberOfProducts;

	void change(Product & product);//Helping function for changeProduct();

public: 

	Store();
	Store(const Store & copyFrom);

	Store & operator=(const Store & object);

	~Store();

	bool isFull();
	bool isEmpty();

	void resize();

	void addProduct(Product & product);
	void removeProduct(unsigned int sku);
	void changeProduct(unsigned int sku);
	void printProduct(unsigned int sku);
	void print();


};