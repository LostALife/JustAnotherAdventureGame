#pragma once
#include <vector>
#include "Vector2.h"
#include "String.h"
#include "Item.h"

enum RoomType {
	Normal,
	Branch,
	BossChamber,
	ChestRoom
};

struct RoomExits {
	bool up;
	bool right;
	bool down;
	bool left;
};

class Room
{
public:
	Room();
	Room(const String& _roomName, const Vector2& _roomPosition, const RoomType& _roomType, const RoomExits& _roomExits, const std::vector<Item*>& _roomItems);

	// TODO create move and copy / assignment constructors
	~Room();

public:
	String getRoomName() {
		return m_roomName;
	}
	Vector2 getRoomPosition() {
		return m_roomPosition;
	}
	RoomType getRoomType() {
		return m_roomType;
	}
	RoomExits getRoomExits() {
		return m_roomExits;
	}
	std::vector<Item*> getRoomItems() {
		return m_roomItems;
	}

private:
	String m_roomName;
	Vector2 m_roomPosition;

	RoomType m_roomType;
	RoomExits m_roomExits;

	std::vector<Item*> m_roomItems;
};