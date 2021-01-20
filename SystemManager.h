#pragma once
#include <vector>
#include <typeinfo>
#include "System.h"
namespace MacG
{
	class SystemManager
	{
	private:
		std::map<const std::type_info*, System*> Systems;
	public:
		void Update(float deltaTime);
		void Render();
		void ClearSystems();
		std::vector<System*> GetSystems();

		template<typename T, typename... TArgs>
		T& AddSystem(TArgs&&... args)
		{
			T* newSystem(new T(std::forward<TArgs>(args)...));
			Systems[&typeid(*newSystem)] = newSystem;
			newSystem->Initialise();

			return *newSystem;
		}

		template <typename T>
		T* GetSystem()
		{
			return static_cast<T*>(Systems[&typeid(T)]);
		}
	};
}


