#include <iostream>
#include "../include/Classes.h"
#include "../include/Car.h"
#include "../include/Customer.h"
#include "../include/Functions.h"
#include "../include/Rent.h"
#include "../include/Settings.h"
#include "../include/Menus.h"

using namespace std;

int main(){
    vector<Car> cars;
    vector<Customer> customers;
    initCars(cars);
    initCustomers(customers);
    initSettings();
    int choice = 0;
    
    
    while (choice != 5){
        back:
        switch(mainMenu()){
            case 1: {
                int suboption;
                while (suboption != 6){
                    switch(customerMenu()){
                        case 1: { //View Customers
                            clear();
                            viewCustomers(customers);
                            break;
                        } 
                        case 2: { // Add Customer
                            clear();
                            addCustomer(customers);
                            break;
                        }
                        case 3: { // Remove Customer
                            clear();
                            string name;
                            cout << "Enter the customer's name you want to delete: "; 
                            cin.ignore();
                            getline(cin, name);
                            deleteCustomer(customers, name);
                            break;
                        }
                        case 4: { // Edit Customer
                            clear();
                            string name;
                            cout << "Enter the customer's name you want to modify: ";
                            cin.ignore();
                            getline(cin, name);
                            modifyCustomer(customers, name);
                            break;
                        }
                        case 5: { // Search Customer
                            clear();
                            string name;
                            cout << "Enter customer name: "; 
                            cin.ignore();
                            getline(cin, name);
                            searchCustomer(customers, name);
                            break;
                        }
                        case 6:{ // Go Back
                            goto back;
                            break;
                        }
                    }
                }
                break;
            }
            case 2: {
                int suboption;
                while (suboption != 6){
                    //Fully Functional
                    
                    switch(carMenu()){
                        case 1: {
                            clear();
                            showCars(cars);
                            break;
                        }
                        case 2: {
                            clear();
                            addCar(cars);
                            break;
                        }
                        case 3: {
                            clear();
                            int id;
                            cout << "Enter car id you want to remove: "; cin >> id;
                            deleteCar(cars, id);
                            break;
                        }
                        case 4: {
                            clear();
                            int id;
                            cout << "Enter car id you want to edit: "; cin >> id;
                            modifyCar(cars, id);
                            break;
                        }
                        case 5: {
                            clear();
                            int id;
                            cout << "Enter car id you want to search: "; cin >> id;
                            searchCar(cars, id);
                            break;
                        }
                        case 6: {
                            goto back;
                            break;
                        }
                    }

                } 
                break;
            }
            case 3: {
                int suboption;
                while (suboption != 3){

                    switch (rentalMenu()){
                        case 1: { // Rent Car
                            clear();
                            string name;
                            int id;
                            em:
                            cout << "Enter car ID to rent: "; cin >> id;
                            if (id < 0) {
                                cout << "\nInvalid car ID, try again.\n\n";
                                goto em;
                            }
                            cout << "Enter the customer name who is renting the car: ";
                            cin.ignore();
                            getline(cin, name);
                            rentCar(customers, cars, name, id);
                            break;
                        }
                        case 2: { // Return Car
                            clear();
                            string name;
                            cout << "Enter the customer name who is returning the car: ";
                            cin.ignore();
                            getline(cin, name);
                            returnCar(customers, cars, name);
                            break;
                        }
                        case 3: { // Go Back
                            goto back;
                            break;
                        }
                    }
                } 
                break;
            }
            case 4: { 
                int suboption;
                while (suboption != 3){
                    
                    switch (settingsMenu()){
                        case 1: { // Change name
                            clear();
                            changeFirmName();
                            break;
                        }
                        case 2: { // Reset Settings
                            clear();
                            cout << "Are you sure you want to reset settings? (y/n): ";
                            char confirm;
                            cin >> confirm;
                            if (confirm == 'y' || confirm == 'Y') {
                                remove("settings.txt");
                                Firm_name = "Your firm's";
                                saveSettings();
                                cout << "\nSettings reset successfully!" << endl;
                            } else {
                                cout << "\nSettings reset cancelled." << endl;
                            }
                            WaitToReturn();
                            break;
                        }
                        case 3: { // Go Back
                            goto back;
                            break;
                        }
                    }
                } 
                break;
            }
            case 5: {
                clear();
                cout << "\n Have a nice day!\n\n";
                return 0;
                break;
            } 
        }
    } 
}