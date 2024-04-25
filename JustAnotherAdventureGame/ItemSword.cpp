#include "ItemSword.h"
#include <iostream>

ItemSword::ItemSword() : Item("Sword", "sword", "WARNING: Extremely sharp! DO NOT EAT!")
{
}

void ItemSword::Use()
{
	std::cout << "You attempt to eat the sword. Everything goes black...\n";
	system("PAUSE");
}
