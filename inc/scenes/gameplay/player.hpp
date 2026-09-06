/*
 * Copyright (C) 2026 Gustavo Furtado
 *
 * This file is part of Materis
 * SDPX-License-Identifier: GPL-3.0-or-later
*/

#pragma once

#include <tyra>
#include "components/entity.hpp"
#include "components/animation.hpp"

namespace Materis {

    class Player {

        public:

            void init();
            void update(float cameraYaw);

            std::shared_ptr<Materis::Entity> entity;

            float yaw = 0.0f;
            float targetYaw = 0.0f;
            float rotationSpeed = 32.0f;

        private:

            void updateMovement(float cameraYaw);
            void updateRotation();
            void updateAnimation();

            Materis::Animation stand;
            Materis::Animation running;

            bool isStanding = true;
            bool isRunning = false;
            bool wasStanding = false;
            bool wasRunning = false;
    };
}