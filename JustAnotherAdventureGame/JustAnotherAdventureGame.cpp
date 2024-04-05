#pragma once
#include <iostream>
#include "InventoryManager.h"
#include "RoomManager.h"
#include "Vector2.h"
#include "ItemIncludes.h"

Room* spawnRoom = nullptr;

void CreateSpawnRoom(RoomManager& _roomManager);

int main()
{
	InventoryManager invManager;
	RoomManager roomManager;

	CreateSpawnRoom(roomManager);
}

// If no spawn room exists, creates one and returns its pointer. 
// Otherwise, returns nullptr.
void CreateSpawnRoom(RoomManager& _roomManager) {
	spawnRoom = _roomManager.GenerateNewRoom("Spawn", Vector2(0,0), RoomType::Normal, RoomExits{true,true,true,true});
}