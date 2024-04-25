#pragma once
#include <vector>
#include "Item.h"

class ItemLibrary
{
public:
	ItemLibrary();
	~ItemLibrary();

public:
	const std::vector<Item*> getItemList() {
		return m_itemList;
	}

public:
	Item* GetRandomItem();
	Item* InstantiateItemOfType(String _type);

private:
	std::vector<Item*> m_itemList;
};
