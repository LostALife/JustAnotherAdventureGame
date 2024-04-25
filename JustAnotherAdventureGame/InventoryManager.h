#pragma once
#include <vector>
#include "Item.h"
#include "ItemLibrary.h"

struct InventoryItem {
	InventoryItem(Item* _other, const unsigned int _count);
	InventoryItem(InventoryItem& _inventoryItem);
	~InventoryItem();

	Item* item;
	int countInInventory = 0;

	bool operator==(const InventoryItem& _other) {
		return item == _other.item && countInInventory == _other.countInInventory;
	}

	bool operator!=(const InventoryItem& _other) {
		return item != _other.item && countInInventory != _other.countInInventory;
	}

	InventoryItem& operator=(const InventoryItem& _other) {
		ItemLibrary itemLibrary;
		item = itemLibrary.InstantiateItemOfType(_other.item->getType());
		countInInventory = _other.countInInventory;
	}
};

class InventoryManager
{
public:
	~InventoryManager();

public:
	const std::vector<InventoryItem*> getInventoryList();

public:
	InventoryManager& AddNewItem(InventoryItem& _inventoryItem);
	InventoryManager& RemoveItemOfType(const Item& _item, const unsigned int _numToRemove);

	InventoryManager& PrintInventoryToConsole();

protected:
private:
	std::vector<InventoryItem*> m_items;

private:
	InventoryItem* GetInventoryItem(const Item& _item);
};
