#pragma once
#include <iostream>

enum GameState {
	Playing,
	Paused
};

class GameManager
{
public:
	GameManager& ChangeGameState(GameState _state);

protected:
private:
	GameState m_gameState;
};

