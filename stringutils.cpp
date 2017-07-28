//
// Created by jwr8 on 7/27/17.
//

#include <iostream>
#include <algorithm>
#include "stringutils.h"

namespace stringutils {
    int selectOption(std::string question, std::vector<std::string> options) {
        std::cout << question << std::endl;
        for (int i = 0; i < options.size(); i++) {
            std::cout << (char) ('A' + i) << ") " << options[i] << std::endl;
        }

        std::string input;
        while (true) {
            getline(std::cin, input);
            int choice = stringutils::convertInputToNum(input, options.size());
            if (choice != 0) {
                return choice;
            } else {
                std::cout << "Invalid input, try again..." << std::endl;
            }
        }
    }

    int convertInputToNum(std::string input, int numOfOptions) {
        if (input.length() != 1) {
            return 0;
        }
        char inputChar = input[0];
        for (int i = 0; i < numOfOptions; i++) {
            if (inputChar == ('1' + i) || inputChar == ('A' + i) || inputChar == ('a' + i)) {
                return i + 1;
            }
        }
        return 0;
    }

    bool askYesOrNoQuestion(std::string question) {
        std::cout << question << std::endl;
        std::string input;
        while (true) {
            getline(std::cin, input);
            int choice = stringutils::verifyYesOrNoInput(input);
            if (choice == 0) {
                return false;
            } else if (choice == 1) {
                return  true;
            } else {
                std::cout << "Invalid input, try again..." << std::endl;
            }
        }
    }

    int verifyYesOrNoInput(std::string input) {
        std::transform(input.begin(), input.end(), input.begin(), ::tolower);
        if (input == "y" || input == "yes") {
            return 1;
        } else if (input == "n" || input == "no") {
            return 0;
        } else {
            return -1;
        }
    }
}
