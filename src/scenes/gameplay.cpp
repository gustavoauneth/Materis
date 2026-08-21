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

        renderOptions.frustumCulling = Tyra::PipelineFrustumCulling_Precise;

        cube.position = Tyra::Vec4(0.0f, 0.0f, 0.0f, 1.0f);
        cube.init("placeholder.obj", "/", 20.0f);

        TYRA_LOG("Gameplay init");
    }

    void Gameplay::update() {

        camera.update();
        cube.update();

        TYRA_LOG("Gameplay loop");
    }

    void Gameplay::render() {

        Tyra::Engine* engine = Materis::GetEngine();
        Tyra::Renderer& renderer = Materis::GetEngine()->renderer;

        stapip.setRenderer(&engine->renderer.core);

        renderer.beginFrame(camera.getCameraInfo());

        renderer.renderer3D.usePipeline(stapip);

        cube.render(stapip, renderOptions);

        TYRA_LOG("Gameplay render");
        renderer.endFrame();
    }
}