#ifndef RENT_H
#define RENT_H
#include <iostream>
#include "Classes.h"
#include "Functions.h"
#include "Car.h"
#include "Customer.h"
using namespace std;

void rentCar(vector<Customer>& customers, vector<Car>& cars, string customer_name, int car_id){
    for (auto& customer : customers){
        if (equal_strings(customer.name, customer_name)){
            for (auto& car : cars){
                if (car_id == car.id){
                    car.rented = true;
                    car.rentedBy = customer.name;
                    customer.rented_id = car.id;
                    cout << "\nCar ID " << car.id << " is rented to " << customer.name << ".\n";
                    saveCars(cars);
                    saveCustomers(customers);
                    WaitToReturn();
                    return;
                }
            }
            cout << "\nCar with ID " << car_id << " not found.\n";
            WaitToReturn();
            return;
        }
    }
    cout << "\nCustomer " << customer_name << " not found.\n";
    WaitToReturn();
}

void returnCar(vector<Customer>& customers, vector<Car>& cars, string customer_name){
    for (auto& customer : customers){
        if (equal_strings(customer.name, customer_name)){
            if (customer.rented_id != -1){
                for (auto& car : cars){
                    if (car.id == customer.rented_id){
                        car.rented = false;
                        car.rentedBy = "Not rented";
                        customer.rented_id = -1;
                        cout << "\nCar ID " << car.id << " is returned by " << customer.name << ".\n";
                        saveCars(cars);
                        saveCustomers(customers);
                        WaitToReturn();
                        return;
                    }
                }
            } else {
                cout << "\nCustomer " << customer.name << " has no rented car.\n";
                WaitToReturn();
                return;
            }
        }
    }
    cout << "\nCustomer " << customer_name << " not found.\n";
    WaitToReturn();
}


#endif // RENT_H