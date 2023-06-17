#pragma once

#include "EntityManager.h"
#include "ManagedEntity.h"

namespace Simp1e::ECS {

    class ManagedEntityManager {
        EntityManager _entityManager;

    public:
        ManagedEntity CreateEntity() {
            return ManagedEntity(_entityManager, _entityManager.CreateEntity());
        }

        ManagedEntity Get(Entity entity) { return ManagedEntity(_entityManager, entity); }

        bool Exists(Entity entity) { return _entityManager.HasEntity(entity); }

        ReadonlyEntityComponentCollection GetComponents(Entity entity) {
            return _entityManager.GetEntityComponents(entity);
        }

        template <typename T>
        void AddComponent(Entity entity, const ComponentType& componentType) {
            _entityManager.AddComponent(entity, componentType);
        }

        template <typename T>
        void AddComponent(Entity entity, const ComponentType& componentType, T&& component) {
            _entityManager.AddComponent(entity, componentType, std::forward<T>(component));
        }

        template <typename T>
        void AddComponent(Entity entity, T&& component) {
            _entityManager.AddComponent(entity, std::forward<T>(component));
        }

        template <typename T>
        void AddComponent(Entity entity, const ComponentType& componentType, T* component) {
            _entityManager.AddComponent(entity, componentType, component);
        }

        template <typename T>
        void AddComponent(Entity entity, T* component) {
            _entityManager.AddComponent(entity, component);
        }

        template <typename T>
        T* GetComponent(Entity entity, const ComponentType& componentType) {
            return _entityManager.GetComponent<T>(entity, componentType);
        }

        template <typename T>
        T* GetComponent(Entity entity) {
            return _entityManager.GetComponent<T>(entity, T::GetComponentType());
        }

        std::unordered_map<Entity, ComponentPointer>& GetComponents(
            const ComponentType& componentType
        ) {
            return _entityManager.GetComponents(componentType);
        }

        template <typename T>
        std::unordered_map<Entity, ComponentPointer>& GetComponents() {
            return _entityManager.GetComponents<T>();
        }

        template <typename T>
        bool HasComponent(Entity entity, const ComponentType& componentType) {
            return _entityManager.HasComponent<T>(entity, componentType);
        }

        template <typename T>
        bool HasComponent(Entity entity) {
            return _entityManager.HasComponent<T>(entity, T::GetComponentType());
        }

        template <typename T>
        void RemoveComponent(Entity entity, const ComponentType& componentType) {
            _entityManager.RemoveComponent<T>(entity, componentType);
        }

        template <typename T>
        void RemoveComponent(Entity entity) {
            _entityManager.RemoveComponent<T>(entity, T::GetComponentType());
        }

        void RemoveEntity(Entity entity) { _entityManager.RemoveEntity(entity); }

        void Clear() { _entityManager.Clear(); }
    };
}
