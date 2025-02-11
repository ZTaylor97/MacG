#pragma once

#include "Entity.h"
#include <SDL.h>

namespace MacG
{
	class Entity;

	class Component
	{
	public:
		Entity* owner;
		virtual void Update(float deltaTime) {}
	};
}


