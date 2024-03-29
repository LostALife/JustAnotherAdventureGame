#include "GameManager.h"

GameManager& GameManager::ChangeGameState(GameState _state)
{
	m_gameState = _state;

	return *this;
}
