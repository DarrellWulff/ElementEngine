#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <iostream>
#include "Engine/Engine.h"
#include "Application/Game.h"
#include "TempTest/TestClass.h"
#include "TempTest/ProjectFolder/EEProject.h"

int main() 
{
	//TODO pass application project file path through main to the engine

	//TODO Make sure that quitEngine takes care of all dynamic allocation
	//Since once engine has quit there will be no way to access the data
	Engine elementEngine;
	EngineConfig engineConfig;

	engineConfig.enginePlatform= EnginePlatform::WINDOWS64;
	engineConfig.engineState = EngineState::INIT;
	engineConfig.engineRendererAPI = EngineRendererAPI::OPENGL;

	elementEngine.engineConfig = engineConfig;

	// Make an instance of the the game class here
	EEProject *eeProject = new EEProject();
	elementEngine.initEngine(eeProject);

	//TEMP TEST program
	//TestClass *newTest = new TestClass();

	return 0;
}