#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <fstream>

void clear(){
    std::cout << "\033[H\033[J\n";
    std::cout << "\033c";
}

void WaitToReturn(){
    int answer;
    et:
    answer = 0;
    std::cout << "\nPress 1 to go back: "; cin >> answer;
    if (answer != 1) goto et;
    else return;
}

#endif