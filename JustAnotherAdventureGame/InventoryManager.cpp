#include <iostream>
#include "InventoryManager.h"
#include "ItemLibrary.h"

InventoryManager::~InventoryManager()
{
	for (int i = 0; i < m_items.size(); i++) {
		delete m_items[i]->item;
	}
}

const std::vector<InventoryItem*> InventoryManager::getInventoryList()
{
	std::vector<InventoryItem*> returnList;
	for (int i = 0; i < m_items.size(); i++) {
		if (m_items[i]->countInInventory > 0)
			returnList.push_back(m_items[i]);
	}

	return returnList;
}

// Adds a new item to the inventory.
InventoryManager& InventoryManager::AddNewItem(const InventoryItem& _inventoryItem)
{
	InventoryItem* searchResult = GetInventoryItem(*_inventoryItem.item);
	if (searchResult == nullptr) {
		m_items.push_back(new InventoryItem(_inventoryItem));
	}
	else {
		searchResult->countInInventory += _inventoryItem.countInInventory;
	}

	return *this;
}

// Adds a random item to the inventory.
InventoryManager& InventoryManager::AddRandomItem()
{
	ItemLibrary itemLibrary;
	Item newItem = itemLibrary.GetRandomItem();

	InventoryItem* searchResult = GetInventoryItem(newItem);
	if (searchResult == nullptr) {
		InventoryItem newInventoryItem = InventoryItem(newItem, 1);
		m_items.push_back(&newInventoryItem);
	}
	else {
		searchResult->countInInventory += 1;
	}

	return *this;
}

// Removes one or more of an item from the inventory.
// Attempting to remove more of an item than exists in the inventory removes all of the specified item from the inventory.
InventoryManager& InventoryManager::RemoveItem(const Item& _item, const unsigned int _numToRemove)
{
	InventoryItem* searchResult = GetInventoryItem(_item);
	if (searchResult != nullptr) {
		int newValue = searchResult->countInInventory - _numToRemove;

		if (newValue > 0) {
			searchResult->countInInventory = newValue;
		}
		else {
			searchResult->countInInventory = 0;
		}
	}

	return *this;
}

// Searches for Item in inventory. Returns nullptr if not found.
InventoryItem* InventoryManager::GetInventoryItem(const Item& _item)
{
	for (int i = 0; i < m_items.size(); i++) {
		if (*m_items[i]->item == _item) {
			return m_items[i];
		}
	}

	return nullptr;
}

// Prints a list of the inventory contents to console.
InventoryManager& InventoryManager::PrintInventoryToConsole()
{
	for (int i = 0; i < m_items.size(); i++) {
		m_items[i]->item->getDisplayName().WriteToConsole();
	}

	return *this;
}

InventoryItem::InventoryItem(const Item& _other, const unsigned int _count)
{
	item = new Item(_other);
	countInInventory = _count;
}

InventoryItem::InventoryItem(const InventoryItem& _inventoryItem)
{
	item = new Item(*_inventoryItem.item);
	countInInventory = _inventoryItem.countInInventory;
}

InventoryItem::~InventoryItem()
{
	delete item;
}
