#include <iostream>
#include "GameManager.h"
#include "String.h"

GameManager::GameManager()
{
	m_roomManager = RoomManager();
	m_invManager = InventoryManager();
	m_playerInput = String();

	CreateSpawnRoom();
	m_currentRoom = m_spawnRoom;
}

// Starts an infinite loop with all game logic.
void GameManager::BeginGameLoop()
{
	// BAD PRACTICE GO BRRRRR
	while (true) {
		system("CLS");
		PrintRoomInfo();

		std::cout << "Enter a command or type 'Help' for a list of commands.\n";

		ProcessPlayerInput();
	}
}

// If no spawn room exists, creates one and sets m_spawnRoom. 
// Otherwise, returns nullptr.
void GameManager::CreateSpawnRoom()
{
	m_spawnRoom = m_roomManager.GenerateNewRoom("Spawn", Vector2(0, 0), RoomType::Normal, RoomExits{ true,true,true,true }, std::vector<Item*>());
}

void GameManager::ProcessPlayerInput()
{
readInput:
	m_playerInput.ReadFromConsole().ToLower().Trim();

	for (auto i : m_moveDirectionMap) {
		if (m_playerInput == i.second) {
			if (Move(MoveDirection(i.first)) == 0)
				return;
			else {
				std::cout << "There is no exit here...\n\n";
				goto readInput;
			}
		}
	}
	
	if (m_playerInput == "pickup") {
		if (m_currentRoom->getRoomItems().size() > 0)
			PrintAndHandlePickup();
		else {
			std::cout << "There are no items in this room...\n\n";
			goto readInput;
		}
	}
	else if (m_playerInput == "drop") {
		if (m_invManager.getInventoryList().size() > 0)
			PrintAndHandleDrop();
		else {
			std::cout << "You don't have any items to drop...\n\n";
			goto readInput;
		}
	}
	else if (m_playerInput == "help")
		PrintCommands();
	else {
		std::cout << "Unknown command. Try again..." << std::endl << std::endl;
		goto readInput;
	}
}


int GameManager::Move(MoveDirection _direction)
{
	Vector2 positionOffset(0, 0);
	if (_direction == MoveDirection::up && m_currentRoom->getRoomExits().up) {
		positionOffset = Vector2(0, 1);
	}
	else if (_direction == MoveDirection::right && m_currentRoom->getRoomExits().right) {
		positionOffset = Vector2(1, 0);
	}
	else if (_direction == MoveDirection::down && m_currentRoom->getRoomExits().down) {
		positionOffset = Vector2(0, -1);
	}
	else if (_direction == MoveDirection::left && m_currentRoom->getRoomExits().left) {
		positionOffset = Vector2(-1, 0);
	}
	else
		return -1;

	Room* result = m_roomManager.GenerateNewRoom(m_currentRoom->getRoomPosition() + positionOffset);
	if (result != nullptr) 
		m_currentRoom = result;

	system("CLS");

	return 0;
}

void GameManager::PrintRoomInfo()
{
	Vector2 roomPos = m_currentRoom->getRoomPosition();
	RoomExits roomExits = m_currentRoom->getRoomExits();
	std::vector<Item*> roomItems = m_currentRoom->getRoomItems();

	std::cout << "Room: " << m_currentRoom->getRoomName().CStr() <<
		" (" << roomPos.m_x << ", " << roomPos.m_y << ")" << '\n';

	std::cout << "\nRoom Items: ";
	for (int i = 0; i < roomItems.size(); i++) {
		std::cout << roomItems[i]->getDisplayName().CStr();

		if (i < roomItems.size() - 1)
			std::cout << ", ";
	}
	std::cout << '\n';

	std::cout << "\nAvailable Exits:" << std::endl;
	if (roomExits.up) {
		std::cout << "  ^\n";
	}
	else {
		std::cout << '\n';
	}
	if (roomExits.left && roomExits.right) {
		std::cout << "< * >\n";
	}
	else if (roomExits.left) {
		std::cout << "< *\n";
	}
	else if (roomExits.right) {
		std::cout << "  * >\n";
	}
	else {
		std::cout << "  *\n";
	}
	if (roomExits.down) {
		std::cout << "  v\n";
	}
	else {
		std::cout << '\n';
	}
	std::cout << std::endl;
}

void GameManager::PrintCommands()
{
	system("CLS");
	std::cout << "Commands:\n";
	std::cout << "Moving: <up, right, down, left>\n";
	std::cout << "Pickup Item: <pickup>\n";
	std::cout << "Drop Item: <drop>\n";
	std::cout << '\n';

	system("Pause");
	system("CLS");
}

void GameManager::PrintAndHandlePickup()
{
	system("CLS");
	std::cout << "<- Type 'back' to go back...\n\n";

	std::cout << "Room Items:\n";
	for (int i = 0; i < m_currentRoom->getRoomItems().size(); i++) {
		std::cout << "(" << i + 1 << ") " << m_currentRoom->getRoomItems()[i]->getDisplayName().CStr() << '\n';
	}

	std::cout << "\nInventory:\n";
	for (int i = 0; i < m_invManager.getInventoryList().size(); i++) {
		InventoryItem* inventoryItem = m_invManager.getInventoryList()[i];
		std::cout << inventoryItem->item->getDisplayName().CStr() << " x " << inventoryItem->countInInventory << '\n';
	}

	std::cout << "\nSelect an item to pickup by typing its number:\n";

	getInput:
	m_playerInput.ReadFromConsole().ToLower().Trim();

	if (m_playerInput == "back") {
		return;
	}

	int selection = m_playerInput.StringToInt();
	if (selection > 0 && selection <= m_currentRoom->getRoomItems().size()) {
		InventoryItem newItem = InventoryItem(*m_currentRoom->getRoomItems()[selection - 1], 1);
		m_invManager.AddNewItem(newItem);
		m_currentRoom->RemoveItem(*newItem.item);
	}
	else {
		std::cout << "No item exists...\n\n";
		goto getInput;
	}

	PrintAndHandlePickup();
}

void GameManager::PrintAndHandleDrop()
{
	system("CLS");
	std::cout << "<- Type 'back' to go back...\n\n";

	std::cout << "Inventory:\n";
	for (int i = 0; i < m_invManager.getInventoryList().size(); i++) {
		InventoryItem* inventoryItem = m_invManager.getInventoryList()[i];
		std::cout << "(" << i + 1 << ") " << inventoryItem->item->getDisplayName().CStr() << " x " << inventoryItem->countInInventory << '\n';
	}

	std::cout << "\nSelect an item to drop by typing its number:\n";

	getInput:
	m_playerInput.ReadFromConsole().ToLower().Trim();

	if (m_playerInput == "back") {
		return;
	}

	int selection = m_playerInput.StringToInt();
	if (selection > 0 && selection <= m_invManager.getInventoryList().size()) {
		m_currentRoom->AddItem(*m_invManager.getInventoryList()[selection - 1]->item);
		m_invManager.RemoveItem(*m_invManager.getInventoryList()[selection - 1]->item, 1);
	}
	else {
		std::cout << "No item exists...\n\n";
		goto getInput;
	}

	PrintAndHandleDrop();
}
