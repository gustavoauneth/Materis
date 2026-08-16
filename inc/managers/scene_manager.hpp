/*
 * Copyright (C) 2026 Gustavo Furtado
 *
 * This file is part of Materis
 * SDPX-License-Identifier: GPL-3.0-or-later
*/

#pragma once

#include <tyra>
#include "scene.hpp"

namespace Materis {

    extern std::unique_ptr<Materis::Scene> currentScene;

    void setScene(std::unique_ptr<Materis::Scene> scene);
    void handleScene();
}