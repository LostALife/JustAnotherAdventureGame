#pragma once
#include "String.h"

class Item
{
public:
	Item();
	Item(const Item& _item);
	Item(const String& _displayName, const String& _itemType, const String& _itemDescription);

public:
	String getDisplayName() {
		return m_itemDisplayName;
	}

	String getDescription() {
		return m_itemDescription;
	}

	String getType() {
		return m_itemType;
	}

public:
	void virtual Use();

public:
	bool operator==(const Item& _other) {
		return m_itemDisplayName == _other.m_itemDisplayName && m_itemType == _other.m_itemType && m_itemDescription == _other.m_itemDescription;
	}

	bool operator!=(const Item& _other) {
		return m_itemDisplayName != _other.m_itemDisplayName && m_itemType != _other.m_itemType && m_itemDescription != _other.m_itemDescription;
	}

protected:
private:
	String m_itemDisplayName;
	String m_itemType;

	String m_itemDescription;
};