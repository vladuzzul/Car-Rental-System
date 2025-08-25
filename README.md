# 🏨 Car Rental System

## 🔍 Overview

**Car Rental System** is a console-based application written in C++ for efficient hotel operations management. It provides features for managing cars, clients,  and application settings.

---

## 🧩 Features

### 👤 Customer Management
- View all customers
- Add, remove, or edit customers
- Search customers by ID

### 🚗 Car Management
- View all cars
- Add, remove, or modify cars
- Search cars by id

### 📆 Rental Management
- Rent cars
- Return cars

### ⚙️ Settings
- Change the displayed firm name in the interface
- Reset the entire database

---

## 📁 Project Structure

```plaintext
Car-Rental-System/
│
├── include/                   # Header files (declarations)
│   ├── Car.h
│   ├── Classes.h
│   ├── Customer.h
│   ├── Functions.h
│   ├── Menus.h               # Menu options displayed in console
│   ├── Rent.h
│   └── Settings.h
│
├── src/                       # Source code (implementations)
│   ├── main.cpp
│   └── *.txt                  # Other txt files
│
├── CMakeLists.txt             # Build configuration
├── LICENSE  
└── README.md
```

---

## 🛠️ Installation

### ✅ Prerequisites

Make sure you have installed:
- **C++11** or newer (GCC / Clang / MSVC)
- **CMake**
- **Git**

### 🔧 Build Instructions

#### Clone the repository
```bash
git clone https://github.com/vladuzzul/Car-Rental-System
cd Car-Rental-System
```
#### Create build directory and compile
```bash
mkdir build
cd build
cmake ..
cmake --build .
```
#### Run the application
```bash
./CarRentalSystem
```

---

## 💻 Usage

After launching the application, you'll have access to an interactive console menu:

1. **Customer management**
2. **Car management**
3. **Rental management**
4. **Settings**
5. **Leave**

---

## 🤝 Contributing

Contributions are welcome! You can:
- Open an issue for bugs or suggestions
- Submit a pull request with new features
- Refactor or optimize code

---

## ⚙️ Tech Stack

- **Language**: C++ (C++11)
- **Build**: CMake
- **Version Control**: Git

---

## ©️ License

Distributed under the [MIT](LICENSE) license.
