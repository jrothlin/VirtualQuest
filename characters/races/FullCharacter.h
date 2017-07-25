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
    static const std::string NO_SUBCLASS;

    FullCharacter(std::string, std::string);

    std::string getRaceName();

    std::string getSubRaceName();

    virtual int getAbilityScore(Stats::ABILITY);

    void generateStats(Stats::SIZE, int, std::vector<std::string>);

    Stats *getStats();

protected:
    std::string raceName_;

    std::string subRaceName_;

    std::map<Stats::ABILITY, int> abilityModifiers_;

    Stats *stats_;

private:
    int best3of4d6();

    int abilityScoreTotal();
};

#endif //VIRTUALQUEST_RACE_H
