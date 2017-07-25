//
// Created by jwr8 on 7/24/17.
//

#ifndef VIRTUALQUEST_DROWELF_H
#define VIRTUALQUEST_DROWELF_H


#include "Elf.h"

class DrowElf : public Elf {
public:
    DrowElf();

    virtual int getAbilityScore(Stats::ABILITY) override;
};


#endif //VIRTUALQUEST_DROWELF_H
