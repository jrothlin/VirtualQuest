//
// Created by jwr8 on 7/22/17.
//

#ifndef VIRTUALQUEST_SETTINGS_H
#define VIRTUALQUEST_SETTINGS_H

class Settings {
public:
    enum DIFFICULTY : int {
        EASY = 0,
        NORMAL = 1,
        HARD = 2
    };

    Settings();

    DIFFICULTY getDifficulty();

    void setDifficulty(DIFFICULTY);

private:
    DIFFICULTY difficulty;
};


#endif //VIRTUALQUEST_SETTINGS_H
