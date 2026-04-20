# Restaurant Seat and Management System

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![Language: C++](https://img.shields.io/badge/Language-C%2B%2B-blue.svg)](https://isocpp.org/)

A console-based C++ application designed to streamline restaurant operations by providing separate interfaces for administrators/staff and customers. It manages table reservations, dynamic menus, order processing, and automated bill generation.

---

## 📑 Table of Contents
- [Overview](#overview)
- [Features](#features)
- [Technology Stack](#technology-stack)
- [Getting Started](#getting-started)
  - [Prerequisites](#prerequisites)
  - [Installation & Compilation](#installation--compilation)
  - [Running the Application](#running-the-application)
- [System Architecture](#system-architecture)
- [Code Structure](#code-structure)
- [Usage Guide](#usage-guide)
  - [Management Console](#management-console)
  - [Customer Console](#customer-console)
- [Sample Output](#sample-output)
- [Future Enhancements](#future-enhancements)
- [Authors](#authors)
- [License](#license)

---

## Overview

In the fast-paced restaurant industry, efficiency and accurate data handling are crucial. This project addresses common issues like lost reservation records, slow order processing, and disorganised table management. The application provides:

- A **secure Management Console** for staff (password-protected) to oversee bookings, update menus, and generate invoices.
- An intuitive **Customer Console** for self-service reservation, menu viewing, and ordering.
- Real-time seat availability and preference-based reservation (e.g., table vs. booth with a view).
- A colour-enhanced console interface for improved readability.

The system is built entirely in C++ and demonstrates the use of fundamental programming concepts including structures, vectors, functions, and conditional logic.

---

## ✨ Features

### Dual-User Interface

| Interface          | Access Level                        | Key Actions                                                                  |
|--------------------|-------------------------------------|------------------------------------------------------------------------------|
| Management Console | Password protected (`cp_Project`)   | Make reservations, view all bookings, add new dishes to menu, process orders |
| Customer Console   | Open to all                         | Self-reservation, view menu, place order, view bill                          |

### Core Functionalities

- **Table & Seat Management:** Differentiate between tables and booths; real-time status updates.
- **Reservation System:** Capture customer name, party size, date, time, and view preference.
- **Dynamic Menu:** Pre-loaded dishes (`Pasta`, `Steak`, `Salad`) with ability to add new items during runtime.
- **Order Processing:** Multi-item ordering with validation; aggregated bill calculation.
- **Bill Generation:** Formatted, itemised invoice with total cost.

### Technical Highlights

- Use of `struct` for `Reservation` and `Dish` data models.
- `vector` containers for dynamic storage of reservations and menu items.
- Formatted output using `<iomanip>` for clean tabular displays.
- Modular functions for each major operation.
- Console colour customisation (Windows-specific).

---

## 💻 Technology Stack

| Component              | Technology / Library                              |
|------------------------|---------------------------------------------------|
| Programming Language   | C++ (Standard 11/14/17)                           |
| Core Libraries         | `<iostream>`, `<vector>`, `<iomanip>`, `<string>` |
| Development Environment| Visual Studio (Console Application)               |

---

## 🚀 Getting Started

### Prerequisites

- A C++ compiler that supports C++11 or later (e.g., **g++**, **MinGW**, **Clang**, or **MSVC**).
- Recommended: **Visual Studio** (Windows) or **VS Code** with C++ extensions.

### Installation & Compilation

1. Clone the repository:
   ```bash
   git clone https://github.com/your-username/restaurant-seat-management.git
   cd restaurant-seat-management
   ```

2. Compile the source file (assuming a single `.cpp` file named `main.cpp`):
   ```bash
   g++ -std=c++11 main.cpp -o restaurant_system
   ```

3. For Windows using Visual Studio Command Prompt:
   ```cmd
   cl /EHsc main.cpp /Fe:restaurant_system.exe
   ```

### Running the Application

Execute the compiled binary:

```bash
./restaurant_system      # Linux/macOS
restaurant_system.exe    # Windows
```

> ⚠️ **Note on Console Colours:**  
> The code uses Windows-specific console colour functions (`SetConsoleTextAttribute`). If compiling on Linux/macOS, comment out or remove the `setConsoleColor()` call to avoid compilation errors. The core logic remains fully functional without colours.

---

## 🏗️ System Architecture

The application follows a menu-driven loop with two primary entry points:

```
        +-------------------+
        |    Main Menu      |
        +-------------------+
               |
       +-------+-------+
       |               |
+------v------+   +----v---------+
| Management  |   | Customer     |
| Console     |   | Console      |
| (Password)  |   | (No Password)|
+-------------+   +--------------+
       |                   |
+------v-------------------v------+
| Reservation | Menu | Order | Bill|
+---------------------------------+
```

### Data Models

```cpp
struct Reservation {
    string customerName;
    int numberOfPeople;
    string reservationDate;
    string reservationTime;
};

struct Dish {
    string name;
    float price;
};
```

---

## 📁 Code Structure

| Function / Component       | Purpose                                                                         |
|----------------------------|---------------------------------------------------------------------------------|
| `makeReservation()`        | Collects customer details and stores a new reservation in the vector.           |
| `viewReservations()`       | Displays all stored reservations in a formatted table.                          |
| `displayMenu()`            | Prints the current menu items with prices.                                      |
| `orderFood(vector<Dish>&)` | Allows selection of multiple menu items and stores them in an order list.       |
| `generateBill(vector<Dish>)`| Calculates and displays an itemised bill with total amount.                    |
| `addDish()`                | Adds a new dish (name and price) to the menu vector.                            |
| `runManagementConsole()`   | Staff-facing menu loop with full access (requires password).                    |
| `runCustomerConsole()`     | Customer-facing menu loop with restricted access (no menu editing).             |

---

## 📘 Usage Guide

### Management Console

1. Launch the application and select **option 1. Management Console**.
2. Enter the password: `cp_Project` (as defined in the code).
3. Choose from the following operations:
   - `1` – Make a reservation (on behalf of a customer).
   - `2` – View all existing reservations.
   - `3` – Display the menu.
   - `4` – Order food.
   - `5` – Generate bill for the current order.
   - `6` – Add a new dish to the menu.
   - `7` – Exit the management console.

### Customer Console

1. Launch the application and select **option 2. Customer Console**.
2. Direct access to:
   - Make a reservation.
   - View their own reservation *(functionality may be extended)*.
   - Display the menu.
   - Order food.
   - Generate bill.
   - Exit.

---

## 📸 Sample Output

Below is a transcript of a typical interaction in the Management Console:

```
Management Console
1. Make Reservation
2. View Reservations
3. Display Menu
4. Order Food
5. Generate Bill
6. Add New Dish
7. Exit
Enter your choice: 3

Menu:
                Dish          Price
               Pasta         $15.99
               Steak         $25.99
               Salad         $10.99

Enter your choice: 4
Menu:
                Dish          Price
               Pasta         $15.99
               Steak         $25.99
               Salad         $10.99
Enter the number of the dish you want to order (0 to finish): 1
Enter the number of the next dish (0 to finish): 2
Enter the number of the next dish (0 to finish): 0

Enter your choice: 5

Bill:
                Dish          Price
               Pasta          15.99
               Steak          25.99
Total Cost: $41.98
```

---

## 🔮 Future Enhancements

Based on the project report, planned improvements include:

- **Mobile App Integration:** A companion app for remote management.
- **Online Ordering:** Web-based interface for takeout/delivery orders.
- **Persistent Database:** Replace in-memory vectors with file-based or SQL storage.
- **Inventory Management:** Real-time stock tracking and low-stock alerts.
- **Advanced Table Optimisation:** Algorithmic seating suggestions.
- **Feedback & Review System:** Collect and analyse customer feedback.

---

## 👥 Authors

> *(Add your names and contact information here)*

---

## 📄 License

This project is licensed under the [MIT License](https://opensource.org/licenses/MIT).
