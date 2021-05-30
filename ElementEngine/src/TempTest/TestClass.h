#pragma once
#include <iostream>
#include <chrono>
#include <vector>
#include "../Math/Vector3.h"
#include "../Math/Matrix.h"

class TestClass
{
public:
	TestClass();

	void testProgram();

	void testVector();
	void fastMagTest();
	void testMatrix();
	void testQuat();
};

