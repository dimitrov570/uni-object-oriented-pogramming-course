#include <iostream>
#include "Store.h"
#define _CRTDBG_MAP_ALLOC
#include <cstdlib> 
#include <crtdbg.h> 
#ifdef _DEBUG 
#define new new ( _NORMAL_BLOCK , __FILE__ , __LINE__ ) 
#endif 


void menu(Store & store)
{
BEGINING:

	char c;
	int sku;
	Product product;

	std::cout << '\n' << "MENU: \n\n" << "A - Add new product \n" << "X - Delete product \n" << "C - Change product \n" << "D - Display products \n" 
			  << "Q - Quit \n";
	std::cout << "Choose: ";
	std::cin >> c;

	switch (c)
	{
	case 'A':
		std::cin >> product;
		store.addProduct(product);
		break;
	
	case 'X':
		std::cout << '\n' << "Insert SKU of the product you want to delete: ";
		std::cin >> sku;
		store.removeProduct(sku);
		break;
	
	case 'C' : std::cout << '\n' << "Insert SKU of the product you want to change: ";
		std::cin >> sku;
		store.changeProduct(sku);
		break;
	
	case 'D': store.print();
		break;
	
	case 'Q': return;
	default:
		std::cout<< '\n' << "Invalid operation! Try again! \n";
	}
	goto BEGINING;
}

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	Product car1(1, "Mercedes", "C200", "Coupe", "Black", 5000, 5);
	
	Product car2(car1);
	car2.setSKU(2);
	car2.setModel("S200");
	car2.setCategory("Sedan");
	car2.setPrice(10000);

	Product car3 = car2;
	car3.setSKU(3);
	car3.setModel("E200");
	car3.setColor("Grey");
	car3.setPrice(7000);
	car3.setCount(10);

	Product car4(4, "BMW", "320", "Sedan", "Black", 4900, 7);
	Product car5(5, "BMW", "M3", "Cabrio", "White", 8900, 3);
	Product car6(6, "BMW", "520D", "Sedan", "Black", 9900, 4);
	Product car7(7, "Audi", "A3", "Coupe", "Red", 5900, 7);
	Product car8(8, "Audi", "S5", "Cabrio", "Blue", 9500, 4);
	Product car9(9, "Audi", "R8", "Cabrio", "Grey", 12000, 6);
	Product car10(10, "VW", "Golf 2", "Limousine", "Grey", 1000, 7);
	Product car11(11, "VW", "Passat", "Hatchback", "Grey", 4500, 5);

	Store MyStore;

	MyStore.addProduct(car1);
	MyStore.addProduct(car2);
	MyStore.addProduct(car3);
	MyStore.addProduct(car4);
	MyStore.addProduct(car5);
	MyStore.addProduct(car6);
	MyStore.addProduct(car7);
	MyStore.addProduct(car8);
	MyStore.addProduct(car9);
	MyStore.addProduct(car10);
	MyStore.addProduct(car11);

	menu(MyStore); 

	return 0;
}