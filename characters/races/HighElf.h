//
// Created by jwr8 on 7/24/17.
//

#ifndef VIRTUALQUEST_HIGHELF_H
#define VIRTUALQUEST_HIGHELF_H


#include "Elf.h"

class HighElf : public Elf {
public:
    HighElf();

    virtual int getAbilityScore(Stats::ABILITY) override;

    virtual std::vector<std::string> getLanguages() override;

    virtual void generateStats() override;

private:
    std::string bonusLanguage;

    void setBonusLanguage();
};


#endif //VIRTUALQUEST_HIGHELF_H
