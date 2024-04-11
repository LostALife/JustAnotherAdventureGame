#pragma once
#include <vector>
#include "Item.h"
#include "ItemApple.h"

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
	Item GetRandomItem();

private:
	std::vector<Item*> m_itemList;
};
