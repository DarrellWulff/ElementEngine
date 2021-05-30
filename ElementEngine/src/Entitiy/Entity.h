#pragma once

class Entity
{
public:

	Entity();

	void addComponent();
	void removeComponent();

	template<typename T>
	void hasComponent(T component);

};

