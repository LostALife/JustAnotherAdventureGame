#pragma once
#include "String.h"

class Item
{
public:
	Item();
	Item(const String& _displayName, const String& _itemType);

public:
	String getDisplayName() {
		return m_itemDisplayName;
	}

	void virtual OnUse();

protected:
private:
	String m_itemDisplayName;
	String m_itemType;
};