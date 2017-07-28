//
// Created by jwr8 on 7/24/17.
//

#ifndef VIRTUALQUEST_WOODELF_H
#define VIRTUALQUEST_WOODELF_H


#include "Elf.h"

class WoodElf : public Elf {
public:
    WoodElf();

    virtual int getAbilityScore(Stats::ABILITY) override;

    virtual int getSpeed() override;
};

#endif //VIRTUALQUEST_WOODELF_H
