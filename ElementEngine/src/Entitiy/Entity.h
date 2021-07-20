#pragma once

#include <memory>
#include <vector>

class Component;
struct ComponentSearchResults;

/// @brief Basic Entity based on "AOS" style for simplicity
class Entity
{
public:

	int id;

public:

	Entity();

	void initEntity();
	void updateEntity(float delta);

	void initComponents();
	void updateComponents(float delta);

	//Override in child classses
	virtual void start() {}
	virtual void update(float delta) {}

	//TODO Check inside these templated functions to see if T
	//inherits Entity and is the correct type

	template<typename T>
	ComponentSearchResults hasComponent(T component);

	template<typename T>
	void addComponent(T component);

	template<typename T>
	void removeComponent(T component);

	template<typename T>
	T getComponent(T componentType);

public:

	std::vector<Entity*> childEntities;
	std::vector<std::unique_ptr<Component>> componentList;
};
//Entity
static int entityIdCount = 0;

