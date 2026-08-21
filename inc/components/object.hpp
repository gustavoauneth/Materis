/*
 * Copyright (C) 2026 Gustavo Furtado
 *
 * This file is part of Materis
 * SDPX-License-Identifier: GPL-3.0-or-later
*/

#pragma once

#include <tyra>

namespace Materis {

    class Object {

        public:

            Object();
            ~Object();

            void init(const char* meshPath, const char* texturePath, float scale);
            void update();
            void render(Tyra::StaticPipeline& pipeline, Tyra::StaPipOptions& stapipOptions);

            Tyra::Vec4 position;

        private:

            std::unique_ptr<Tyra::StaticMesh> mesh;

    };
}