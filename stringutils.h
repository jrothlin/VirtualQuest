//
// Created by jwr8 on 7/27/17.
//

#ifndef VIRTUALQUEST_STRINGUTILS_H
#define VIRTUALQUEST_STRINGUTILS_H


#include <string>
#include <vector>

namespace stringutils {
    int selectOption(std::string, std::vector<std::string>);
    int convertInputToNum(std::string, int);
    bool askYesOrNoQuestion(std::string);
    int verifyYesOrNoInput(std::string);
    std::string promptForStringResponse(std::string);
    std::string constructNCharacterString(char, int);
    void clearScreen();
    void pressButtonToContinue();
};


#endif //VIRTUALQUEST_STRINGUTILS_H
