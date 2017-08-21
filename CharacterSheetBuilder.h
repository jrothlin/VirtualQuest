//
// Created by jwr8 on 8/20/17.
//

#ifndef VIRTUALQUEST_FORMBUILDER_H
#define VIRTUALQUEST_FORMBUILDER_H


#include <string>
#include <sstream>

class CharacterSheetBuilder {
public:
    CharacterSheetBuilder(int);

    void addDashedLine(char);

    void nextLine();

    bool addInt(std::string, int);

    bool addFloat(std::string, float);

    bool addString(std::string, std::string);

    bool addCustomLine(std::string);

    std::string build();

private:
    int formWidth_;

    std::stringstream sheet_;

    std::stringstream currentLine_;

    void addNChars(int, char);
};


#endif //VIRTUALQUEST_FORMBUILDER_H
