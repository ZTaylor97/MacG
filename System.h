#pragma once
#include "Entity.h"
namespace MacG
{
	class System
	{
	private:
		std::vector<Entity*> targetEntities;
	public:
		virtual void UpdateEntityList(std::vector<Entity*> entities) {}
		virtual void Initialise() {}
		virtual void Update(float deltaTime) {}
		virtual void Render() {}
		virtual void Clear() 
		{
			targetEntities.clear();
		}

	};
}


