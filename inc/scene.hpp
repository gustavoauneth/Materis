/*
 * Copyright (C) 2026 Gustavo Furtado
 *
 * This file is part of Materis
 * SDPX-License-Identifier: GPL-3.0-or-later
*/

#pragma once

namespace Materis {

    class Scene {

        public:

            virtual ~Scene() = default;
            virtual void init() = 0;
            virtual void update() = 0;
            virtual void render() = 0;
            
    };
}