//
// Created by jwr8 on 8/20/17.
//

#include <tgmath.h>
#include <iostream>
#include "CharacterSheetBuilder.h"

CharacterSheetBuilder::CharacterSheetBuilder(int formWidth) : formWidth_(formWidth), sheet_(""), currentLine_("") {
    if (formWidth < 20) {
        throw std::invalid_argument("The form width must be >= 20");
    }
    addDashedLine('+');
}

void CharacterSheetBuilder::addDashedLine() {
    addDashedLine('|');
}

void CharacterSheetBuilder::addDashedLine(char endChar) {
    if (currentLine_.str().size() > 1) {
        nextLine();
    }
    currentLine_ << endChar;
    addNChars(formWidth_ - 2, '-');
    currentLine_ << endChar << std::endl;
    sheet_ << currentLine_.str();
    currentLine_.str(std::string());
}

void CharacterSheetBuilder::nextLine() {
    if (currentLine_.str().size() == 0) {
        currentLine_ << '|';
    }
    addNChars(formWidth_ - currentLine_.str().size() - 1, ' ');
    currentLine_ << '|' << std::endl;
    sheet_ << currentLine_.str();
    currentLine_.str(std::string());
}

// Adds text to the sheet as " name : value |"
// Returns true if successfully added, false if resulting text is too long
bool CharacterSheetBuilder::addIntField(std::string name, int value) {
    int charsInInt = getCharsInInt(value);
    int extraChars = 6;
    int charsNeeded = name.size() + charsInInt + extraChars;
    if (charsNeeded > formWidth_ - 1) {
        return false;
    }
    if (charsNeeded > formWidth_ - currentLine_.str().size()) {
        nextLine();
    }
    currentLine_ << "| " << name << " : " << value << " ";
    return true;
}

int CharacterSheetBuilder::getCharsInInt(int value) {
    int charsNeeded = 1;
    if (value < 0) {
        charsNeeded++;
    }
    int divider = 10;
    while (value / divider > 0) {
        charsNeeded++;
        divider *= 10;
    }
    return charsNeeded;
}

// Adds text to the sheet as " name : value |" with the number of specified decimals
// Returns true if successfully added, false if resulting text is too long or decimals is less than one
bool CharacterSheetBuilder::addFloatField(std::string name, float value, int decimals) {
    int charsInFloat = getCharsInInt((int) value) + 1 + decimals;
    int extraChars = 6;
    int charsNeeded = name.size() + charsInFloat + extraChars;
    if (charsNeeded > formWidth_ + 1 || decimals < 1) {
        return false;
    }
    if (charsNeeded > formWidth_ - currentLine_.str().size()) {
        nextLine();
    }
    currentLine_ << "| " << name << " : " << (int) value << ".";
    for (int i = 1; i <= decimals; i++) {
        currentLine_ << ((int) (value * std::pow(10, i))) % 10;
    }
    currentLine_ << " ";
    return true;
}

// Adds text to the sheet as " name : value |"
// Returns true if successfully added, false if resulting text is too long
bool CharacterSheetBuilder::addStringField(std::string name, std::string value) {
    int extraChars = 6;
    int charsNeeded = name.size() + extraChars + value.size();
    if (charsNeeded > formWidth_ + 1) {
        return false;
    }
    if (charsNeeded > formWidth_ - currentLine_.str().size()) {
        nextLine();
    }
    currentLine_ << "| " << name << " : " << value << " ";
    return true;
}

bool CharacterSheetBuilder::addString(std::string strToAdd) {
    if (strToAdd.size() > formWidth_ - 2) {
        return false;
    }
    if (strToAdd.size() > formWidth_ - currentLine_.str().size()) {
        nextLine();
    }
    if (currentLine_.str().size() == 0) {
        currentLine_ << "|";
    }
    currentLine_ << strToAdd;
    return true;
}

// Returns true if successfully added, false if resulting text is too long
bool CharacterSheetBuilder::addCustomLine(std::string customString) {

}

std::string CharacterSheetBuilder::build() {
    if (currentLine_.str().size() > 0) {
        nextLine();
    }
    addDashedLine('+');
    return sheet_.str();
}

void CharacterSheetBuilder::addNChars(int n, char character) {
    for (int i = 0; i < n; i++) {
        currentLine_ << character;
    }
}
