#include <ctime>
#include "String.h"
#include "ItemLibrary.h"
#include "ItemApple.h"
#include "ItemDonut.h"
#include "ItemSword.h"

ItemLibrary::ItemLibrary()
{
	m_itemList.push_back(new ItemApple());
	m_itemList.push_back(new ItemDonut());
	m_itemList.push_back(new ItemSword());

	srand(time(NULL));
}

ItemLibrary::~ItemLibrary()
{
	for (int i = 0; i < m_itemList.size(); i++) {
		delete m_itemList[i];
	}
}

Item* ItemLibrary::GetRandomItem()
{
	int randIndex = rand() % m_itemList.size();

	Item* returnItem = InstantiateItemOfType(m_itemList[randIndex]->getType());

	return returnItem;
}

Item* ItemLibrary::InstantiateItemOfType(String _type)
{
	// I hate this, but I don't know how else to do it...
	if (_type == "apple")
		return new ItemApple();
	else if (_type == "donut")
		return new ItemDonut();
	else if (_type == "sword")
		return new ItemSword();

	return nullptr;
}
