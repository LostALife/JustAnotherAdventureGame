#include "ItemApple.h"
#include <iostream>


ItemApple::ItemApple() : Item("Apple", "apple", "It's an apple... Need I say more?")
{
}

void ItemApple::Use()
{
	std::cout << "Tasted pretty good...\n";
	system("PAUSE");
}
