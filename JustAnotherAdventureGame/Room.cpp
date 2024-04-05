#include "Room.h"

Room::Room() : m_roomName("room"), m_roomPosition(0,0), m_roomType(RoomType::Normal), m_roomExits(RoomExits{false,false,false,false})
{
}

Room::Room(const String _roomName, const Vector2 _roomPosition, const RoomType _roomType, const RoomExits _roomExits)
{
	m_roomName = _roomName;
	m_roomPosition = _roomPosition;
	m_roomType = _roomType;
	m_roomExits = _roomExits;
}