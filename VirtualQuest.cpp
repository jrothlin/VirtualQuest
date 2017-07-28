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
    mainPlayer = new MainPlayer();
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
    cout << "Created player" << endl;
    mainPlayer->character->generateStats();
    cout << "Generated stats" << endl;
    cout << mainPlayer->character->getStats()->abilityScores[Stats::ABILITY::CHARISMA] << endl;
    cout << mainPlayer->character->getStats()->abilityScores[Stats::ABILITY::CONSTITUTION] << endl;
    cout << mainPlayer->character->getStats()->abilityScores[Stats::ABILITY::DEXTERITY] << endl;
    cout << mainPlayer->character->getStats()->abilityScores[Stats::ABILITY::INTELLIGENCE] << endl;
    cout << mainPlayer->character->getStats()->abilityScores[Stats::ABILITY::STRENGTH] << endl;
    cout << mainPlayer->character->getStats()->abilityScores[Stats::ABILITY::WISDOM] << endl;
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
