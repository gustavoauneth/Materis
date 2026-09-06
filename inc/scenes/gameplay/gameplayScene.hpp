/*
 * Copyright (C) 2026 Gustavo Furtado
 *
 * This file is part of Materis
 * SDPX-License-Identifier: GPL-3.0-or-later
*/

#pragma once

#include "scene.hpp"
#include "camera.hpp"
#include "components/entity.hpp"
#include "components/object.hpp"
#include "managers/scene_manager.hpp"
#include "scenes/gameplay/player.hpp"

namespace Materis {

    class Gameplay : public Materis::Scene {

        public:

            void init() override;
            void update() override;
            void render() override;

        private:

            Materis::Player player;
            
            Tyra::StaticPipeline stapip;
            Tyra::StaPipOptions stapipOptions;
            Tyra::DynamicPipeline dynpip;
            Tyra::DynPipOptions dynpipOptions;
            Camera camera;
            std::vector<std::unique_ptr<Object>> objects;
            std::vector<std::shared_ptr<Entity>> entities;
    };
}