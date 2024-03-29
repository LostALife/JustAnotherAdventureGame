#pragma once
#include <vector>
#include "Item.h"

class InventoryManager
{
public:
	InventoryManager& AddNewItem(std::unique_ptr<Item> _item);
	InventoryManager& RemoveItem();

	Item& GetItem();

	InventoryManager& EqualTo(const Item& _other);

	InventoryManager& PrintInventoryToConsole();

protected:
private:
	std::vector<std::unique_ptr<Item>> m_items;
};

