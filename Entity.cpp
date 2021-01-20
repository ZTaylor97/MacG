#include "Entity.h"

#include <iostream>

namespace MacG
{

	Entity::Entity( std::string name, LayerType layer) :  name(name), layer(layer) {
		this->isActive = true;
	}

	void Entity::Update(float deltaTime) {
		for (auto& component : components) {
			component->Update(deltaTime);
		}
	}

	void Entity::Destroy() {
		this->isActive = false;
	}
}

