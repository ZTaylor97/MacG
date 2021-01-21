#include "SystemManager.h"

namespace MacG
{
	void SystemManager::Update(float deltaTime)
	{
		for (auto& system : Systems)
		{
			system.second->Update(deltaTime);
		}
		// TODO: Insert code for removing superfluous systems
	}
	void SystemManager::Render()
	{
		for (auto& system : Systems)
		{
			system.second->Render();
		}
	}
	void SystemManager::ClearSystems()
	{
		for (auto& system : Systems)
		{
			system.second->Clear();
		}
		Systems.clear();
	}

	std::vector<System*> SystemManager::GetSystems()
	{
		std::vector<System*> returnSystems;

		for (auto& system : Systems)
		{
			returnSystems.emplace_back(system.second);
		}

		return returnSystems;
	}
}