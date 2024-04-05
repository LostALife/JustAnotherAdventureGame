#pragma once
#include "RoomManager.h"

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

	Room* m_spawnRoom;
	Room* m_currentRoom;

private:
	void CreateSpawnRoom();
	void PrintRoomInfo();
};

