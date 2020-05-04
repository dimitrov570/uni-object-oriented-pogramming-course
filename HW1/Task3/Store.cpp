#include "Store.h"


Store::Store() :size(INITIAL_SIZE), numberOfProducts(0)
{
	products = new Product[size];
}

Store::Store(const Store & copyFrom) :size(copyFrom.size), numberOfProducts(copyFrom.numberOfProducts)
{
	products = new Product[size];
	for (int i = 0; i < size; ++i)
	{
		products[i] = copyFrom.products[i];
	}
}

Store & Store::operator=(const Store & object)
{
	if (this != &object)
	{
		delete[] products;
		
		size = object.size;
		numberOfProducts = object.numberOfProducts;
		products = new Product[size];
		
		for (int i = 0; i < size; ++i)
		{
			products[i] = object.products[i];
		}
	}
	return *this;
}


bool Store::isFull()
{
	return (numberOfProducts>=size);
}

bool Store::isEmpty()
{
	return (numberOfProducts==0);
}


void Store::resize()
{
	int new_size = size * EXPAND_FACTOR;
	Product* tmp = new Product[new_size];
	for (int i = 0; i < size; ++i)
	{
		tmp[i] = products[i];
	}
	delete[] products;
	products = tmp;
	size = new_size;
}


void Store::addProduct(Product & newProduct)
{
	if (isFull())
	{
		resize();
	}

	bool same = false; //This will tell if the product we want to add already exists in the Shop

	for (int i = 0; i < numberOfProducts; ++i)
	{
		if (products[i] == newProduct) //If there is already the same product we are only going to sum their Counts
		{
			products[i].setCount(products[i].getCount() + newProduct.getCount());
			same = true;
			break; //There are never two same products in the shop, so we can break from the cycle
		}
		if (products[i].getSKU() == newProduct.getSKU())
		{
			std::cout << "There exists different product with that SKU! You can't add this product! \n";
			return;
		}
	}
	if (!same)
	{
		products[numberOfProducts++] = newProduct;
	}
}

void Store::removeProduct(unsigned int sku)
{
	int i = 0;
	bool found = false;

	for (; i < numberOfProducts; ++i)
	{
		if (products[i].getSKU() == sku)
		{
			products[i]=products[i+1];
			found = true;
			break;
		}
	}
	for (int j = i; j < numberOfProducts-1; ++j)
	{
		products[j] = products[j + 1];
	}
	if (found)
	{
		products[numberOfProducts--] = Product(); //Setting default product at the last position
		return;
	}
	std::cout << '\n' << "Such product doesn't exist! \n";
}

void Store::changeProduct(unsigned int sku)
{
	for (int i = 0; i < numberOfProducts; ++i)
	{
		if (products[i].getSKU() == sku)
		{
			change(products[i]);
			return; //There are no other products with that SKU, so there is no need to continue for cycle
		};
	}
	std::cout << '\n' <<"Such product doesn't exists in the store! \n";
	return;
}

void Store::printProduct(unsigned int sku)
{
	for (int i=0; i < numberOfProducts; ++i)
	{
		if (products[i].getSKU() == sku)
		{
			std::cout<<products[i];
		};
	}
}

void Store::print()
{
	for (int i = 0; i < numberOfProducts; ++i)
	{
		std::cout << "Product " << i+1 << ":\n-------------------------\n" << products[i] << "\n-------------------------\n\n";
	}
}

void Store::change(Product & product)
{
	BEGINING:
	int operation;
	std::cout << '\n' << "Select what you want to change: 1 - SKU, 2 - Brand, 3 - Model, 4 - Category, 5 - Color, 6 - Price, 7 - Count. \n"
		<<"Insert 8 if you want to quit!\n" << "Please, insert a number: ";
	
	std::cin >> operation;

	if (operation == 8)
	{
		return;
	}

	int number;
	char name[100]; //There is no car brand, model, category or color which name is longer than 100,
					//so it's safe to put the length 100, since we won't reach that limit;

	switch (operation)
	{
	case 1: std::cout << '\n' << "Please, insert a new SKU: ";
		std::cin >> number;
		for (int i = 0; i < numberOfProducts; ++i)
		{
			if (products[i].getSKU() == number)
			{
				std::cout << '\n' << "That SKU already exists! \n";
				goto BEGINING;
			}
		}
		product.setSKU(number);
		break;
	case 2: std::cout << '\n' << "Please, insert a new Brand name: ";
		std::cin >> name;
		product.setBrand(name);
		break;
	case 3: std::cout << '\n' << "Please, insert a new Model name: ";
		std::cin >> name;
		product.setModel(name);
		break;
	case 4:std::cout << '\n' << "Please, insert a new Category name: ";
		std::cin >> name;
		product.setCategory(name);
		break;
	case 5: std::cout << '\n' << "Please, insert a new Color: ";
		std::cin >> name;
		product.setColor(name);
		break;
	case 6: std::cout << '\n' << "Please, insert a new Price: ";
		std::cin >> number;
		product.setPrice(number);
		break;
	case 7: std::cout << '\n' << "Please, insert a new Count: ";
		std::cin >> number;
		product.setCount(number);
		break;
	default:
		std::cout << '\n' << "Such operation doesn't exist! Please, try again!\n";
		break;
	}

	std::cout << std::endl;
	std::cout << '\n' << "Do you want to change something else? 1 - yes, any other NUMBER - no" << '\n' << "Insert: ";
	std::cin >> number;
	if (number == 1)
	{
		goto BEGINING;
	}
	else
	{
		return;
	}
}

Store::~Store()
{
	delete[] products;
}