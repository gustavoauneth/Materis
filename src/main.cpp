/*
 * Copyright (C) 2026 Gustavo Furtado
 *
 * This file is part of Materis
 * SDPX-License-Identifier: GPL-3.0-or-later
*/

#include <tyra>
#include "game.hpp"

int main() {

    Tyra::EngineOptions options;
    options.loadUsbDriver = true;

    Tyra::Engine engine(options);

    Materis::Game game(&engine);
    engine.run(&game);

    SleepThread();

    return 0;
}
