//
// Created by jwr8 on 7/24/17.
//

#include "DrowElf.h"

DrowElf::DrowElf() : Elf() {
    subRaceName_ = "Drow";
}

int DrowElf::getAbilityScore(Stats::ABILITY ability) {
    if (ability == Stats::ABILITY::CHARISMA) {
        return Elf::getAbilityScore(ability) + 1;
    }
    return Elf::getAbilityScore(ability);
}

std::vector<std::string> DrowElf::getLanguages() {
    std::vector<std::string> languages = Elf::getLanguages();
    languages.push_back("Drow Hand Signs");
    return languages;
}
