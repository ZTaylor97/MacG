#include "EntityManager.h"

namespace MacG
{
    Entity& EntityManager::AddEntity(std::string entityName, LayerType layer)
    {
        Entity* entity = new Entity(entityName, layer);
        entities.emplace(entityName, entity);
        return *entity;
    }

    Entity* EntityManager::GetEntityByName(std::string entityId) const
    {
        if (entities.find(entityId) == entities.end())
        {
            return NULL;
        }
        else {
            Entity* returnVal = entities.at(entityId);
        }
    }

    void EntityManager::ClearData() {
        for (auto& entity : entities)
        {
            entity.second->Destroy();
        }

        entities.clear();
    }

    void EntityManager::Update(float deltaTime) {
        for (auto& entity : entities) {
            entity.second->Update(deltaTime);
        }
        DestroyInactiveEntities();
    }

    void EntityManager::DestroyInactiveEntities()
    {
        for (auto& entity : entities)
        {
            if (!entity.second->IsActive())
            {
                entity.second->Destroy();
                entities.erase(entity.first);
            }
        }
    }

    void EntityManager::Render() {
    }

    bool EntityManager::HasNoEntities() const {
        return entities.size() == 0;
    }

    unsigned int EntityManager::GetEntityCount() const {
        return entities.size();
    }

    std::map<std::string, Entity*> EntityManager::GetEntities() const {
        return entities;
    }

    std::vector<Entity*> EntityManager::GetEntitiesByLayer(LayerType layer) const
    {
        std::vector<Entity*> result;
        for (auto& entity : entities)
        {
            if (entity.second->layer == layer) result.emplace_back(entity.second);
        }

        return result;
    }
}