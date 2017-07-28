//
// Created by jwr8 on 7/24/17.
//

#include "WoodElf.h"

WoodElf::WoodElf() : Elf() {
    subRaceName_ = "Wood Elf";
}

int WoodElf::getAbilityScore(Stats::ABILITY ability) {
    if (ability == Stats::ABILITY::WISDOM) {
        return Elf::getAbilityScore(ability) + 1;
    }
    return Elf::getAbilityScore(ability);
}

int WoodElf::getSpeed() {
    return Elf::getSpeed() + 5;
}
