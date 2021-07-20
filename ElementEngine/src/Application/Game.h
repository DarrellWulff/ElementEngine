#pragma once
#include "Application.h"
#include "../Entitiy/Entity.h"
#include <memory>
#include <vector>

class Game : public Application
{
public:

	Game();

	void initGame();
	void updateGame(float delta);

	template<typename T>
	static void addEntityToGame(T newEntity);

	template<typename T>
	static void freeEntity(T entityToDelete);

public:


};

static std::vector<Entity*> EntityList;

template<typename T>
inline void Game::addEntityToGame(T newEntity)
{

}

template<typename T>
inline void Game::freeEntity(T entityToDelete)
{

}
