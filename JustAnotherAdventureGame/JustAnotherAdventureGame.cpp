#pragma once
#include <iostream>
#include "GameManager.h"
#include "InventoryManager.h"
#include "RoomManager.h"
#include "Vector2.h"
#include "Item.h"

#include "ItemApple.h";

int main()
{
	GameManager gameManager;
	InventoryManager invManager;
	RoomManager roomManager;

	/*ItemApple apple;

	invManager.AddNewItem(&apple);
	invManager.PrintInventoryToConsole();*/

	Room foundRoom = roomManager.GetRoomAtPosition(Vector2(0, 0));
	std::cout << foundRoom.getRoomName().CStr() << std::endl;
}