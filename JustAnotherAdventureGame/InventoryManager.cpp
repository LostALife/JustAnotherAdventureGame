#include <iostream>
#include "InventoryManager.h"

InventoryManager& InventoryManager::AddNewItem(std::unique_ptr<Item> _item)
{
	m_items.emplace_back(_item);

	return *this;
}

InventoryManager& InventoryManager::PrintInventoryToConsole()
{
	for (int i = 0; i < m_items.size(); i++) {
		m_items[i]->getDisplayName().WriteToConsole();
	}

	return *this;
}
