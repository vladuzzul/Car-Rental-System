#ifndef CAR_H
#define CAR_H

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include "Classes.h"
#include "Functions.h"

using namespace std;

void initCars(vector<Car>& cars){
    ifstream carin{"cars.txt", ios::in};
    string line;
    while(getline(carin, line)){
        Car car;
        size_t pos = 0;
        pos = line.find(',');
        car.id = stoi(line.substr(0, pos));
        line.erase(0, pos + 1);
        
        pos = line.find(',');
        car.model = line.substr(0, pos);
        line.erase(0, pos + 1);
        
        pos = line.find(',');
        car.year = stoi(line.substr(0, pos));
        line.erase(0, pos + 1);
        
        pos = line.find(',');
        car.licensePlate = line.substr(0, pos);
        line.erase(0, pos + 1);
        
        car.pricePerDay = stod(line);
        
        cars.push_back(car);
    }
    carin.close();
}

void saveCars(const vector<Car>& cars){
    ofstream carout{"cars.txt", ios::trunc};
    carout.clear();
    for(const auto& car : cars){
        carout << car.id << "," 
               << car.model << "," 
               << car.year << "," 
               << car.licensePlate << "," 
               << car.pricePerDay << endl;
    }
}

void addCar(vector<Car>& cars){
    Car car;
    cout << "Enter car ID: "; cin >> car.id;
    cout << "Enter car model: "; cin.ignore(); getline(cin, car.model);
    cout << "Enter car year: "; cin >> car.year;
    cout << "Enter car license plate: "; cin.ignore(); getline(cin, car.licensePlate);
    cout << "Enter car price per day: "; cin >> car.pricePerDay;
    cars.push_back(car);
    saveCars(cars);
}

void showCars(const vector<Car>& cars){
    clear();
    for(const auto& car : cars){
        cout << "ID: " << car.id 
             << "\n\tModel: " << car.model 
             << "\n\tYear: " << car.year 
             << "\n\tLicense Plate: " << car.licensePlate 
             << "\n\tPrice per Day: " << car.pricePerDay << "\n\n";
    }
    WaitToReturn();
}

void searchCar(const vector<Car>& cars, int id){
    for(const auto& car : cars){
        if(car.id == id){
            cout << "ID: " << car.id 
                 << "\n\tModel: " << car.model 
                 << "\n\tYear: " << car.year 
                 << "\n\tLicense Plate: " << car.licensePlate 
                 << "\n\tPrice per Day: " << car.pricePerDay << "\n\n";
                 WaitToReturn();
            return;
        }
    }
    cout << "Car with ID " << id << " not found." << endl;
    WaitToReturn();
}

void deleteCar(vector<Car>& cars, int id){
    auto it = remove_if(cars.begin(), cars.end(), [id](const Car& car) { return car.id == id; });
    if(it != cars.end()){
        cars.erase(it, cars.end());
        cout << "Car with ID " << id << " deleted successfully." << endl;
    } else {
        cout << "Car with ID " << id << " not found." << endl;
    }
    saveCars(cars);
}

void modifyCar(vector<Car>& cars, int id){
    for (auto& car : cars){
        if (car.id == id){
            cout << "Enter new price per day: "; cin >> car.pricePerDay;
            saveCars(cars);
            return;
        }
    }
    cout << "Car not found!\n";
    WaitToReturn();
}


#endif