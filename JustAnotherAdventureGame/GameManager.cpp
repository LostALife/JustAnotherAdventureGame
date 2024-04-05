#include <iostream>
#include "GameManager.h"
#include "String.h"

GameManager::GameManager()
{
	m_roomManager = new RoomManager();
	CreateSpawnRoom();
	m_currentRoom = m_spawnRoom;
}

GameManager::~GameManager()
{
	delete m_roomManager;
}

void GameManager::BeginGameLoop()
{
	String playerInput;

	// BAD PRACTICE GO BRRRRR
	while (true) {
		PrintRoomInfo();

		std::cout << "Enter a command or type 'Help' for a list of commands." << std::endl << std::endl;

		readInput:

		playerInput.ReadFromConsole();

		if (playerInput.ToLower() == "move up") {
			Room* result = m_roomManager->GenerateNewRoom(m_currentRoom->getRoomPosition() + Vector2(0, 1));
			if (result != nullptr)
				m_currentRoom = result;
			system("CLS");
		} 
		else if (playerInput.ToLower() == "move right") {
			Room* result = m_roomManager->GenerateNewRoom(m_currentRoom->getRoomPosition() + Vector2(1, 0));
			if (result != nullptr)
				m_currentRoom = result;
			system("CLS");
		}
		else if (playerInput.ToLower() == "move down") {
			Room* result = m_roomManager->GenerateNewRoom(m_currentRoom->getRoomPosition() + Vector2(0, -1));
			if (result != nullptr)
				m_currentRoom = result;
			system("CLS");
		}
		else if (playerInput.ToLower() == "move left") {
			Room* result = m_roomManager->GenerateNewRoom(m_currentRoom->getRoomPosition() + Vector2(-1, 0));
			if (result != nullptr)
				m_currentRoom = result;
			system("CLS");
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
	std::cout << "Room: " << m_currentRoom->getRoomName().CStr() <<
		" (" << m_currentRoom->getRoomPosition().m_x << " " << m_currentRoom->getRoomPosition().m_y << ")" << std::endl << std::endl;
}
