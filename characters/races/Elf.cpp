//
// Created by jwr8 on 7/23/17.
//

#include "Elf.h"

Elf::Elf() : FullCharacter("Elf", FullCharacter::NO_SUBCLASS) {}

Elf::Elf(std::string subRaceName) : FullCharacter("Elf", subRaceName) {}

int Elf::getAbilityScore (Stats::ABILITY ability) {
    if (ability == Stats::ABILITY::DEXTERITY) {
        return FullCharacter::getAbilityScore(ability) + 2;
    }
    return FullCharacter::getAbilityScore(ability);
}
