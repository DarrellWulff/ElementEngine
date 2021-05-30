#include <iostream>
#include "Engine/Engine.h"
#include "TempTest/TestClass.h"

int main() 
{
	//TODO pass application project file path through main to the engine

	//TODO Make sure that quitEngine takes care of all dynamic allocation
	//Since once engine has quit there will be no way to access the data
	Engine elementEngine;

	elementEngine.initEngine();

	//TEMP TEST program
	TestClass *newTest = new TestClass();

	return 0;
}