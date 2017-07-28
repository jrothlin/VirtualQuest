//
// Created by jwr8 on 7/23/17.
//

#include "Elf.h"

Elf::Elf() : FullCharacter() {
    raceName_ = "Elf";
}

int Elf::getAbilityScore (Stats::ABILITY ability) {
    if (ability == Stats::ABILITY::DEXTERITY) {
        return FullCharacter::getAbilityScore(ability) + 2;
    }
    return FullCharacter::getAbilityScore(ability);
}

int Elf::getSpeed() {
    return FullCharacter::getSpeed() + 30;
}

std::vector<std::string> Elf::getLanguages() {
    std::vector<std::string> languages = FullCharacter::getLanguages();
    languages.push_back("Common");
    languages.push_back("Elvish");
    return languages;
}
