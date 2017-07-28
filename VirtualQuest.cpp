//
// Created by jwr8 on 7/22/17.
//

#include "VirtualQuest.h"
#include "characters/races/Elf.h"
#include "characters/races/DrowElf.h"
#include "characters/races/HighElf.h"
#include "characters/races/WoodElf.h"

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
        int choice = selectOption(mainMenu, mainMenuOptions);

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

int VirtualQuest::selectOption(string question, vector<string> options) {
    cout << question << endl;
    for (int i = 0; i < options.size(); i++) {
        cout << (char) ('A' + i) << ") " << options[i] << endl;
    }

    string input;
    while (true) {
        getline(cin, input);
        int choice = convertInputToNum(input, options.size());
        if (choice != 0) {
            return choice;
        } else {
            cout << "Invalid input, try again..." << endl;
        }
    }
}

int VirtualQuest::convertInputToNum(string input, int numOfOptions) {
    if (input.length() != 1) {
        return 0;
    }
    char inputChar = input[0];
    for (int i = 0; i < numOfOptions; i++) {
        if (inputChar == ('1' + i) || inputChar == ('A' + i) || inputChar == ('a' + i)) {
            return i + 1;
        }
    }
    return 0;
}

void VirtualQuest::startGame() {
    string racePrompt = "Choose your player's race";
    vector<string> races = {
            "Elf",
            "Drow Elf",
            "High Elf",
            "Wood Elf",
    };
    int raceChoice = selectOption(racePrompt, races);
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
        vector<string> yesNo = {
                "yes",
                "no"
        };
        int choice = selectOption(requestEditSettings, yesNo);
        switch (choice) {
            case 1:
                editSettings(settings);
                break;
            default:
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
    int choice = selectOption(selectDifficulty, difficulties);
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
