/*
 * Copyright (C) 2026 Gustavo Furtado
 *
 * This file is part of Materis
 * SDPX-License-Identifier: GPL-3.0-or-later
*/

#include "context.hpp"

namespace Materis {

    static Tyra::Engine* engine = nullptr;
    static Tyra::Pad* pad = nullptr;

    void SetEngine(Tyra::Engine* t_engine) {

        engine = t_engine;
        pad = &t_engine->pad;
    }

    Tyra::Engine* GetEngine() {

        return engine;
    }

    Tyra::Pad* GetPad() {

        return pad;
    }
}