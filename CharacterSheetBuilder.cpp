//
// Created by jwr8 on 8/20/17.
//

#include "CharacterSheetBuilder.h"

CharacterSheetBuilder::CharacterSheetBuilder(int formWidth) : formWidth_(formWidth),
                                                              sheet_(""), currentLine_("") {
    if (formWidth < 20) {
        throw std::invalid_argument("The form width must be >= 20");
    }
}

void CharacterSheetBuilder::addDashedLine(char endCharacters) {
    currentLine_ << endCharacters;
    addNChars(formWidth_ - 2, '-');
    currentLine_ << endCharacters << std::endl;
    sheet_ << currentLine_.str();
    currentLine_.clear();
}

void CharacterSheetBuilder::nextLine() {
    if (currentLine_.str().size() == 0) {
        currentLine_ << '|';
    }
    addNChars(formWidth_ - currentLine_.str().size() - 1, ' ');
    currentLine_ << '|' << std::endl;
    sheet_ << currentLine_.str();
    currentLine_.clear();
}

bool CharacterSheetBuilder::addInt(std::string name, int value) {

}

bool CharacterSheetBuilder::addFloat(std::string name, float value) {

}

bool CharacterSheetBuilder::addString(std::string name, std::string value) {

}

bool CharacterSheetBuilder::addCustomLine(std::string customString) {

}

std::string CharacterSheetBuilder::build() {

}

void CharacterSheetBuilder::addNChars(int n, char character) {
    for (int i = 0; i < n; i++) {
        currentLine_ << character;
    }
}
