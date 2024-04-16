#pragma once
#include <vector>
#include "Item.h"

struct InventoryItem {
	InventoryItem(const Item& _other, const unsigned int _count);
	InventoryItem(const InventoryItem& _inventoryItem);
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
		item = new Item(*_other.item);
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
	InventoryManager& AddNewItem(const InventoryItem& _inventoryItem);
	InventoryManager& AddRandomItem();
	InventoryManager& RemoveItem(const Item& _item, const unsigned int _numToRemove);

	InventoryManager& PrintInventoryToConsole();

protected:
private:
	std::vector<InventoryItem*> m_items;

private:
	InventoryItem* GetInventoryItem(const Item& _item);
};
