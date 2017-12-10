//
// Created by jwr8 on 7/22/17.
//

#include "MainPlayer.h"

MainPlayer::MainPlayer() : name_("") {}

MainPlayer::MainPlayer(std::string name) : name_(name) {}

std::string MainPlayer::getName() {
    return name_;
}

void MainPlayer::setName(std::string name) {
    name_ = name;
}