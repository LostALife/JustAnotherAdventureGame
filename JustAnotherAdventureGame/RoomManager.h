#pragma once
#include <vector>
#include <ctime>
#include <algorithm>
#include "Vector2.h"
#include "ItemLibrary.h"
#include "String.h"
#include "Room.h"
#include "Item.h"

struct RoomGenParams {
	String roomName;
	Vector2 roomPosition;

	RoomType roomType = RoomType::Normal;
	RoomExits roomExits = RoomExits{false, false, false, false};

	std::vector<Item*> roomItems;
};

class RoomManager
{
public:
	// TODO: MOVE, COPY, MOVE ASSIGN, COPY ASSIGN Constructors
	RoomManager();
	RoomManager(const RoomManager& _other);
	~RoomManager();

	int newInt = 5;
	int* newIntPtr = &newInt;

public:
	Room* GetRoomAtPosition(const Vector2 _roomPosition);
	Room* GenerateNewRoom(const Vector2 _roomPosition);
	Room* GenerateNewRoom(const String _roomName, const Vector2 _roomPosition, const RoomType _roomType, const RoomExits _roomExits, const std::vector<Item*>& _roomItems);

protected:
private:
	std::vector<Room*> m_rooms;
 
	std::vector<String> m_bossNames = {"Billy", "Gandolf", "Randy", "Oden", "Milly", "Ganon", "Mike Tyson", "Virgil"};
	std::vector<String> m_roomNames = {"Dungeon", "Basement", "Temple", "Slaughterhouse", "Tomb"};

private:
	RoomGenParams GenerateNewRoomParameters(const Vector2 _newRoomPosition);

private:
	Room* BinarySearchRoomPos(const Vector2 _position);
	Room* GetClosestRoomByType(const RoomType _roomType, Vector2 _searchFrom, const int _searchDistance);
};
