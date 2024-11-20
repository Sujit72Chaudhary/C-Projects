#include <iostream> // Include the standard input-output stream library
#include <string> // Include the string library for handling string inputs
#define SIZE 10 // Define a constant SIZE with value 10, representing the hash table size

using namespace std; // Use the standard namespace

// Define the Employee class
class Employee {
private:
    int empID; // Private member to store employee ID
    string name, phone_no; // Private members to store employee name and phone number

public:
    // Member function to get data from the user
    void getData() {
        cout << "Name of the employee: "; // Prompt for employee name
        cin >> name; // Input name
        cout << "Phone number of the employee: "; // Prompt for employee phone number
        cin >> phone_no; // Input phone number
        cout << "ID of the employee: "; // Prompt for employee ID
        cin >> empID; // Input employee ID
    }

    // Member function to display employee data
    void display() {
        cout << "Name of the employee: " << name << endl; // Display name
        cout << "Phone number of the employee: " << phone_no << endl; // Display phone number
        cout << "ID of the employee: " << empID << endl; // Display ID
    }

    // Member function to return the employee ID
    int getID() {
        return empID; // Return employee ID
    }
};

// Define the HTEmp class for managing the hash table of employees
class HTEmp {
private:
    Employee HT[SIZE]; // Array to store employee objects
    bool flag[SIZE]; // Array to indicate if a slot is occupied

public:
    // Constructor to initialize the hash table
    HTEmp() {
        for (int i = 0; i < SIZE; i++) {
            flag[i] = false; // Initialize all slots as empty
        }
    }

    // Function to insert an employee into the hash table
    void insert() {
        Employee newR; // Create a new Employee object
        newR.getData(); // Get data for the new employee
        int ID = newR.getID(); // Get employee ID
        int hashvalue = ID % SIZE; // Calculate hash value using modulo operation

        if (!flag[hashvalue]) { // Check if slot is empty
            HT[hashvalue] = newR; // Insert employee into the hash table
            flag[hashvalue] = true; // Mark this slot as occupied
        } else {
            // Handle collision using linear probing
            for (int i = 1; i < SIZE; i++) {
                int pos = (hashvalue + i) % SIZE; // Calculate new position
                if (!flag[pos]) { // Check if new position is empty
                    HT[pos] = newR; // Insert employee at new position
                    flag[pos] = true; // Mark this slot as occupied
                    break; // Exit the loop once inserted
                }
            }
        }
    }

    // Function to search for an employee by ID
    void search(int empID) {
        int hashvalue = empID % SIZE; // Calculate hash value for employee ID

        for (int i = 0; i < SIZE; i++) { // Loop to check each slot with linear probing
            int pos = (hashvalue + i) % SIZE; // Calculate position with probing
            if (flag[pos] && HT[pos].getID() == empID) { // Check if slot is occupied and ID matches
                cout << "Employee found:" << endl; // Display employee found message
                HT[pos].display(); // Display employee details
                return; // Exit function once found
            }
            if (!flag[pos]) { // Stop searching if an empty slot is found
                break;
            }
        }
        cout << "Employee with ID " << empID << " not found." << endl; // Employee not found
    }
};

// Main function for the employee database management system
int main() {
    HTEmp employeeDB; // Create an instance of the hash table
    int choice, empID; // Variables to store user choice and employee ID for search

    do {
        cout << "\nEmployee Database Management System\n" << "************************************\n"; // Display menu header
        cout << "1. Insert Employee\n"; // Display insert option
        cout << "2. Search Employee by ID\n"; // Display search option
        cout << "3. Exit\n"; // Display exit option
        cout << "Enter your choice: "; // Prompt for user choice
        cin >> choice; // Input user choice

        switch (choice) { // Switch case for handling different menu options
            case 1:
                employeeDB.insert(); // Call insert function for adding an employee
                break;
            case 2:
                cout << "Enter Employee ID to search: "; // Prompt for employee ID to search
                cin >> empID; // Input employee ID
                employeeDB.search(empID); // Call search function with employee ID
                break;
            case 3:
                cout << "Exiting the system. Goodbye!" << endl; // Display exit message
                cout << "*****************************" << endl; // Exit footer
                break;
            default:
                cout << "Invalid choice. Please try again >>>>>" << endl; // Handle invalid input
                break;
        }
    } while (choice != 3); // Continue loop until the user chooses to exit

    return 0; // End of program
}
