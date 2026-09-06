/*
 * Copyright (C) 2026 Gustavo Furtado
 *
 * This file is part of Materis
 * SDPX-License-Identifier: GPL-3.0-or-later
*/

#include "components/animation.hpp"

namespace Materis {

    void Animation::animationCallback(const Tyra::AnimationSequenceCallback& callback) {

        switch (callback) {

            case Tyra::AnimationSequenceCallback_NextFrame: {

                if (onNextFrame) {

                    onNextFrame();
                }

                break;
            }
            case Tyra::AnimationSequenceCallback_Loop: {

                if (onLoop) {

                    onLoop();
                }

                break;
            }
            case Tyra::AnimationSequenceCallback_End: {

                if (onEnd) {

                    onEnd();
                }

                break;
            }
        }
    }
}