//
// Created by jwr8 on 7/22/17.
//

#include <sstream>
#include "VirtualQuest.h"
#include "characters/races/Elf.h"
#include "characters/races/DrowElf.h"
#include "characters/races/HighElf.h"
#include "characters/races/WoodElf.h"
#include "stringutils.h"
#include "gameinfo.h"
#include "CharacterSheetBuilder.h"

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
    mainPlayer = new MainPlayer();
    stringutils::clearScreen();
    chooseName();
    stringutils::clearScreen();
    chooseRace();
    stringutils::clearScreen();
    mainPlayer->character->generateStats();
    printStats();
    stringutils::pressButtonToContinue();
    stringutils::clearScreen();
}

void VirtualQuest::chooseName() {
    string name = stringutils::promptForStringResponse("Choose your player's name");
    int maxLength = 30;
    while (name.size() > maxLength) {
        std::ostringstream retryPrompt;
        retryPrompt << "Please re-enter name. Must be less than " << maxLength << " characters.";
        name = stringutils::promptForStringResponse(retryPrompt.str());
    }
    mainPlayer->setName(name);
}

void VirtualQuest::chooseRace() {
    string racePrompt = "Choose your player's race";
    int raceChoice = stringutils::selectOption(racePrompt, gameinfo::races);
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
}

void VirtualQuest::printStats() {
    CharacterSheetBuilder *playerStats = new CharacterSheetBuilder(100);
    playerStats->addStringField("Name", mainPlayer->getName());
    playerStats->addIntField("LEVEL", mainPlayer->character->getLevel());
    playerStats->addIntField("EXPERIENCE", mainPlayer->character->getExperience());
    std::stringstream hp;
    hp << "?" << "/" << mainPlayer->character->getMaxHitPoints();
    playerStats->addStringField("HIT POINTS", hp.str());
    playerStats->addDashedLine();
    playerStats->addStringField("RACE", mainPlayer->character->getRaceName());
    playerStats->addStringField("SUBRACE", mainPlayer->character->getSubRaceName());
    playerStats->addDashedLine();
    playerStats->addIntField("SIZE", mainPlayer->character->getSize());
    playerStats->addIntField("HEIGHT", mainPlayer->character->getHeight());
    playerStats->addIntField("WEIGHT", mainPlayer->character->getWeight());
    playerStats->addIntField("SPEED", mainPlayer->character->getSpeed());
    playerStats->addDashedLine();
    playerStats->addDashedLine();
    playerStats->addString(" ABILITIES |");
    playerStats->nextLine();
    playerStats->addString("-----------+");
    playerStats->nextLine();
    playerStats->addIntField("CHARISMA", mainPlayer->character->getAbilityScore(Stats::ABILITY::CHARISMA));
    playerStats->addIntField("CONSTITUTION", mainPlayer->character->getAbilityScore(Stats::ABILITY::CONSTITUTION));
    playerStats->addIntField("DEXTERITY", mainPlayer->character->getAbilityScore(Stats::ABILITY::DEXTERITY));
    playerStats->addIntField("INTELLIGENCE", mainPlayer->character->getAbilityScore(Stats::ABILITY::INTELLIGENCE));
    playerStats->addIntField("STRENGTH", mainPlayer->character->getAbilityScore(Stats::ABILITY::STRENGTH));
    playerStats->addIntField("WISDOM", mainPlayer->character->getAbilityScore(Stats::ABILITY::WISDOM));
    playerStats->addDashedLine();
    playerStats->addString(" LANGUAGES : ");
    std::vector<std::string> languages = mainPlayer->character->getLanguages();
    if (languages.size() == 0) {
        playerStats->addString("NONE");
    } else {
        playerStats->addString(languages[0]);
    }
    for (int i = 1; i < languages.size(); i++) {
        playerStats->addString(", " + languages[i]);
    }
    cout << playerStats->build();
}

void VirtualQuest::printTutorial() {
    stringutils::clearScreen();
    cout << "Here is a tutorial" << endl;
    stringutils::pressButtonToContinue();
    stringutils::clearScreen();
}

void VirtualQuest::editSettings() {
    stringutils::clearScreen();
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
                cout << "Easy" << endl;
                break;
            default:
                break;
        }
        string requestEditSettings = "Would you like to edit the current settings?";
        bool choice = stringutils::askYesOrNoQuestion(requestEditSettings);
        if (choice) {
            editSettings(settings);
        } else {
            delete settings;
            stringutils::clearScreen();
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
