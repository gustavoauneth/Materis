/*
 * Copyright (C) 2026 Gustavo Furtado
 *
 * This file is part of Materis
 * SDPX-License-Identifier: GPL-3.0-or-later
*/

#pragma once

#include <tyra>
#include <string>

class Camera {

    public:

        Camera();
        ~Camera();

        Tyra::Vec4 lookAt, position, unitCircle;

        float circleRotation;
        float circleLength;
        float pitch;
        float yaw;
        float sensitivity;
        float distance;
        float heightOffset;
        float followSpeed;

        const float speed = 40.0f;

        Tyra::CameraInfo3D getCameraInfo() {

            return Tyra::CameraInfo3D(&position, &lookAt);
        }

        void update(const Tyra::Vec4& targetPosition);

    private:

        void rotate();
        void updateLookAt(
            const Tyra::Vec4& targetPosition
        );
        void updateFollowPosition(
            const Tyra::Vec4& targetPosition
        );

};