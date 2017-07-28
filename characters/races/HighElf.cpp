//
// Created by jwr8 on 7/24/17.
//

#include "HighElf.h"
#include "../../VirtualQuest.h"
#include "Languages.h"
#include <algorithm>

HighElf::HighElf() : Elf() {
    subRaceName_ = "High Elf";
}

int HighElf::getAbilityScore(Stats::ABILITY ability) {
    if (ability == Stats::ABILITY::INTELLIGENCE) {
        return Elf::getAbilityScore(ability) + 1;
    }
    return Elf::getAbilityScore(ability);
}

std::vector<std::string> HighElf::getLanguages() {
    std::vector<std::string>  languages = Elf::getLanguages();
    languages.push_back(bonusLanguage);
    return languages;
}

void HighElf::generateStats() {
    setBonusLanguage();
    Elf::generateStats();
}

void HighElf::setBonusLanguage() {
    std::string selectLanguageQuestion = "Select a bonus language:";
    std::vector<std::string> allLanguages = Languages::languages;
    std::vector<std::string> knownLanguages = Elf::getLanguages();
    std::vector<std::string> unknownLanguages;
    std::sort(allLanguages.begin(), allLanguages.end());
    std::sort(knownLanguages.begin(), knownLanguages.end());
    std::set_symmetric_difference(allLanguages.begin(), allLanguages.end(), knownLanguages.begin(),
                                  knownLanguages.end(), std::back_inserter(unknownLanguages));
    int languageChoice = VirtualQuest::selectOption(selectLanguageQuestion, unknownLanguages);
    bonusLanguage = unknownLanguages[languageChoice - 1];
}
