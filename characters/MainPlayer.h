//
// Created by jwr8 on 7/22/17.
//

#ifndef VIRTUALQUEST_MAINPLAYER_H
#define VIRTUALQUEST_MAINPLAYER_H

#include "Stats.h"
#include "FullCharacter.h"

class MainPlayer {
public:
    FullCharacter *character;

    MainPlayer();

    MainPlayer(std::string);

    std::string getName();

    void setName(std::string);

private:
    std::string name_;
};


#endif //VIRTUALQUEST_MAINPLAYER_H
