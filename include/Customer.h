#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include "Classes.h"
#include "Functions.h"

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
    customers.push_back(customer);
    saveCustomers(customers);
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
    WaitToReturn();
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

void searchCustomer(vector <Customer> customers, string name){
    for (auto customer : customers){
        if(equal_strings(customer.name, name)){
            cout << "\nName: " << customer.name << "\n";
            if (customer.rented_id != -1) {
                cout << "Rented Car ID: " << customer.rented_id << "\n";
            } else {
                cout << "No car rented.\n";
            }
            WaitToReturn();
            return;
        }
    }
    cout << "Customer not found! \n";
}

void deleteCustomer(vector <Customer>& customers, string name){
    for (auto it = customers.begin(); it <= customers.end(); ++it){
        if(equal_strings(it->name, name)){
            customers.erase(it);
            saveCustomers(customers);
            cout << "\nCustomer deleted succesfully!\n";
            WaitToReturn();
            return;
        }
    }
    cout << "\nCustomer not found!\n";
    WaitToReturn();
    return;
}

void modifyCustomer(vector <Customer>& customers, string name){
    for (auto it = customers.begin(); it <= customers.end(); ++it){
        if(equal_strings(it->name, name)){
            string new_name;
            cout << "Enter the new name: "; 
            getline(cin, new_name);
            it -> name = new_name;
            saveCustomers(customers);
            cout << "\nCustomer modified succesfully!\n";
            WaitToReturn();
            return;
        }
    }
    cout << "\nCustomer not found!\n";
    WaitToReturn();
    return;
}

#endif // CUSTOMER_H