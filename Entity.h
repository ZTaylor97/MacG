#pragma once

#include <vector>
#include <string>
#include <map>
#include <typeinfo>

#include "Constants.h"

#include "Component.h"

namespace MacG 
{
    class Component;
	class Entity
	{
	private:
		bool isActive;
		std::vector<Component*> components;
		std::map<const std::type_info*, Component*> componentTypeMap;
	public:
		const std::string name;
		const LayerType layer;

        Entity(std::string entityName, LayerType layer);

		void Update(float deltaTime);
		void Destroy();
		bool IsActive() const { return isActive;}

        template <typename T, typename... TArgs>
        T& AddComponent(TArgs&&... args) {
            T* newComponent(new T(std::forward<TArgs>(args)...));
            newComponent->owner = this;
            components.emplace_back(newComponent);
            componentTypeMap[&typeid(*newComponent)] = newComponent;
            newComponent->Initialize();
            return *newComponent;
        }

        template <typename T>
        bool HasComponent() const
        {
            return componentTypeMap.count(&typeid(T));
        }

        template <typename T>
        T* GetComponent() {
            return static_cast<T*>(componentTypeMap[&typeid(T)]);
        }
	};
}


