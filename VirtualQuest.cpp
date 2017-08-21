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

// TODO : Change this method to use CharacterSheetBuilder once its implemented
void VirtualQuest::printStats() {
    int formWidth = 100;
    cout << endl;
    printFormLine(formWidth, '+');
    std::string nameLine = "| NAME: " + mainPlayer->getName();
    nameLine += "  |  LEVEL: " + mainPlayer->character->getLevel();
    nameLine += "  |  EXPERIENCE: " + mainPlayer->character->getExperience();
    cout << nameLine << stringutils::constructNCharacterString(' ', formWidth - nameLine.size() - 1) << "|" << endl;
    printFormLine(formWidth, '|');
    std::string raceLine = "| RACE: " + mainPlayer->character->getRaceName() + "  |  ";
    raceLine += "SUBRACE: " + mainPlayer->character->getSubRaceName();
    cout << raceLine;
    cout << stringutils::constructNCharacterString(' ', formWidth - raceLine.size() - 1) << "|" << endl;
    printFormLine(formWidth, '|');
    std::string sizeLine = "| SIZE: " + mainPlayer->character->getSize();
    sizeLine += "  |  HEIGHT: ";
//    sizeLine += mainPlayer->character->getHeight();
    sizeLine += "  |  WEIGHT: ";
//    sizeLine += mainPlayer->character->getWeight();
    cout << sizeLine;
    cout << stringutils::constructNCharacterString(' ', formWidth - sizeLine.size() - 1) << "|" << endl;
    printFormLine(formWidth, '|');
    printFormLine(formWidth, '|');
    cout << "| ABILITIES |" << stringutils::constructNCharacterString(' ', formWidth - 14) << "|" << endl;
    cout << "|" << stringutils::constructNCharacterString('-', 11) << "+" << stringutils::constructNCharacterString(' ', formWidth - 14) << "|" << endl;
    std::string charismaLine = "| CHARISMA: " + mainPlayer->character->getAbilityScore(Stats::ABILITY::CHARISMA);
    cout << charismaLine;
    cout << stringutils::constructNCharacterString(' ', formWidth - charismaLine.size() - 1) << "|" << endl;
    std::string constitutionLine = "| CONSTITUTION: " + mainPlayer->character->getAbilityScore(Stats::ABILITY::CONSTITUTION);
    cout << constitutionLine;
    cout << stringutils::constructNCharacterString(' ', formWidth - constitutionLine.size() - 1) << "|" << endl;
    std::string dexterityLine = "| DEXTERITY: " +  mainPlayer->character->getAbilityScore(Stats::ABILITY::DEXTERITY);
    cout << dexterityLine;
    cout << stringutils::constructNCharacterString(' ', formWidth - dexterityLine.size() - 1) << "|" << endl;
    std::string intelligenceLine = "| INTELLIGENCE: " + mainPlayer->character->getAbilityScore(Stats::ABILITY::INTELLIGENCE);
    cout << intelligenceLine;
    cout << stringutils::constructNCharacterString(' ', formWidth - intelligenceLine.size() - 1) << "|" << endl;
    std::string strengthLine = "| STRENGTH: " + mainPlayer->character->getAbilityScore(Stats::ABILITY::STRENGTH);
    cout << strengthLine;
    cout << stringutils::constructNCharacterString(' ', formWidth - strengthLine.size() - 1) << "|" << endl;
    std::string wisdomLine = "| WISDOM: " + mainPlayer->character->getAbilityScore(Stats::ABILITY::WISDOM);
    cout << wisdomLine;
    cout << stringutils::constructNCharacterString(' ', formWidth - wisdomLine.size() - 1) << "|" << endl;
    printFormLine(formWidth, '|');
    std::string speedLine = "| SPEED: " + mainPlayer->character->getSpeed();
    cout << speedLine;
    cout << stringutils::constructNCharacterString(' ', formWidth - speedLine.size() - 1) << "|" << endl;
    printFormLine(formWidth, '|');
    std::string languagesLine = "| LANGUAGES: ";
    std::vector<std::string> languages = mainPlayer->character->getLanguages();
    for (int i = 0; i < languages.size() - 1; i++) {
        languagesLine += languages[i];
        languagesLine += ", ";
    }
    if (languages.size() > 0) {
        languagesLine += languages[languages.size() - 1];
    }
    cout << languagesLine;
    cout << stringutils::constructNCharacterString(' ', formWidth - languagesLine.size() - 1) << "|" << endl;
    printFormLine(formWidth, '|');
    std::string pointsLine = "| HIT POINTS: " + mainPlayer->character->getMaxHitPoints();
    cout << pointsLine;
    cout << stringutils::constructNCharacterString(' ', formWidth - pointsLine.size() - 1) << "|" << endl;
    printFormLine(formWidth, '+');
    cout << endl;
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
