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
    void run();

private:
    Settings settings;

    MainPlayer *mainPlayer;

    void editSettings(Settings *);

    void startGame();

    void printTutorial();

    void editSettings();

    void printStats();

    void printFormLine(int, char);
};


#endif //VIRTUALQUEST_VIRTUALQUEST_H
