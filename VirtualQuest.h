//
// Created by jwr8 on 7/22/17.
//

#ifndef VIRTUALQUEST_VIRTUALQUEST_H
#define VIRTUALQUEST_VIRTUALQUEST_H


#include <array>
#include <iostream>
#include <vector>
#include "Settings.h"

using namespace std;

class VirtualQuest {
public:
    void run();

private:
    Settings settings;

    void editSettings(Settings *);

    int selectOption(string, vector<string>);

    int convertInputToNum(string, int);

    void startGame();

    void printTutorial();

    void editSettings();

};


#endif //VIRTUALQUEST_VIRTUALQUEST_H
