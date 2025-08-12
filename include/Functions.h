#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <fstream>

void clear(){
    std::cout << "\033[H\033[J\n";
    std::cout << "\033c";
}

void WaitToReturn(){
    char answer;
    et:
    answer = 0;
    std::cout << "\nPress 1 to go back: "; cin >> answer;
    if (answer != '1') goto et;
    else return;
}

bool equal_strings(const std::string& lhs, const std::string& rhs) {
    if (lhs.size() != rhs.size()) {
        return false;
    }

    auto lit = std::begin(lhs);
    auto rit = std::begin(rhs);

    while (lit != std::end(lhs) && rit != std::end(rhs)) {
        if (std::toupper(*lit) != std::toupper(*rit)) {
            break;
        }
        ++lit;
        ++rit;
    }

    if (lit == std::end(lhs) && rit == std::end(rhs)) {
        return true;
    }

    auto spacePos = lhs.find(' ');
    if (spacePos != std::string::npos) {
        std::string firstPart = lhs.substr(0, spacePos);
        std::string secondPart = lhs.substr(spacePos + 1);
        std::string swapped = secondPart + " " + firstPart;

        if (swapped.size() == rhs.size()) {
            auto sit = std::begin(swapped);
            auto rit2 = std::begin(rhs);

            while (sit != std::end(swapped) && rit2 != std::end(rhs)) {
                if (std::toupper(*sit) != std::toupper(*rit2)) {
                    return false;
                }
                ++sit;
                ++rit2;
            }
            return sit == std::end(swapped) && rit2 == std::end(rhs);
        }
    }

    return false;
}

#endif