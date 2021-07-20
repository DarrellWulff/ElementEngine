#include "Game.h"

Game::Game()
{

}

void Game::initGame()
{
	for (Entity* entity : EntityList)
	{
		entity->initEntity();
	}
}

void Game::updateGame(float delta)
{
	for (Entity* entity : EntityList)
	{
		entity->updateEntity(delta);
	}
}
