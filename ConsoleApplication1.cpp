#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <Windows.h>

using namespace std;

// Structure for group member
struct GroupMember {
    string name;
    string role;
};

// Function to display intro
void displayIntro() {
    cout << setw(50) << right << "Restaurant Seat And Management System" << setw(20) << right << "\n";
    cout << endl;

    GroupMember members[] = {
        {"Muhammad Mujtaba", "Project Manager"},
        {"Muhammad Muneeb Ansari", "Jr. Programmer"},
        {"Tehreem Noor", "Jr. Programmer"}
    };

    for (const auto& member : members) {
        cout << setw(30) << right << member.name << setw(25) << right << member.role << endl;
    }
}


// Function to set console text color
void setConsoleColor() {
    HANDLE console_color;
    console_color = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(console_color, 12);
}

// Structure for Reservations
struct Reservation {
    string customerName;
    int numberOfPeople;
    string reservationDate;
    string reservationTime;
};

//Structure for dish
struct Dish {
    string name;
    float price;
};

// List of reservations and dishes
vector<Reservation> reservations;
vector<Dish> menu = {{"Pasta", 15.99}, {"Steak", 25.99}, {"Salad", 10.99}};


// Function to add dish
void addDish() {
    Dish newDish;
    int numOfDish;
    cout << "Enter number of dishes: ";
    cin >> numOfDish;
    for (int i = 1; i <= numOfDish; i++) {
        cout << "Enter the name of the new dish: ";
        cin >> newDish.name;

        cout << "Enter the price of the new dish: ";
        cin >> newDish.price;

        menu.push_back(newDish);

        cout << "Dish added successfully.\n";
    }
}

// Funtion to make reservations
void makeReservation() {
    Reservation reservation;
    cout << "Enter customer name: ";
    cin.ignore();
    getline(cin, reservation.customerName);

    cout << "Enter number of people: ";
    cin >> reservation.numberOfPeople;

    cout << "Enter reservation date (MM/DD/YYYY): ";
    cin >> reservation.reservationDate;

    cout << "Enter reservation time: ";
    cin >> reservation.reservationTime;

    reservations.push_back(reservation);
    cout << "Reservation successful!" << endl;
}

// Function to display reservations
void viewReservations() {
    if (reservations.empty()) {
        cout << "No reservations available." << endl;
    } else {
        cout << "Reservations:" << endl;
        cout << setw(20) << "Customer Name" << setw(15) << "People" << setw(15)
            << "Date" << setw(15) << "Time" << endl;
        for (const auto &reservation : reservations) {
            cout << setw(20) << reservation.customerName << setw(15)
                << reservation.numberOfPeople << setw(15)
                << reservation.reservationDate << setw(15)
                << reservation.reservationTime << endl;
        }
    }
}

// Function to Display menu
void displayMenu() {
    cout << "Menu:\n";
    cout << setw(20) << "Dish" << setw(15) << "Price" << endl;
    for (const auto &dish : menu) {
        cout << setw(20) << dish.name << setw(15) << "$" << dish.price << endl;
    }
}

// Funtion to store order data
void orderFood(vector<Dish> &orderedDishes) {
    displayMenu();

    cout << "Enter the number of the dish you want to order (0 to finish): ";
    int choice;
    while (cin >> choice && choice != 0) {
        if (choice >= 1 && choice <= static_cast<int>(menu.size())) {
            orderedDishes.push_back(menu[choice - 1]);
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
        cout << "Enter the number of the next dish (0 to finish): ";
    }
}

// Function to generate bill
void generateBill(const vector<Dish> &orderedDishes) {
    if (orderedDishes.empty()) {
        cout << "No items ordered. Bill is $0.00." << endl;
        return;
    }

    double totalCost = 0.0;
    cout << "\nBill:\n";
    cout << setw(20) << "Dish" << setw(15) << "Price" << endl;
    for (const auto &dish : orderedDishes) {
        cout << setw(20) << dish.name << setw(15) << dish.price << endl;
        totalCost += dish.price;
    }

    cout << "\nTotal Cost: $" << totalCost << endl;
}


// Function to authenticate a password
bool authenticatePassword(const string& enteredPassword, const string& storedPassword) {
    return enteredPassword == storedPassword;
}


// Funtion for management console 
void runManagementConsole() {
    int choice;
    vector<Dish> orderedDishes;

    do {
        cout << "\nManagement Console\n";
        cout << "1. Make Reservation\n";
        cout << "2. View Reservations\n";
        cout << "3. Display Menu\n";
        cout << "4. Order Food\n";
        cout << "5. Generate Bill\n";
        cout << "6. Add New Dish\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                makeReservation();
                break;
            case 2:
                viewReservations();
                break;
            case 3:
                displayMenu();
                break;
            case 4:
                orderFood(orderedDishes);
                break;
            case 5:
                generateBill(orderedDishes);
                break;
            case 6:
                addDish();
                break;
            case 7:
                cout << "Exiting the program.\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 7);
}

// Function for customer console
void runCustomerConsole(){
    int mainChoice;
    vector<Dish> orderedDishes;
    do {
        cout << "\nCustomer Console\n";
        cout << "1. Make Reservation\n";
        cout << "2. View Reservations\n";
        cout << "3. Display Menu\n";
        cout << "4. Order Food\n";
        cout << "5. Generate Bill\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> mainChoice;

        switch (mainChoice) {
        case 1:
            makeReservation();
            break;
        case 2:
            viewReservations();
            break;
        case 3:
            displayMenu();
            break;
        case 4:
            orderFood(orderedDishes);
            break;
        case 5:
            generateBill(orderedDishes);
            break;
        case 6:
            cout << "Exiting the program.\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (mainChoice != 6);
}

int main() {
    
    setConsoleColor();
    displayIntro();
    
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;

    string password = "cp_Project";
    string entPassword;
    int cnslSlct;
    cout << "1.  Management Console \n";
    cout << "2.  Customer Console \n";
    cout << "Enter 0 to exit \n";
    cout << "Please select one option: ";
    cin >> cnslSlct;
    
    cout << endl;
    cout << endl;

    if (cnslSlct == 1) {
        cout << "Enter Password: ";
        cin >> entPassword;
        if (authenticatePassword(entPassword, password)) {
            runManagementConsole();
    
            cout << endl;
            cout << endl;
        }
        else {
            cout << "Incorrect Password" << endl;
        }
    }
    else if (cnslSlct == 2) {
        runCustomerConsole();
        
        cout << endl;
        cout << endl;
    }
    else if ( cnslSlct == 0) {
        return 0;
    }

    return 0;
}
