#include "Item.h"

Item::Item() : m_itemDisplayName("blank"), m_itemType("placeholder")
{
}

Item::Item(const String& _displayName, const String& _itemType)
{
	m_itemDisplayName = _displayName;
	m_itemType = _itemType;
}

void Item::OnUse()
{
}