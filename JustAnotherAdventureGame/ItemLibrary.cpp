#include <ctime>
#include "ItemLibrary.h"

ItemLibrary::ItemLibrary()
{
	m_itemList.push_back(new ItemApple());
}

ItemLibrary::~ItemLibrary()
{
	for (int i = 0; i < m_itemList.size(); i++) {
		delete m_itemList[i];
	}
}

Item ItemLibrary::GetRandomItem()
{
	srand(time(NULL));
	int randIndex = rand() % m_itemList.size();

	Item returnItem = *m_itemList[randIndex];

	return returnItem;
}
