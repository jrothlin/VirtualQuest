//
// Created by jwr8 on 7/22/17.
//

#include "FullCharacter.h"


FullCharacter::FullCharacter(string raceName, string subRaceName) : raceName_(raceName), subRaceName_(subRaceName) {
    abilityModifiers_ = {
            {Stats::ABILITY::CHARISMA, 0},
            {Stats::ABILITY::CONSTITUTION, 0},
            {Stats::ABILITY::DEXTERITY, 0},
            {Stats::ABILITY::INTELLIGENCE, 0},
            {Stats::ABILITY::STRENGTH, 0},
            {Stats::ABILITY::WISDOM, 0},
    };
    stats_ = new Stats();
}
