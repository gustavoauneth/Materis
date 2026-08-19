/*
 * Copyright (C) 2026 Gustavo Furtado
 *
 * This file is part of Materis
 * SDPX-License-Identifier: GPL-3.0-or-later
*/

#include <tyra>
#include "context.hpp"
#include "scenes/gameplay.hpp"

namespace Materis {

    void Gameplay::init() {

        Tyra::Renderer& renderer = Materis::GetEngine()->renderer;

        renderer.setClearScreenColor(Tyra::Color(122, 202, 255));

        TYRA_LOG("Gameplay init");
    }

    void Gameplay::update() {

        TYRA_LOG("Gameplay loop");
    }

    void Gameplay::render() {

        Tyra::Renderer& renderer = Materis::GetEngine()->renderer;

        renderer.beginFrame();
        TYRA_LOG("Gameplay render");
        renderer.endFrame();
    }
}