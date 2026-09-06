/*
 * Copyright (C) 2026 Gustavo Furtado
 *
 * This file is part of Materis
 * SDPX-License-Identifier: GPL-3.0-or-later
*/

#include "context.hpp"
#include "scenes/gameplay/player.hpp"
#include "utils.hpp"

namespace Materis {

    void Player::init() {

        stand.framesSequence = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
                               11, 12, 13, 14, 15, 16, 17, 18, 19,
                               20, 21, 22, 23, 24, 25, 26, 27, 28,
                               29, 30, 31, 32, 33, 34, 35, 36, 37,
                               38, 39};

        running.framesSequence = {40, 41, 42, 43, 44, 45};

        entity = std::make_shared<Materis::Entity>();
        entity->position = Tyra::Vec4(1600.0f, 0.0f, 0.0f, 1.0f);
        entity->init("character/player.md2", "/character/", 10.0f);
        entity->setAnimation(stand);
    }
    
    void Player::update(float cameraYaw) {

        updateMovement(cameraYaw);
        updateRotation();
        updateAnimation();
    }

    void Player::updateMovement(float cameraYaw) {

        const auto& leftJoy = Materis::GetEngine()->pad.getLeftJoyPad();

        const float center = 128.0f;
        const float deadzone = 20.0f;

        float horizontal = static_cast<float>(leftJoy.h) - center;
        float vertical = center - static_cast<float>(leftJoy.v);

        if (
            horizontal > -deadzone &&
            horizontal < deadzone
        ) {
            horizontal = 0.0f;
        }

        if (
            vertical > -deadzone &&
            vertical < deadzone
        ) {
            vertical = 0.0f;
        }

        if (horizontal == 0.0f && vertical == 0.0f) {

            wasStanding = isStanding;
            wasRunning = isRunning;
            isStanding = true;
            isRunning = false;

            return;
        }
        else {

            wasStanding = isStanding;
            wasRunning = isRunning;
            isStanding = false;
            isRunning = true;
        }

        horizontal /= 127.0f;
        vertical /= 127.0f;

        const float cameraRad = Materis::Utils::degreesToRadians(
            cameraYaw
        );

        Tyra::Vec4 cameraForward(
            Tyra::Math::cos(cameraRad),
            0.0f,
            Tyra::Math::sin(cameraRad),
            0.0f
        );

        Tyra::Vec4 cameraRight(
            -Tyra::Math::sin(cameraRad),
            0.0f,
            Tyra::Math::cos(cameraRad),
            0.0f
        );

        cameraForward.normalize();
        cameraForward.normalize();

        Tyra::Vec4 direction = 
            cameraForward * vertical +
            cameraRight * horizontal;

        direction.normalize();
   
        const float movementAngle = Tyra::Math::atan2(
            direction.x,
            direction.z
        );

        targetYaw = Materis::Utils::radiansToDegrees(movementAngle) + 180.0f;

        if (targetYaw >= 360.0f) {

            targetYaw -= 360.0f;
        }

        if (targetYaw < 0.0f)
        {
            targetYaw += 360.0f;
        }
        
        const float moveSpeed = 25.0f;

        entity->position += direction * moveSpeed;

        entity->getMesh()->rotation.identity();
        entity->getMesh()->rotation.rotateX(-1.566f);
        entity->getMesh()->rotation.rotateY(1.566f);
        entity->getMesh()->rotation.rotateY(
            Materis::Utils::degreesToRadians(yaw)
        );

    }

    void Player::updateRotation() {
        
        float delta = targetYaw - yaw;

        if (delta > 180.0f) {

            delta -= 360.0f;
        }
        
        if (delta < -180.0f) {

            delta += 360.0f;
        }

        yaw += delta * rotationSpeed * 0.016f;

        if (yaw >= 360.0f) {

            yaw -= 360.0f;
        }
        if (yaw < 0.0f) {

            yaw += 360.0f;
        }
        
        auto& rotation = entity->getMesh()->rotation;

        rotation.identity();
        rotation.rotateX(-1.566f);
        rotation.rotateY(1.566f);

        rotation.rotateY(
            Materis::Utils::degreesToRadians(yaw)
        );
    }

    void Player::updateAnimation() {

        if (wasRunning && isStanding) {
        
            entity->setAnimation(stand);
        }
        else if (wasStanding && isRunning) {

            entity->setAnimation(running);
        }
    }
}