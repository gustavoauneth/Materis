/*
 * Copyright (C) 2026 Gustavo Furtado
 *
 * This file is part of Materis
 * SDPX-License-Identifier: GPL-3.0-or-later
*/

#include "game.hpp"
#include "context.hpp"

namespace Materis {

    Game::Game(Tyra::Engine* t_engine) { 
        
        Materis::SetEngine(t_engine);
    }

    Game::~Game() {

    }

    void Game::init() { 
        
        TYRA_LOG("Hello!"); 
    }

    void Game::loop() { 
        
        TYRA_LOG("Loop!");
    }
}