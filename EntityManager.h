#pragma once
#include "Entity.h"
#include "Component.h"

#include <vector>

namespace MacG
{
    class EntityManager {
    private:
        std::map<std::string, Entity*> entities;
    public:
        void ClearData();
        void Update(float deltaTime);
        void Render();
        bool HasNoEntities() const;
        unsigned int GetEntityCount() const;
        Entity* GetEntityByName(std::string entityId) const;
        std::map<std::string, Entity*> GetEntities() const;
        std::vector<Entity*> GetEntitiesByLayer(LayerType layer) const;

        template<typename T>
        std::vector<Entity*> GetEntitiesByComponent()
        {
            std::vector<Entity*> returnEntities;

            for (auto& entity : entities)
            {
                if (entity.second->HasComponent<T>())
                {
                    returnEntities.emplace_back(entity.second);
                }
            }

            return returnEntities;
        }

        Entity& AddEntity(std::string entityName, LayerType layer);
        void DestroyInactiveEntities();
    };
}

