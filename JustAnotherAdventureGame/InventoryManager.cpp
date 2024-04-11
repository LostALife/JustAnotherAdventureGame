#include <iostream>
#include "InventoryManager.h"
#include "ItemLibrary.h"

InventoryManager::~InventoryManager()
{
	for (int i = 0; i < m_items.size(); i++) {
		delete m_items[i]->item;
	}
}

// Adds a new item to the inventory.
InventoryManager& InventoryManager::AddNewItem(InventoryItem* _item)
{
	InventoryItem* searchResult = GetInventoryItem(*_item);
	if (searchResult == nullptr) {
		InventoryItem newInventoryItem = { new Item(*_item->item), 1};
		m_items.push_back(&newInventoryItem);
	}
	else {
		searchResult->countInInventory += 1;
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
		InventoryItem newInventoryItem = { &newItem, 1 };
		m_items.push_back(&newInventoryItem);
	}
	else {
		searchResult->countInInventory += 1;
	}

	return *this;
}

// Removes one or more of an item from the inventory.
// Attempting to remove move of an item than exists in the inventory removes all of the specified item from the inventory.
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

// Searches for an InventoryItem in inventory. Returns nullptr if not found.
InventoryItem* InventoryManager::GetInventoryItem(const InventoryItem& _item)
{
	for (int i = 0; i < m_items.size(); i++) {
		if (*m_items[i] == _item) {
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
