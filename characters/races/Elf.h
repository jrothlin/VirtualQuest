//
// Created by jwr8 on 7/23/17.
//

#ifndef VIRTUALQUEST_ELF_H
#define VIRTUALQUEST_ELF_H


#include "../Stats.h"
#include "../FullCharacter.h"

// TODO: have Elf extend Race once FullCharacter moves some of it's implementation to Race.cc
class Elf : public FullCharacter {
public:
    Elf();

    virtual int getAbilityScore(Stats::ABILITY) override;

    virtual int getSpeed() override;

    virtual std::vector<std::string> getLanguages() override;
};


#endif //VIRTUALQUEST_ELF_H
