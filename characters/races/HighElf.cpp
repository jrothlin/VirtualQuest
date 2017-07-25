//
// Created by jwr8 on 7/24/17.
//

#include "HighElf.h"

HighElf::HighElf() : Elf("High Elf"){}

int HighElf::getAbilityScore(Stats::ABILITY ability) {
    if (ability == Stats::ABILITY::INTELLIGENCE) {
        return Elf::getAbilityScore(ability) + 1;
    }
    return Elf::getAbilityScore(ability);
}
