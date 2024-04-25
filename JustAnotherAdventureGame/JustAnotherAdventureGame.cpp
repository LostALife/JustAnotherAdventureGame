#pragma once
#include <iostream>
#include "GameManager.h"
#include "String"

int main()
{
	GameManager gameManager;
	String playerInput;
	
	std::cout << "Welcome to Just Another Adventure Game!" << std::endl;
	std::cout << "Press any key to begin. You can type 'Help' at any point to show available commands." << std::endl << std::endl;

	system("PAUSE");

	gameManager.BeginGameLoop();
}