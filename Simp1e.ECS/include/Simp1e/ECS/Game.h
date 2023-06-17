#pragma once

#include <functional>
#include <unordered_map>

#include "EventManager.h"
#include "ManagedEntityManager.h"
#include "SystemManager.h"

namespace Simp1e::ECS {

    class Game {
        ManagedEntityManager _entityManager;
        EventManager         _eventManager;
        SystemManager        _systemManager;

    public:
        ManagedEntityManager& Entities() { return _entityManager; }
        EventManager&         Events() { return _eventManager; }
        SystemManager&        Systems() { return _systemManager; }

        void Update() { _systemManager.Update(); }

        void Clear() {
            _entityManager.Clear();
            _eventManager.Clear();
            _systemManager.Clear();
        }
    };
}
