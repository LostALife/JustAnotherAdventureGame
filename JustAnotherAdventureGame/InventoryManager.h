#pragma once
#include <vector>
#include "Item.h"

class InventoryManager
{
public:
	InventoryManager& AddNewItem(Item* _item);
	InventoryManager& RemoveItem();

	Item& GetItem();

	InventoryManager& EqualTo(const Item& _other);

	InventoryManager& PrintInventoryToConsole();

protected:
private:
	std::vector<Item*> m_items;
};
