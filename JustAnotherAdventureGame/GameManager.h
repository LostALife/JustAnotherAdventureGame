#pragma once
#include "RoomManager.h"
#include "InventoryManager.h"

class GameManager
{
public:
	GameManager();
	~GameManager();

public:
	void BeginGameLoop();

protected:
private:
	RoomManager* m_roomManager;
	InventoryManager* m_invManager;

	Room* m_spawnRoom;
	Room* m_currentRoom;

private:
	void CreateSpawnRoom();
	void PrintRoomInfo();
};

