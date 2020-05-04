#include "Product.h"


Product::Product(unsigned int sku, const char* brand, const char* model, const char* category,
	const char* color, unsigned int price, unsigned int count) :SKU(sku), Price(price), Count(count)
{
	Brand = new char[strlen(brand) + 1];
	strcpy(Brand, brand);

	Model = new char[strlen(model) + 1];
	strcpy(Model, model);

	Category = new char[strlen(category) + 1];
	strcpy(Category, category);

	Color = new char[strlen(color) + 1];
	strcpy(Color, color);
}

Product::Product(const Product & copyFrom) :SKU(copyFrom.SKU), Price(copyFrom.Price), Count(copyFrom.Count)
{
	Brand = new char[strlen(copyFrom.Brand) + 1];
	strcpy(this->Brand, copyFrom.Brand);

	Model = new char[strlen(copyFrom.Model) + 1];
	strcpy(this->Model, copyFrom.Model);

	Category = new char[strlen(copyFrom.Category) + 1];
	strcpy(this->Category, copyFrom.Category);

	Color = new char[strlen(copyFrom.Color) + 1];
	strcpy(this->Color, copyFrom.Color);
}

Product & Product::operator=(const Product & object)
{
	if (this != &object)
	{
		
		copy(*this, object);
	}

	return *this;
}


unsigned int Product::getSKU() const
{
	return SKU;
}

const char * Product::getBrand() const
{
	return Brand;
}

const char * Product::getModel() const
{
	return Model;
}

const char * Product::getCategory() const
{
	return Category;
}

const char * Product::getColor() const
{
	return Color;
}

unsigned int Product::getPrice() const
{
	return Price;
}

unsigned int Product::getCount() const
{
	return Count;
}


void Product::setSKU(unsigned int sku)
{
	SKU = sku;
}

void Product::setBrand(const char* brand)
{
	if (brand == nullptr)
	{
		return;
	}
	delete[] this->Brand;
	Brand = new char[strlen(brand) + 1];
	strcpy(Brand, brand);
}

void Product::setModel(const char * model)
{
	if (model == nullptr)
	{
		return;
	}
	delete[] this->Model;
	Model = new char[strlen(model) + 1];
	strcpy(Model, model);
}

void Product::setCategory(const char * category)
{
	if (category == nullptr)
	{
		return;
	}
	delete[] this->Category;
	Category = new char[strlen(category) + 1];
	strcpy(Category, category);
}

void Product::setColor(const char * color)
{
	if (color == nullptr)
	{
		return;
	}
	delete[] this->Color;
	Color = new char[strlen(color) + 1];
	strcpy(Color, color);
}

void Product::setPrice(unsigned int price)
{
	Price = price;
}

void Product::setCount(unsigned int count)
{
	Count = count;
}

std::istream & operator>>(std::istream & stream, Product & product)
{

	unsigned int sku, price, count;
	char Brand[100];
	char Model[100];
	char Category[100];
	char Color[100];
	std::cout << "SKU: ";
	stream >> sku;
	std::cout << '\n' << "Brand: ";
	stream >> Brand;
	std::cout << '\n' << "Model: ";
	stream >> Model;
	std::cout << '\n' << "Category: ";
	stream >> Category;
	std::cout << '\n' << "Color: ";
	stream >> Color;
	std::cout << '\n' << "Price: ";
	stream >> price;
	std::cout << '\n' << "Count: ";
	stream >> count;

	product.SKU = sku;
	product.setBrand(Brand);
	product.setModel(Model);
	product.setCategory(Category);
	product.setColor(Color);
	product.Price = price;
	product.Count = count;

	return stream;
}

std::ostream & operator<<(std::ostream & stream, const Product & product)
{
	stream << "SKU: " << product.SKU << '\n' << "Brand: " << product.Brand << '\n' << "Model: " << product.Model << '\n' 
		<< "Category: " << product.Category << '\n' << "Color: " << product.Color << '\n' << "Price: " << product.Price << '\n' 
		<< "Count: " << product.Count;

	return stream;
}

bool compareNames(const char * name1, const char * name2)
{
	if (name1 == nullptr || name2 == nullptr)
	{
		return false;
	}
	else if (strlen(name1) != strlen(name2))//To prevent accessing memory that isn't allowed
	{
		return false;
	}
	for (int i = 0; i < strlen(name1); i++)
	{
		if (name1[i] != name2[i])
		{
			return false;
		}
	}
	return true;
}

bool  operator==(Product & product1, Product & product2)
{
	if (product1.SKU != product2.SKU)
	{
		return false;
	}
	else if (product1.Price != product2.Price)
	{
		return false;
	}
	else if (!compareNames(product1.Brand, product2.Brand)) // ! of compareNames();
	{
		return false;
	}
	else if (!compareNames(product1.Model, product2.Model))
	{
		return false;
	}
	else if (!compareNames(product1.Category, product2.Category))
	{
		return false;
	}
	else if (!compareNames(product1.Color, product2.Color))
	{
		return false;
	}

	return true;
}


void copy(Product & product1, const Product & product2)
{
	product1.SKU = product2.SKU;
	product1.Price = product2.Price;
	product1.Count = product2.Count;

	delete[] product1.Brand;
	product1.Brand = new char[strlen(product2.Brand) + 1];
	strcpy(product1.Brand, product2.Brand);

	delete[] product1.Model;
	product1.Model = new char[strlen(product2.Model) + 1];
	strcpy(product1.Model, product2.Model);

	delete[] product1.Category;
	product1.Category = new char[strlen(product2.Category) + 1];
	strcpy(product1.Category, product2.Category);

	delete[] product1.Color;
	product1.Color = new char[strlen(product2.Color) + 1];
	strcpy(product1.Color, product2.Color);
}

Product::~Product()
{
	delete[] Brand;
	delete[] Model;
	delete[] Category;
	delete[] Color;
}