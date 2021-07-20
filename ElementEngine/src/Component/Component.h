#pragma once

#include <memory>

class Entity;

class Component
{

public:

	Entity* parentEntity;
	bool isUpdateEnabled = false;

public:

	Component(Entity* parent);

	virtual void initComponent() {}
	virtual void updateComponent(float delta) {}
};

