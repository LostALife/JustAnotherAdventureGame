#pragma once
#include <vector>
#include "Vector2.h"
#include "String.h"
#include "Room.h"

class RoomManager
{
public:
	const Room& GetRoomInfo(Vector2 _roomPosition);

protected:
private:
	std::vector<Room> m_rooms;

private:
	void GenerateNewRoom(String _roomName, Vector2 _position);
	Room& FindRoomFromPosition(Vector2 _position);
};