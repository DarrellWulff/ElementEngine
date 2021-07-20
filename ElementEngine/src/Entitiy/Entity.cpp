#include "Entity.h"
#include "../Component/Component.h"
#include <vector>
#include <typeinfo>

//TODO Make Delete Entity
Entity::Entity()
{
	id = entityIdCount;
	entityIdCount++;
}

struct ComponentSearchResults
{
	bool isContained;
	int foundIndex;
};

void Entity::initEntity()
{
	initComponents();
	start();
}

void Entity::updateEntity(float delta)
{
	updateComponents(delta);
	update(delta);
}

void Entity::initComponents()
{
	for (auto& currentComponent : componentList)
	{
		currentComponent->initComponent();
	}
}

void Entity::updateComponents(float delta)
{
	for (auto& currentComponent : componentList)
	{
		if (currentComponent->isUpdateEnabled == true)
		{
			currentComponent->updateComponent(delta);
		}
	}
}

 template<typename T>
ComponentSearchResults Entity::hasComponent(T component)
{
	ComponentSearchResults searchResults;
	searchResults.isContained = false;
	searchResults.foundIndex = 0;

	//auto cast to current component type
	for (auto& currentComponent : componentList) 
	{
		searchResults.foundIndex++;
		if (typeid(currentComponent) == typeid(T))
		{
			searchResults.isContained = true;
			return searchResults;
		}
	}

	return searchResults;
}

template<typename T>
void Entity::addComponent(T component)
{
	ComponentSearchResults searchResults = hasComponent(component);
	if (searchResults.isContained == false)
	{
		componentList.push_back(component);
	}
}

template<typename T>
void Entity::removeComponent(T component)
{
	ComponentSearchResults searchResults = hasComponent(component);
	if (searchResults.isContained == true)
	{
		std::vector<Component*>::iterator componentPosition = componentList.begin() + searchResults.foundIndex;
		componentList.at(componentPosition).reset();
		componentList.erase(componentPosition);
	}
}

template<typename T>
T Entity::getComponent(T componentType) 
{
	//auto cast to current component type
	for (auto& currentComponent : componentList)
	{
		if (typeid(currentComponent) == typeid(T))
		{
			return currentComponent;
		}
	}
}
