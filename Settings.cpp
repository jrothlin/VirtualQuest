//
// Created by jwr8 on 7/22/17.
//

#include "Settings.h"

Settings::Settings() {
    difficulty = NORMAL;
}

Settings::DIFFICULTY Settings::getDifficulty() {
    return difficulty;
}

void Settings::setDifficulty(DIFFICULTY newDifficulty) {
    difficulty = newDifficulty;
}
