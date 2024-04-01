#pragma once
#include "Vector2.h"
#include "String.h"

class Room
{
public:
	Room();
	Room(const String _roomName, const Vector2 _roomPosition);

public:
	String getRoomName() {
		return m_roomName;
	}
	Vector2 getRoomPosition() {
		return m_position;
	}
	int getRoomId() {
		return m_id;
	}

private:
	String m_roomName;
	Vector2 m_position;

	int m_id;
};

