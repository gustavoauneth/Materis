/*
 * Copyright (C) 2026 Gustavo Furtado
 *
 * This file is part of Materis
 * SDPX-License-Identifier: GPL-3.0-or-later
*/

#pragma once

#include <tyra>
#include "scene.hpp"
#include "managers/scene_manager.hpp"

namespace Materis {

    std::unique_ptr<Materis::Scene> currentScene;

    void setScene(std::unique_ptr<Materis::Scene> scene) {

        currentScene = std::move(scene);

        currentScene->init();
    }

    void handleScene() {

        if (currentScene) {

            currentScene->update();
            currentScene->render();
        }
    }
}