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
    static const std::string NO_RACE;

    static const std::string NO_SUBRACE;

    FullCharacter();

    virtual std::string getRaceName();

    virtual std::string getSubRaceName();

    virtual int getAbilityScore(Stats::ABILITY);

    virtual Stats::SIZE getSize();

    virtual double getHeight();

    virtual double getWeight();

    virtual int getSpeed();

    virtual std::vector<std::string> getLanguages();

    virtual int getMaxHitPoints();

    virtual int getExperience();

    virtual int getLevel();

    Stats *getStats();

    virtual void generateStats();

protected:
    std::string raceName_;

    std::string subRaceName_;

    Stats *stats_;

private:
    int best3of4d6();

    int abilityScoreTotal();
};

#endif //VIRTUALQUEST_RACE_H
