#include <iostream>
#include "GameManager.h"
#include "String.h"

GameManager::GameManager()
{
	m_roomManager = new RoomManager();
	m_invManager = new InventoryManager();

	CreateSpawnRoom();
	m_currentRoom = m_spawnRoom;
}

GameManager::~GameManager()
{
	delete m_roomManager;
	delete m_invManager;
}

void GameManager::BeginGameLoop()
{
	String playerInput;

	// BAD PRACTICE GO BRRRRR
	while (true) {
		system("CLS");
		PrintRoomInfo();

		std::cout << "Enter a command or type 'Help' for a list of commands." << std::endl << std::endl;

		readInput:

		playerInput.ReadFromConsole();

		if (playerInput.ToLower() == "move up") {
			if (m_currentRoom->getRoomExits().up) {
				Room* result = m_roomManager->GenerateNewRoom(m_currentRoom->getRoomPosition() + Vector2(0, 1));
				if (result != nullptr)
					m_currentRoom = result;
				system("CLS");
			}
			else {
				std::cout << "There is no exit here..." << std::endl << std::endl;
				goto readInput;
			}
		} 
		else if (playerInput.ToLower() == "move right") {
			if (m_currentRoom->getRoomExits().right) {
				Room* result = m_roomManager->GenerateNewRoom(m_currentRoom->getRoomPosition() + Vector2(1, 0));
				if (result != nullptr)
					m_currentRoom = result;
				system("CLS");
			}
			else {
				std::cout << "There is no exit here..." << std::endl << std::endl;
				goto readInput;
			}
		}
		else if (playerInput.ToLower() == "move down") {
			if (m_currentRoom->getRoomExits().down) {
				Room* result = m_roomManager->GenerateNewRoom(m_currentRoom->getRoomPosition() + Vector2(0, -1));
				if (result != nullptr)
					m_currentRoom = result;
				system("CLS");
			}
			else {
				std::cout << "There is no exit here..." << std::endl << std::endl;
				goto readInput;
			}
		}
		else if (playerInput.ToLower() == "move left") {
			if (m_currentRoom->getRoomExits().left) {
				Room* result = m_roomManager->GenerateNewRoom(m_currentRoom->getRoomPosition() + Vector2(-1, 0));
				if (result != nullptr)
					m_currentRoom = result;
				system("CLS");
			}
			else {
				std::cout << "There is no exit here..." << std::endl << std::endl;
				goto readInput;
			}
		}
		else if (playerInput.ToLower() == "help") {
			system("CLS");
			std::cout << "Commands:" << std::endl;
			std::cout << "Move <up, right, down, left>" << std::endl << std::endl;

			system("Pause");
			system("CLS");
		}
		else {
			std::cout << "Uknown command. Try again..." << std::endl << std::endl;
			goto readInput;
		}		
	}
}

// If no spawn room exists, creates one and sets m_spawnRoom. 
// Otherwise, returns nullptr.
void GameManager::CreateSpawnRoom()
{
	m_spawnRoom = m_roomManager->GenerateNewRoom("Spawn", Vector2(0, 0), RoomType::Normal, RoomExits{ true,true,true,true });
}

void GameManager::PrintRoomInfo()
{
	Vector2 roomPos = m_currentRoom->getRoomPosition();
	RoomExits roomExits = m_currentRoom->getRoomExits();

	std::cout << "Room: " << m_currentRoom->getRoomName().CStr() <<
		" (" << roomPos.m_x << " " << roomPos.m_y << ")" << std::endl;

	std::cout << "Available Exits:" << std::endl;
	if (roomExits.up)
		std::cout << "Up" << std::endl;
	if (roomExits.down)
		std::cout << "Down" << std::endl;
	if (roomExits.left)
		std::cout << "Left" << std::endl;
	if (roomExits.right)
		std::cout << "Right" << std::endl;
	std::cout << std::endl;
}
