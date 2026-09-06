/*
 * Copyright (C) 2026 Gustavo Furtado
 *
 * This file is part of Materis
 * SDPX-License-Identifier: GPL-3.0-or-later
*/

#pragma once

#include <tyra>
#include <functional>

namespace Materis {

    class Animation {

        public:

            bool loop = true;
            std::vector<u32> framesSequence;
            void animationCallback(const Tyra::AnimationSequenceCallback& callback);
            std::function<void()> onNextFrame;
            std::function<void()> onLoop;
            std::function<void()> onEnd;

    };
}