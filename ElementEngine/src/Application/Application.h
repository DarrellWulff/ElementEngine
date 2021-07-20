#pragma once
#include "ApplicationWindow.h"
#include <string>

class Application
{
public:

	Application();

	void setApplicationWindowConfig(WindowConfig windowConfig);

public:

	ApplicationWindow window;
	WindowConfig applicationWindowConfig;

};

