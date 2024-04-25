#include "ItemDonut.h"
#include <iostream>

ItemDonut::ItemDonut() : Item("Donut", "donut", "Sugary, torus shaped, and slightly unhealthy!")
{
}

void ItemDonut::Use()
{
	std::cout << "You enjoyed the yummy donut! You now have type 2 diabetes...\n";
	system("PAUSE");
}
