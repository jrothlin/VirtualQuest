//
// Created by jwr8 on 7/22/17.
//

#ifndef VIRTUALQUEST_STATS_H
#define VIRTUALQUEST_STATS_H


#include <string>
#include <map>
#include <list>

using namespace std;

class Stats {
public:
    enum ABILITY : int {
        STRENGTH = 0,
        DEXTERITY = 1,
        CONSTITUTION = 2,
        INTELLIGENCE = 3,
        WISDOM = 4,
        CHARISMA = 5,
    };

    enum SIZE : int {
        SMALL = 0,
        MEDIUM = 1,
        LARGE = 2,
    };

    map AbilityScores;

    int hitPoints;

    int level;

    int experience;

    SIZE size;

    float height;

    int speed;

    list<string> languages;
};


#endif //VIRTUALQUEST_STATS_H
