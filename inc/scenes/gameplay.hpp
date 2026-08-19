/*
 * Copyright (C) 2026 Gustavo Furtado
 *
 * This file is part of Materis
 * SDPX-License-Identifier: GPL-3.0-or-later
*/

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