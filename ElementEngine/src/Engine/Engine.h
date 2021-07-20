#pragma once
#include "../Application/Game.h"
//TODOT make configuration file

//Focus is windows devices only atm.
enum EnginePlatform
{
	WINDOWS64 = 1,
	WINDOWS32,
	UWP,
	LINUX,
	ANDROID
};

enum EngineRendererAPI
{
	DIRECT3D11 = 1,
	DIRECT3D12,
	OPENGL,
	VULKAN,
	METAL
};

enum EngineState
{
	INIT = 1,
	EDIT,
	RUN,
	QUIT
};

struct EngineConfig 
{
	EnginePlatform enginePlatform;
	EngineState engineState;
	EngineRendererAPI engineRendererAPI;
};

class Engine
{

public:

	EngineConfig engineConfig;

	Game application;

public:

	Engine();
	~Engine();

	void initEngine(Game *newApplication);

	void updateEngine();

	void quitEngine();

protected:

	void initBasedOnPlatform();
	void initRendererAPI();

private:

};

