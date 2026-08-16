/*
 * Copyright (C) 2026 Gustavo Furtado
 *
 * This file is part of Materis
 * SDPX-License-Identifier: GPL-3.0-or-later
*/

#pragma once

#include <tyra>

namespace Materis {

    class Game : public Tyra::Game {

        public:

            Game(Tyra::Engine* t_engine);
            ~Game();

            void init();
            void loop();

    };
}