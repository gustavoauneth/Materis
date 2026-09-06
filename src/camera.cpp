/*
 * Copyright (C) 2026 Gustavo Furtado
 *
 * This file is part of Materis
 * SDPX-License-Identifier: GPL-3.0-or-later
*/

#include "camera.hpp"
#include "utils.hpp"
#include "game.hpp"
#include "context.hpp"

Camera::Camera()
  : lookAt(0.0f),
    position(-2767.37, 30.0f, -8166.36),
    circleRotation(0.0f),
    circleLength(30.0f),
    pitch(15.0f),
    yaw(270.0f),
    sensitivity(4.58425f),
    distance(1500.0f),
    heightOffset(100.0f),
    followSpeed(0.1f) {}

Camera::~Camera() {}

void Camera::update(const Tyra::Vec4& targetPosition) {

    rotate();
    updateFollowPosition(targetPosition);
    updateLookAt(targetPosition);

    // TYRA_LOG("X: " + std::to_string(position.x) + " Y: " + std::to_string(position.y) + " Z: " + std::to_string(position.z));
    // TYRA_LOG("RX: " + std::to_string(lookAt.x) + " RY: " + std::to_string(lookAt.y) + " RZ: " + std::to_string(lookAt.z));
}

void Camera::rotate() {

    const auto& rightJoy = Materis::GetEngine()->pad.getRightJoyPad();

    if (rightJoy.h <= 100) {
        yaw -= sensitivity;
    } 
    else if (rightJoy.h >= 200) {
        yaw += sensitivity;
    }

    if (rightJoy.v <= 100) {
        pitch += sensitivity;
    } 
    else if (rightJoy.v >= 200) {
        pitch -= sensitivity;
    }

    if (pitch > 80.0F) {
        pitch = 80.0F; 
    }
    else if (pitch < -30.0F) {
        pitch = -30.0F;
    }

    if (yaw >= 360.0f) {

        yaw -= 360.0f;
    }
    else if (yaw < 0.0f) {

        yaw += 360.0f;
    }
}

void Camera::updateFollowPosition(const Tyra::Vec4& targetPosition) {

    const float yawRad = Materis::Utils::degreesToRadians(
        yaw
    );

    const float pitchRad = Materis::Utils::degreesToRadians(
        pitch
    );

    Tyra::Vec4 direction(
        Tyra::Math::cos(pitchRad) * Tyra::Math::cos(yawRad),
        Tyra::Math::sin(pitchRad),
        Tyra::Math::cos(pitchRad) * Tyra::Math::sin(yawRad)
    );

    direction.normalize();

    Tyra::Vec4 desiredPosition = targetPosition;

    desiredPosition.y += heightOffset;

    desiredPosition -= direction * distance;

    position +=
        (desiredPosition - position)
        * followSpeed;
}

void Camera::updateLookAt(const Tyra::Vec4& targetPosition) {

    Tyra::Vec4 target = targetPosition;

    target.y += heightOffset;

    lookAt += (target - lookAt) * 0.15f;
}