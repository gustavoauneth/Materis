/*
 * Copyright (C) 2026 Gustavo Furtado
 *
 * This file is part of Materis
 * SDPX-License-Identifier: GPL-3.0-or-later
*/

#pragma once

#include <tyra>
#include "components/animation.hpp"

namespace Materis {

    class Entity {

        public:

            Entity();
            ~Entity();

            void init(const char* meshPath, const char* texturePath, float scale);
            void update();
            void render(Tyra::DynamicPipeline& pipeline, Tyra::DynPipOptions& dynpipOptions);
            void setAnimation(Materis::Animation& animation);
            std::shared_ptr<Tyra::DynamicMesh>& getMesh();

            Tyra::Vec4 position;

        private:

            std::shared_ptr<Tyra::DynamicMesh> mesh;
        
    };
}