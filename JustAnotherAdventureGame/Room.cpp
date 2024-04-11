#include "Room.h"

Room::Room() : m_roomName("room"), m_roomPosition(0,0), m_roomType(RoomType::Normal), m_roomExits(RoomExits{false,false,false,false})
{
}

Room::Room(const String& _roomName, const Vector2& _roomPosition, const RoomType& _roomType, const RoomExits& _roomExits, const std::vector<Item*>& _roomItems)
{
	m_roomName = _roomName;
	m_roomPosition = _roomPosition;
	m_roomType = _roomType;
	m_roomExits = _roomExits;
	m_roomItems = _roomItems;
}

Room::~Room()
{
	for (int i = 0; i < m_roomItems.size(); i++) {
		delete m_roomItems[i];
	}

	m_roomItems.clear();
}
