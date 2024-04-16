#pragma once
#include <map>
#include "RoomManager.h"
#include "InventoryManager.h"
#include "Vector2.h"

enum MoveDirection
{
	up,
	right,
	down,
	left
};

class GameManager
{
public:
	GameManager();

public:
	void BeginGameLoop();

protected:
private:
	RoomManager m_roomManager;
	InventoryManager m_invManager;
	String m_playerInput;

	std::map<int, const char*> m_moveDirectionMap = { {0, "up"}, {1, "right"}, {2, "down"}, {3, "left"} };

	Room* m_spawnRoom;
	Room* m_currentRoom;

private:
	void CreateSpawnRoom();

	void ProcessPlayerInput();
	int Move(MoveDirection _direction);

	void PrintRoomInfo();
	void PrintCommands();
	void PrintAndHandlePickup();
	void PrintAndHandleDrop();
};
