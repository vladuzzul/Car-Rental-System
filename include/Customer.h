#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include "Classes.h"

void initCustomers(vector<Customer>& customers) {
    ifstream custin{"customers.txt", ios::in};
    string line;
    while (getline(custin, line)) {
        Customer customer;
        size_t pos = 0;
        pos = line.find(',');
        customer.name = line.substr(0, pos);
        line.erase(0, pos + 1);
        
        customer.rented_id = stoi(line);
        
        customers.push_back(customer);
    }
    custin.close();
}

void saveCustomers(const vector<Customer>& customers) {
    ofstream custout{"customers.txt", ios::trunc};
    custout.clear();
    for (const auto& customer : customers) {
        custout << customer.name << "," 
                << customer.rented_id << endl;
    }
}

void addCustomer(vector<Customer>& customers) {
    Customer customer;
    cout << "Enter customer name: "; cin.ignore(); getline(cin, customer.name);
    cout << "Enter rented car ID (-1 if none): "; cin >> customer.rented_id;
    customers.push_back(customer);
}

void viewCustomers(const vector<Customer>& customers) {
    for (const auto& customer : customers) {
        if (customer.rented_id != -1) {
            cout << customer.name << " (Rented Car ID: " 
                 << customer.rented_id << ")" << endl;
        } else {
            cout << customer.name << " (No car rented)" << endl;
        }
    }
}

void rentCar(vector<Customer>& customers, vector<Car>& cars){
    int customerId, carId;
    cout << "Enter customer ID: "; cin >> customerId;
    cout << "Enter car ID to rent: "; cin >> carId;

    for (auto& customer : customers) {
        if (customer.rented_id == -1 && customerId == customer.rented_id) {
            for (const auto& car : cars) {
                if (car.id == carId) {
                    customer.rented_id = carId;
                    cout << "Car rented successfully!" << endl;
                    return;
                }
            }
            cout << "Car not found!" << endl;
            return;
        }
    }
}


#endif // CUSTOMER_H