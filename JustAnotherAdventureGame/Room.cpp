#include "Room.h"

Room::Room() : m_roomName("room"), m_position(0,0), m_id(0)
{
}

Room::Room(const String _roomName, const Vector2 _roomPosition, const int _id)
{
	m_roomName = _roomName;
	m_position = _roomPosition;
	m_id = _id;
}
