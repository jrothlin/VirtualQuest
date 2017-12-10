//
// Created by jwr8 on 7/22/17.
//

#ifndef VIRTUALQUEST_VIRTUALQUEST_H
#define VIRTUALQUEST_VIRTUALQUEST_H


#include <array>
#include <iostream>
#include <vector>
#include "Settings.h"
#include "characters/MainPlayer.h"

using namespace std;

class VirtualQuest {
public:
    /*
     * Entry point to VirtualQuest presenting the main menu
     */
    void run();

private:
    Settings settings;

    MainPlayer *mainPlayer;

    void editSettings(Settings *);

    /*
     * Begins the actual game play
     */
    void startGame();

    void printTutorial();

    void editSettings();

    /*
     * Print the user's character's statistics
     */
    void printStats();

    /*
     * Prompt the user to choose their character's name
     */
    void chooseName();

    /*
     * Prompt the user to choose their character's race
     */
    void chooseRace();
};


#endif //VIRTUALQUEST_VIRTUALQUEST_H
