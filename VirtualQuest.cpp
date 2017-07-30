//
// Created by jwr8 on 7/22/17.
//

#include "VirtualQuest.h"
#include "characters/races/Elf.h"
#include "characters/races/DrowElf.h"
#include "characters/races/HighElf.h"
#include "characters/races/WoodElf.h"
#include "stringutils.h"
#include "gameinfo.h"

void VirtualQuest::run() {
    cout << "Welcome to VirtualQuest!" << endl;
    string mainMenu = "Main menu";
    vector<string> mainMenuOptions = {
            "Play!",
            "Okay, explain this shit to me...",
            "Settings",
            "Exit"
    };
    while (true) {
        int choice = stringutils::selectOption(mainMenu, mainMenuOptions);

        switch (choice) {
            case 1:
                startGame();
                break;
            case 2:
                printTutorial();
                break;
            case 3:
                editSettings();
                break;
            default:
                return;
        }
    }
}


void VirtualQuest::startGame() {
    string racePrompt = "Choose your player's race";
    int raceChoice = stringutils::selectOption(racePrompt, gameinfo::races);
    mainPlayer = new MainPlayer("Joseph William Rothlin");
    switch (raceChoice) {
        case 1 :
            mainPlayer->character = new Elf();
            break;
        case 2 :
            mainPlayer->character = new DrowElf();
            break;
        case 3 :
            mainPlayer->character = new HighElf();
            break;
        case 4 :
            mainPlayer->character = new WoodElf();
            break;
    }
    mainPlayer->character->generateStats();
    printStats();
}

void VirtualQuest::printStats() {
    int formWidth = 100;
    cout << endl;
    printFormLine(formWidth, '+');
    cout << "| NAME: " << mainPlayer->getName();
    cout << "  |  LEVEL: " << mainPlayer->character->getLevel();
    cout << "  |  EXPERIENCE: " << mainPlayer->character->getExperience();
    cout << stringutils::constructNCharacterString(' ', formWidth - 40 - mainPlayer->getName().size()) << "|" << endl;
    printFormLine(formWidth, '|');
    cout << "| RACE: " << mainPlayer->character->getRaceName() << "  |  ";
    cout << "SUBRACE: " << mainPlayer->character->getSubRaceName();
    cout << stringutils::constructNCharacterString(' ', formWidth - 23 - mainPlayer->character->getRaceName().size() - mainPlayer->character->getSubRaceName().size()) << "|" << endl;
    printFormLine(formWidth, '|');
    cout << "| SIZE: " << mainPlayer->character->getSize() << "  |  ";
    cout << "HEIGHT: " << mainPlayer->character->getHeight() << "  |  ";
    cout << "WEIGHT: " << mainPlayer->character->getWeight();
    cout << stringutils::constructNCharacterString(' ', formWidth - 38) << "|" << endl;
    printFormLine(formWidth, '|');
    printFormLine(formWidth, '|');
    cout << "| ABILITIES |" << stringutils::constructNCharacterString(' ', formWidth - 14) << "|" << endl;
    cout << "|" << stringutils::constructNCharacterString('-', 11) << "+" << stringutils::constructNCharacterString(' ', formWidth - 14) << "|" << endl;
    cout << "| CHARISMA: " << mainPlayer->character->getAbilityScore(Stats::ABILITY::CHARISMA);
    cout << stringutils::constructNCharacterString(' ', formWidth - 13 - ((mainPlayer->character->getAbilityScore(Stats::ABILITY::CHARISMA) < 10) ? 1 : 2)) << "|" << endl;
    cout << "| CONSTITUTION: " << mainPlayer->character->getAbilityScore(Stats::ABILITY::CONSTITUTION);
    cout << stringutils::constructNCharacterString(' ', formWidth - 17 - ((mainPlayer->character->getAbilityScore(Stats::ABILITY::CONSTITUTION) < 10) ? 1 : 2)) << "|" << endl;
    cout << "| DEXTERITY: " <<  mainPlayer->character->getAbilityScore(Stats::ABILITY::DEXTERITY);
    cout << stringutils::constructNCharacterString(' ', formWidth - 14 - ((mainPlayer->character->getAbilityScore(Stats::ABILITY::DEXTERITY) < 10) ? 1 : 2)) << "|" << endl;
    cout << "| INTELLIGENCE: " << mainPlayer->character->getAbilityScore(Stats::ABILITY::INTELLIGENCE);
    cout << stringutils::constructNCharacterString(' ', formWidth - 17 - ((mainPlayer->character->getAbilityScore(Stats::ABILITY::INTELLIGENCE) < 10) ? 1 : 2)) << "|" << endl;
    cout << "| STRENGTH: " << mainPlayer->character->getAbilityScore(Stats::ABILITY::STRENGTH);
    cout << stringutils::constructNCharacterString(' ', formWidth - 13 - ((mainPlayer->character->getAbilityScore(Stats::ABILITY::STRENGTH) < 10) ? 1 : 2)) << "|" << endl;
    cout << "| WISDOM: " << mainPlayer->character->getAbilityScore(Stats::ABILITY::WISDOM);
    cout << stringutils::constructNCharacterString(' ', formWidth - 11 - ((mainPlayer->character->getAbilityScore(Stats::ABILITY::WISDOM) < 10) ? 1 : 2)) << "|" << endl;
    printFormLine(formWidth, '|');
    cout << "SPEED: " << mainPlayer->character->getSpeed() << endl;
    cout << "LANGUAGES: ";
    for (string language : mainPlayer->character->getLanguages()) {
        cout << language << ", ";
    }
    cout << endl;
    cout << "HIT POINTS: " << mainPlayer->character->getMaxHitPoints() << endl;
}

void VirtualQuest::printFormLine(int width, char end) {
    cout << end << stringutils::constructNCharacterString('-', width - 2) << end << endl;
}

void VirtualQuest::printTutorial() {
    cout << "Here is a tutorial" << endl;
}

void VirtualQuest::editSettings() {
    Settings *settings = new Settings();
    while (true) {
        cout << "Here are the current settings:" << endl;
        cout << "Difficulty: ";
        switch (settings->getDifficulty()) {
            case Settings::HARD:
                cout << "Hard" << endl;
                break;
            case Settings::NORMAL:
                cout << "Normal" << endl;
                break;
            case Settings::EASY:
            default:
                break;
        }
        string requestEditSettings = "Would you like to edit the current settings?";
        bool choice = stringutils::askYesOrNoQuestion(requestEditSettings);
        if (choice) {
            editSettings(settings);
        } else {
            delete settings;
            return;
        }
    }
}

void VirtualQuest::editSettings(Settings *settings) {
    string selectDifficulty = "Select a difficulty";
    vector<string> difficulties = {
            "Easy",
            "Normal",
            "Hard"
    };
    int choice = stringutils::selectOption(selectDifficulty, difficulties);
    switch (choice) {
        case 1:
            settings->setDifficulty(Settings::EASY);
            break;
        case 2:
            settings->setDifficulty(Settings::NORMAL);
            break;
        case 3:
            settings->setDifficulty(Settings::HARD);
            break;
    }
}
