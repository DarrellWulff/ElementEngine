#include "TestClass.h"

#define quote(x) #x

TestClass::TestClass()
{
	testProgram();
}

void TestClass::testProgram()
{
	std::cout << "\nentered test program\n" << std::endl;

	//testVector();
	//fastMagTest();
	//testMatrix();
	testQuat();
}

void TestClass::testVector()
{
	std::cout << " Vector Testing \n";

	Vector3 emptyVector;

	emptyVector.printVector(quote(emptyVector));

	Vector3 testVector(1.0f);

	testVector.printVector(quote(testVector));

	Vector3 setVector(1.0f, 2.0f, 3.0f);

	setVector.printVector(quote(setVector));

	setVector = testVector + setVector;

	setVector.printVector(quote(setVector));

	setVector = setVector * 2.5f;

	setVector.printVector(quote(setVector));

}

void TestClass::fastMagTest()
{

	const int NUM_ELEMENTS = 10000000;

	//INIT
	std::vector<Vector3> regVectors;
	std::vector<Vector3> fastVectors;

	//FILL
	for (int i = 0; i < NUM_ELEMENTS; i++) 
	{
		float curX = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / 1000));
		float curY = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / 1000));
		float curZ = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / 1000));

		Vector3 curVector(curX, curY, curZ);

		regVectors.push_back(curVector);
	}

	for (int i = 0; i < NUM_ELEMENTS; i++)
	{
		float curX = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / 1000));
		float curY = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / 1000));
		float curZ = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / 1000));

		Vector3 curVector(curX, curY, curZ);

		fastVectors.push_back(curVector);
	}

	//TEST AREA
	std::cout << "TEST START" << std::endl;
	//REG VEC
	auto t1 = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < NUM_ELEMENTS; i++)
	{
		regVectors[i].normalize();
	}
	auto t2 = std::chrono::high_resolution_clock::now();
	std::cout << "reg normal took "
		<< std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count()
		<< " milliseconds\n";


	//FAST VEC
	auto t3 = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < NUM_ELEMENTS; i++)
	{
		fastVectors[i].fastNormalize();
	}
	auto t4 = std::chrono::high_resolution_clock::now();
	std::cout << "fast normal took "
		<< std::chrono::duration_cast<std::chrono::milliseconds>(t4 - t3).count()
		<< " milliseconds\n";
}

void TestClass::testMatrix()
{
	std::cout << "\n Matrix Testing \n";

	Matrix newTestMatrix;

	Matrix newTestMatrix2(
		2.0f,0.0f,0.0f,0.0f,
		0,3,0,0,
		0,0,4,0,
		0,0,0,5
	);

	Matrix newTestMatrix3(
		2, 1, 0, 0,
		0, 3, 1, 0,
		1, 0, 4, 0,
		0, 1, 0, 5
	);

	newTestMatrix.printMatrix();

	newTestMatrix2.printMatrix();

	newTestMatrix = newTestMatrix * newTestMatrix2;

	newTestMatrix.printMatrix();

	newTestMatrix = newTestMatrix + newTestMatrix3;

	newTestMatrix.printMatrix();
}

void TestClass::testQuat()
{
	std::cout << "\nQuat Test\n";
}
