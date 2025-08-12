#include <iostream>
#include "../include/Classes.h"
#include "../include/Car.h"
#include "../include/Customer.h"
#include "../include/Functions.h"
#include "../include/Rent.h"
#include "../include/Settings.h"

using namespace std;

int main(){
    vector<Car> cars;
    vector<Customer> customers;
    initCars(cars);
    initCustomers(customers);
    initSettings();
    int choice;
    
    
    do{
        clear();
        cout << Firm_name << " Car Rental Management System\n\n";
        cout << "1. Customer Manager\n";
        cout << "2. Car Management\n";
        cout << "3. Rental Management\n";
        cout << "4. Settings\n";
        cout << "5. Exit\n";
        cout << "\nEnter your choice: "; cin >> choice;
        
        int suboption;
        switch(choice){
            case 1: {
                do{
                    clear();
                    cout << Firm_name << " Customer Management\n\n";
                    cout << "1. View Customers\n";
                    cout << "2. Add Customer\n";
                    cout << "3. Remove Customer\n";
                    cout << "4. Edit Customer\n";
                    cout << "5. Search Customer\n";
                    cout << "6. Go Back\n";
                    cout << "\nEnter your choice: "; cin >> suboption; 

                    switch(suboption){
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
                    }
                } while (suboption != 6);
                break;
            }
            case 2: {
                do{
                    //Fully Functional
                    clear();
                    cout << Firm_name << " Car Management\n\n";
                    cout << "1. View Cars\n";
                    cout << "2. Add Car\n";
                    cout << "3. Remove Car\n";
                    cout << "4. Edit Car Price\n";
                    cout << "5. Search Car\n";
                    cout << "6. Go Back\n";
                    cout << "\nEnter your choice: "; cin >> suboption;
                    
                    switch(suboption){
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
                    }

                } while (suboption != 6);
                break;
            }
            case 3: {
                do{
                    clear();
                    cout << Firm_name << " Rental Management\n\n";
                    cout << "1. Rent Car\n";
                    cout << "2. Return Car\n";
                    cout << "3. Go Back\n";
                    cout << "\n Enter your choice: "; cin >> suboption;

                    switch (suboption){
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
                    }
                } while (suboption != 3);
                break;
            }
            case 4: { // Settings not functional yet
                do{
                    clear();
                    cout << Firm_name << " Settings\n\n";
                    cout << "1. Change Firm Name\n";
                    cout << "2. Reset Settings\n";
                    cout << "3. Go Back\n";
                    cout << "\nEnter your choice: "; cin >> suboption;

                    switch (suboption){
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
                    }
                } while (suboption != 3);
                break;
            }
            case 5: {
                clear();
                cout << "\n Have a nice day!\n\n";
                return 0;
                break;
            } 
        }
    } while (choice != 5);
}