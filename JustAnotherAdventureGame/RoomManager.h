#pragma once
#include <vector>
#include "Vector2.h"
#include "String.h"
#include "Room.h"

class RoomManager
{
public:
	const Room& GetRoomAtPosition(const Vector2 _roomPosition);

protected:
private:
	std::vector<Room> m_rooms;

private:
	Room& GenerateNewRoom(const String _roomName, const Vector2 _position);
	Room* FindRoomFromPosition(const Vector2 _position);
};