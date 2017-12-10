//
// Created by jwr8 on 7/23/17.
//

#include <cstdlib>
#include "dice.h"

// TODO: create dice objects which has a roll function as well as a max roll or numSides function
namespace dice {
    int d20() {
        return rand() % 20 + 1;
    }

    int d12() {
        return rand() % 12 + 1;
    }

    int d10() {
        return rand() % 10 + 1;
    }

    int d8() {
        return rand() % 8 + 1;
    }

    int d6() {
        return rand() % 6 + 1;
    }

    int d4() {
        return rand() % 4 + 1;
    }
}  // namespace dice
