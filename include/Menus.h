
#ifndef MENUS_H
#define MENUS_H

#include "Settings.h"
#include <iostream>
using namespace std;

int mainMenu(){
    clear();
    int choice;
    cout << Firm_name << " Car Rental Management System\n\n";
    cout << "1. Customer Management\n";
    cout << "2. Car Management\n";
    cout << "3. Rental Management\n";
    cout << "4. Settings\n";
    cout << "5. Exit\n";
    cout << "\nEnter your choice: "; cin >> choice;
    return choice;
}

int customerMenu(){
    clear();
    int suboption;
    cout << Firm_name << " Customer Management\n\n";
    cout << "1. View Customers\n";
    cout << "2. Add Customer\n";
    cout << "3. Remove Customer\n";
    cout << "4. Edit Customer\n";
    cout << "5. Search Customer\n";
    cout << "6. Go Back\n";
    cout << "\nEnter your choice: "; cin >> suboption; 
    return suboption;
}

int carMenu(){
    clear();
    int suboption;
    cout << Firm_name << " Car Management\n\n";
    cout << "1. View Cars\n";
    cout << "2. Add Car\n";
    cout << "3. Remove Car\n";
    cout << "4. Edit Car Price\n";
    cout << "5. Search Car\n";
    cout << "6. Go Back\n";
    cout << "\nEnter your choice: "; cin >> suboption;
    return suboption;
}

int rentalMenu (){
    clear();
    int suboption;
    cout << Firm_name << " Rental Management\n\n";
    cout << "1. Rent Car\n";
    cout << "2. Return Car\n";
    cout << "3. Go Back\n";
    cout << "\n Enter your choice: "; cin >> suboption;
    return suboption;
}

int settingsMenu(){
    clear();
    int suboption;
    cout << Firm_name << " Settings\n\n";
    cout << "1. Change Firm Name\n";
    cout << "2. Reset Settings\n";
    cout << "3. Go Back\n";
    cout << "\nEnter your choice: "; cin >> suboption;
    return suboption;
}

#endif // MENUS_H