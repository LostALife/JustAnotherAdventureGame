#pragma once
#include "Item.h"

class ItemSword : public Item
{
public:
	ItemSword();

	void Use() override;
};

