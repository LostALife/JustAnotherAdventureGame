#include "Item.h"

Item::Item() : m_itemDisplayName("blank"), m_itemType("placeholder"), m_itemDescription("placeholder")
{
}

Item::Item(const Item& _item)
{
	m_itemDisplayName = _item.m_itemDisplayName;
	m_itemType = _item.m_itemType;
	m_itemDescription = _item.m_itemDescription;
}

Item::Item(const String& _displayName, const String& _itemType, const String& _itemDescription)
{
	m_itemDisplayName = _displayName;
	m_itemType = _itemType;
	m_itemDescription = _itemDescription;
}

void Item::Use()
{
}