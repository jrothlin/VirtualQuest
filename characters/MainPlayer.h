//
// Created by jwr8 on 7/22/17.
//

#ifndef VIRTUALQUEST_MAINPLAYER_H
#define VIRTUALQUEST_MAINPLAYER_H

#include "races/Stats.h"
#include "races/FullCharacter.h"

class MainPlayer {
public:
    FullCharacter *character;

    MainPlayer(std::string);

    std::string getName();

private:
    std::string name_;
};


#endif //VIRTUALQUEST_MAINPLAYER_H
