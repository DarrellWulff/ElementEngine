#include "Engine.h"
#include <iostream>

Engine::Engine()
{

}

Engine::~Engine()
{

}


void Engine::initEngine(Game *newApplication)
{
	std::cout << "Element Engine Initialization" << std::endl;

	if (newApplication == nullptr) 
	{
		std::cout << "No Game file set in main, cannot init Element Engine" << std::endl;
		return;
	}

	initBasedOnPlatform();
}

void Engine::updateEngine()
{
}

void Engine::quitEngine()
{
}

void Engine::initBasedOnPlatform()
{
	switch (engineConfig.enginePlatform)
	{
	case WINDOWS64:
		break;
	case WINDOWS32:
		break;
	case UWP:
		break;
	case LINUX:
		break;
	case ANDROID:
		break;
	default:
		break;
	}
}

void Engine::initRendererAPI()
{
	switch (engineConfig.engineRendererAPI)
	{
	case DIRECT3D11:
		break;
	case DIRECT3D12:
		break;
	case OPENGL:
		break;
	case VULKAN:
		break;
	case METAL:
		break;
	default:
		break;
	}
}
