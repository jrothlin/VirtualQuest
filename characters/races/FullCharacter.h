//
// Created by jwr8 on 7/22/17.
//

#ifndef VIRTUALQUEST_RACE_H
#define VIRTUALQUEST_RACE_H


#include <string>
#include <map>
#include "Stats.h"


class FullCharacter {
public:
    static const string FullCharacter::NO_SUBCLASS = "N/A";

    FullCharacter::FullCharacter(string, string);

    std::string getRaceName();

    std::string getSubRaceName();

    virtual int getAbilityScore(Stats::ABILITY);

protected:
    std::string raceName_;

    std::string subRaceName_;

    std::map abilityModifiers_;

    Stats *stats_;
};

#endif //VIRTUALQUEST_RACE_H
