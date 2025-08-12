#ifndef SETTINGS_H
#define SETTINGS_H
#include <fstream>
#include <iostream>
using namespace std;

string Firm_name;

void initSettings(){
    ifstream sin("settings.txt", ios::in);
    string line;
    std::getline(sin, Firm_name);
    if (Firm_name.rfind("Firm Name: ", 0) == 0) {
        Firm_name = Firm_name.substr(11); // Remove "Firm Name: " prefix
    } else {
        Firm_name = "Your firm's";
    }
    sin.close();
}



void saveSettings(){
    ofstream sin("settings.txt", ios::trunc);
    sin << "Firm Name: " << Firm_name << '\n';
}

void changeFirmName(){
    cout << "Enter new firm name: ";
    cin.ignore();
    getline(cin, Firm_name);
    saveSettings();
    cout << "Firm name changed successfully!" << endl;
}
#endif // SETTINGS_H