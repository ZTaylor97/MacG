#pragma once
#include "Entity.h"
namespace MacG
{
	class System
	{
	private:
		
	public:
		std::vector<Entity*> targetEntities;
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


