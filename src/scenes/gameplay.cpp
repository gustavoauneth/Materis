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

        stapipOptions.frustumCulling = Tyra::PipelineFrustumCulling_Precise;
        dynpipOptions.frustumCulling = Tyra::PipelineFrustumCulling_Precise;

        std::unique_ptr<Object> cube = std::make_unique<Object>();
        cube->position = Tyra::Vec4(0.0f, 0.0f, 0.0f, 1.0f);
        cube->init("placeholder.obj", "/", 20.0f);

        objects.push_back(std::move(cube));

        stapip.setRenderer(&engine->renderer.core);
        dynpip.setRenderer(&engine->renderer.core);

        TYRA_LOG("Gameplay init");
    }

    void Gameplay::update() {

        camera.update();

        for (std::unique_ptr<Object>& object : objects) {

            object->update();
        }

        TYRA_LOG("Gameplay loop");
    }

    void Gameplay::render() {

        Tyra::Engine* engine = Materis::GetEngine();
        Tyra::Renderer& renderer = Materis::GetEngine()->renderer;

        renderer.beginFrame(camera.getCameraInfo());

        renderer.renderer3D.usePipeline(stapip);

        for (std::unique_ptr<Object>& object : objects) {

            object->render(stapip, stapipOptions);
        }

        renderer.renderer3D.usePipeline(dynpip);

        TYRA_LOG("Gameplay render");
        renderer.endFrame();
    }
}