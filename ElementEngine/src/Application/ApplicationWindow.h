#pragma once
#include <SDL.h>
#include <stdio.h>
#include <string>

struct WindowConfig 
{
	int SCREEN_WIDTH;
	int SCREEN_HEIGHT;
	bool fullScreenEnabled;
	std::string renderAPIName;
};

class ApplicationWindow
{
public:

	ApplicationWindow();

public:

	WindowConfig windowConfig;

};

