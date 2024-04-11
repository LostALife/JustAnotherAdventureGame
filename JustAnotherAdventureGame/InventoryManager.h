#pragma once
#include <vector>
#include "Item.h"

struct InventoryItem {
	Item* item;
	int countInInventory = 0;

	bool operator==(const InventoryItem& _other) {
		return item == _other.item && countInInventory == _other.countInInventory;
	}

	bool operator!=(const InventoryItem& _other) {
		return item != _other.item && countInInventory != _other.countInInventory;
	}
};

class InventoryManager
{
public:
	~InventoryManager();

public:
	InventoryManager& AddNewItem(InventoryItem* _item);
	InventoryManager& AddRandomItem();
	InventoryManager& RemoveItem(const Item& _item, const unsigned int _numToRemove);

	InventoryManager& PrintInventoryToConsole();

protected:
private:
	std::vector<InventoryItem*> m_items;

private:
	InventoryItem* GetInventoryItem(const Item& _item);
	InventoryItem* GetInventoryItem(const InventoryItem& _item);
};
