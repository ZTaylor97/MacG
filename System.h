#pragma once
#include "Entity.h"
namespace MacG
{
	class System
	{
	private:
		
	public:
		std::vector<Entity*> targetEntities;
		virtual void UpdateEntityList(std::map<std::string, MacG::Entity*> entities) {}
		virtual void Initialise() {}
		virtual void Update(float deltaTime) {}
		virtual void Render() {}
		virtual void Clear() 
		{
			targetEntities.clear();
		}

	};
}


