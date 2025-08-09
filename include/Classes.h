#ifndef CLASSES_H
#define CLASSES_H
#include <string>
using namespace std;

// Forward declarations of classes
class Car{
    public:
        int id = -1;
        string model = "Brand, Model";
        int year = 0;
        string licensePlate = "Unknown";
        double pricePerDay = 0.0;
        
};

class Customer{
    public:
        string name = "Unknown name";
        int rented_id = -1;
};

// Include other necessary headers here
// #include "Car.h"
// #include "Customer.h"
// #include "Rental.h"
// #include "RentalSystem.h"

// Add any global constants, enums, or typedefs here

#endif // CLASSES_H