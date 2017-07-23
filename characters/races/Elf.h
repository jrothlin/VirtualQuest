//
// Created by jwr8 on 7/23/17.
//

#ifndef VIRTUALQUEST_ELF_H
#define VIRTUALQUEST_ELF_H


#include "Stats.h"
#include "FullCharacter.h"

class Elf : public FullCharacter {
public:
    Elf();

    Elf(std::string);

    int getAbilityScore(Stats::ABILITY) override;

};


#endif //VIRTUALQUEST_ELF_H
