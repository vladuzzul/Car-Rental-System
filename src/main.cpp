#include <iostream>
#include "../include/Classes.h"
#include "../include/Car.h"
#include "../include/Customer.h"
#include "../include/Functions.h"

using namespace std;

int main(){
    vector<Car> cars;
    vector<Customer> customers;
    initCars(cars);
    initCustomers(customers);
    int choice;

    string Firm_name = "Your";

    
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
                    cout << "5. Search Cusotmer\n";
                    cout << "6. Go Back\n";
                    cout << "\nEnter your choice: "; cin >> suboption; 
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
                } while (suboption != 3);
                break;
            }
            case 4: {
                do{
                    clear();
                    cout << Firm_name << " Settings\n\n";
                    cout << "1. Change Firm Name\n";
                    cout << "2. Reset Database\n";
                    cout << "3. Go back\n";
                    cout << "\nEnter your choice: "; cin >> suboption;
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