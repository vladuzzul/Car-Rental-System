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
        bool rented = false;
        string rentedBy = "Not rented";
        
};

class Customer{
    public:
        string name = "Unknown name";
        int rented_id = -1;
};

#endif // CLASSES_H