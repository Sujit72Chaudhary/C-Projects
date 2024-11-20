#include <iostream>   // Include input-output stream for standard IO operations
#include <string>     // Include string library to use the string class

using namespace std;  // Use the standard namespace for convenience

#define size 10       // Define a constant `size` representing the maximum number of customers in the waitlist

// Class representing a customer
class customer {
    string name;        // Private member variable to store the customer's name
    long long phone_no; // Private member variable to store the customer's phone number

public:
    // Method to read the customer's details
    void read() {
        cout << "Enter Customer name: ";
        cin.ignore();           // Ignore any leftover newline character in the input buffer
        getline(cin, name);     // Read the full name of the customer, including spaces
        cout << "Enter phone number: ";
        cin >> phone_no;        // Read the phone number as a long long integer
    }

    // Method to display the customer's details
    void display() {
        cout << "Customer Name: " << name << endl;     // Display the customer's name
        cout << "Phone Number: " << phone_no << endl;  // Display the customer's phone number
    }
};

// Class representing the restaurant's waitlist
class restaurant {
    customer Q[size];   // Array of customer objects to represent the waitlist
    int rear, front;    // Indices for the rear (end) and front (start) of the queue

public:
    // Constructor to initialize `rear` and `front` to -1, indicating an empty queue
    restaurant() {
        rear = front = -1;  // Set rear and front to -1 (empty queue)
    }

    // Method to add a customer to the waitlist
    void addTowaitlist() {
        if (rear == size - 1) {          // If the queue is full (rear is at max capacity)
            cout << "Restaurant is full!!" << endl;
        } else {
            rear = rear + 1;             // Increment rear to point to the next position
            Q[rear].read();              // Call the read() function to input customer details
            if (front == -1) {           // If the waitlist was previously empty
                front = 0;               // Set front to 0 (first customer added)
            }
        }
    }

    // Method to seat the customer at the front of the waitlist (FIFO)
    void seatToparty() {
        if (front == -1 || front > rear) {   // If the queue is empty
            cout << "Restaurant is empty!!" << endl;
        } else {
            Q[front].display();            // Display the details of the customer being seated
            front = front + 1;             // Move front to the next customer in the queue
            if (front > rear) {            // If the waitlist becomes empty after seating
                front = rear = -1;         // Reset front and rear to -1 (empty queue)
            }
        }
    }

    // Method to display all customers currently on the waitlist
    void displaywaitlist() {
        if (front == -1) {                 // If the waitlist is empty
            cout << "Waitlist is empty!" << endl;
            return;
        }

        for (int i = front; i <= rear; i++) {   // Loop through customers in the queue
            Q[i].display();                    // Display details of each customer
        }
    }
};

// Main function to run the restaurant waitlist program
int main() {
    restaurant r;     // Create an object of the restaurant class
    int choice;       // Variable to store the user's menu choice

    // Loop to repeatedly display the menu until the user exits
    do {
        // Display menu options
        cout<<" \nMENU LISTS "<<endl;
        cout<<"***********"<<endl;
        cout << "1. Add to waitlist\n2. Seat a party\n3. Display waitlist\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;  // Input the user's choice

        // Perform actions based on the user's choice
        switch (choice) {
            case 1:
                r.addTowaitlist();   // Call the function to add a customer to the waitlist
                break;
            case 2:
                r.seatToparty();     // Call the function to seat the first customer in line
                break;
            case 3:
                r.displaywaitlist(); // Call the function to display the current waitlist
                break;
            case 4:
                cout << "Exiting..." << endl<<"***********"<<endl;  // Display exit message
                break;
            default:
                cout << "Invalid choice! Please try again->>>>>>>>" << endl; // Handle invalid input
        }
    } while (choice != 4);  // Loop until the user chooses to exit (choice = 4)

    return 0;  // End the program
}
