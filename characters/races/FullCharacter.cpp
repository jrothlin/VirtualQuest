//
// Created by jwr8 on 7/22/17.
//

#include <iostream>
#include "FullCharacter.h"
#include "../../dice.h"

const std::string FullCharacter::NO_SUBCLASS = "N/A";

FullCharacter::FullCharacter(std::string raceName, std::string subRaceName) : raceName_(raceName), subRaceName_(subRaceName) {
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

int FullCharacter::getAbilityScore(Stats::ABILITY ability) {
    return stats_->abilityScores[ability];
}

void FullCharacter::generateStats(Stats::SIZE size, int speed, std::vector<std::string> languages) {
    // While loop makes sure no player is way better or worse than any other
    while (abilityScoreTotal() < 67 || abilityScoreTotal() > 77) {
        stats_->abilityScores[Stats::ABILITY::CHARISMA] = FullCharacter::best3of4d6();
        stats_->abilityScores[Stats::ABILITY::CONSTITUTION] = FullCharacter::best3of4d6();
        stats_->abilityScores[Stats::ABILITY::DEXTERITY] = FullCharacter::best3of4d6();
        stats_->abilityScores[Stats::ABILITY::INTELLIGENCE] = FullCharacter::best3of4d6();
        stats_->abilityScores[Stats::ABILITY::STRENGTH] = FullCharacter::best3of4d6();
        stats_->abilityScores[Stats::ABILITY::WISDOM] = FullCharacter::best3of4d6();
    }
    std::cout << abilityScoreTotal() << std::endl;
    stats_->hitPoints = 20;
    stats_->level = 1;
    stats_->experience = 0;
    stats_->size = size;
    stats_->height = 0.0;
    stats_->weight = 0.0;
    stats_->speed = speed;
    for (std::string language : languages) {
        stats_->languages.push_back(language);
    }
}

int FullCharacter::abilityScoreTotal() {
    int total = 0;
    total += stats_->abilityScores[Stats::ABILITY::CHARISMA];
    total += stats_->abilityScores[Stats::ABILITY::CONSTITUTION];
    total += stats_->abilityScores[Stats::ABILITY::DEXTERITY];
    total += stats_->abilityScores[Stats::ABILITY::INTELLIGENCE];
    total += stats_->abilityScores[Stats::ABILITY::STRENGTH];
    total += stats_->abilityScores[Stats::ABILITY::WISDOM];
    return total;
}

int FullCharacter::best3of4d6() {
    int total = 0;
    int min = dice::d6();
    for (int i = 0; i < 3; i++) {
        int currentRoll = dice::d6();
        if (currentRoll < min) {
            total += min;
            min = currentRoll;
        } else {
            total += currentRoll;
        }
    }
    return total;
}

Stats *FullCharacter::getStats() {
    return stats_;
}
