#pragma once

#include "scene.hpp"
#include "managers/scene_manager.hpp"

namespace Materis {

    class Gameplay : public Materis::Scene {

        public:

            void init() override;
            void update() override;
            void render() override;
            
    };
}