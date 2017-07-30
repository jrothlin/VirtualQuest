//
// Created by jwr8 on 7/22/17.
//

#include <iostream>
#include "FullCharacter.h"
#include "../../dice.h"

const std::string FullCharacter::NO_RACE = "N/A";

const std::string FullCharacter::NO_SUBRACE = "N/A";

FullCharacter::FullCharacter() {
    stats_ = new Stats();
    raceName_ = NO_RACE;
    subRaceName_ = NO_SUBRACE;
    stats_->abilityScores = {
            {Stats::ABILITY::CHARISMA, 0},
            {Stats::ABILITY::CONSTITUTION, 0},
            {Stats::ABILITY::DEXTERITY, 0},
            {Stats::ABILITY::INTELLIGENCE, 0},
            {Stats::ABILITY::STRENGTH, 0},
            {Stats::ABILITY::WISDOM, 0},
    };
    stats_->maxHitPoints = 0;
    stats_->level = 1;
    stats_->experience = 0;
    stats_->height = 0.0;
    stats_->weight = 0.0;
    stats_->speed = 0;
    stats_->size = Stats::MEDIUM;
    stats_->languages = {};
}

std::string FullCharacter::getRaceName() {
    return raceName_;
}

std::string FullCharacter::getSubRaceName() {
    return subRaceName_;
}

int FullCharacter::getAbilityScore(Stats::ABILITY ability) {
    return stats_->abilityScores[ability];
}

Stats::SIZE FullCharacter::getSize() {
    return stats_->size;
}

double FullCharacter::getHeight() {
    return stats_->height;
}

double FullCharacter::getWeight(){
    return stats_->weight;
}

int FullCharacter::getSpeed() {
    return stats_->speed;
}

std::vector<std::string> FullCharacter::getLanguages(){
    return stats_->languages;
}

Stats *FullCharacter::getStats() {
    return stats_;
}

void FullCharacter::generateStats() {
    // While loop makes sure no player is way better or worse than any other
    while (abilityScoreTotal() < 67 || abilityScoreTotal() > 77) {
        stats_->abilityScores[Stats::ABILITY::CHARISMA] = FullCharacter::best3of4d6();
        stats_->abilityScores[Stats::ABILITY::CONSTITUTION] = FullCharacter::best3of4d6();
        stats_->abilityScores[Stats::ABILITY::DEXTERITY] = FullCharacter::best3of4d6();
        stats_->abilityScores[Stats::ABILITY::INTELLIGENCE] = FullCharacter::best3of4d6();
        stats_->abilityScores[Stats::ABILITY::STRENGTH] = FullCharacter::best3of4d6();
        stats_->abilityScores[Stats::ABILITY::WISDOM] = FullCharacter::best3of4d6();
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

int FullCharacter::getMaxHitPoints() {
    return stats_->maxHitPoints;
}

int FullCharacter::getExperience() {
    return stats_->experience;
}

int FullCharacter::getLevel() {
    return stats_->level;
}
