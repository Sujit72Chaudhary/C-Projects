#include <iostream>
#include <string>
#define size 10 // Define maximum size of the queue

using namespace std;

// Class to represent a customer
class customer {
    string name;        // Customer's name
    long long int phone_no;    // Customer's phone number

public:
    // Method to read customer details
    void read() {
        cout << "Enter Customer name: ";
        cin.ignore(); // Ignore any leftover newline in input buffer
        getline(cin, name); // Read full name with spaces
        cout << "Enter phone number: ";
        cin >> phone_no; // Read phone number
    }

    // Method to display customer details
    void display() {
        cout << "Customer Name: " << name << endl;
        cout << "Phone Number: " << phone_no << endl;
    }
};

// Class to represent the circular queue for customers
class cst_queue {
    customer Q[size]; // Array of customers to implement the queue
    int front, rear;  // Front and rear indices

public:
    // Constructor to initialize front and rear
    cst_queue() : front(-1), rear(-1) {}

    // Queue operation methods
    void addNewCst();    // Add a new customer to the queue
    void checkoutCst();  // Process checkout for the front customer
    void displayCst();   // Display all customers in the queue
    void closeCheckout(); // Close the checkout and display remaining customers
    bool isEmpty();      // Check if the queue is empty
    bool isFull();       // Check if the queue is full
};

// Method to check if the queue is empty
bool cst_queue::isEmpty() {
    return front == -1; // True if front is -1, indicating no customers
}

// Method to check if the queue is full
bool cst_queue::isFull() {
    return (rear + 1) % size == front; // True if the next position of rear is front
}

// Method to add a new customer to the queue
void cst_queue::addNewCst() {
    if (isFull()) {
        cout << "Queue is Full!!" << endl; // Queue is full, cannot add
        return;
    }
    if (isEmpty()) {
        front = 0; // Initialize front if queue was empty
    }
    rear = (rear + 1) % size; // Increment rear in circular manner
    Q[rear].read(); // Read new customer data
}

// Method to checkout the customer at the front of the queue
void cst_queue::checkoutCst() {
    if (isEmpty()) {
        cout << "Queue is empty!!" << endl; // No customers to checkout
        return;
    }
    cout << "Checking out customer:" <<endl<<"----------------------"<< endl;
    Q[front].display(); // Display details of the customer being checked out
    // Reset queue if it becomes empty after checkout
    if (front == rear) {
        front = rear = -1; // Both front and rear reset
    } else {
        front = (front + 1) % size; // Increment front in circular manner
    }
}

// Method to display all customers currently in the queue
void cst_queue::displayCst() {
    if (isEmpty()) {
        cout << "Queue is empty!!" << endl; // No customers to display
        return;
    }
    cout << "Customers in queue:"<<endl<<"----------------------"<< endl;
    int i = front; // Start from the front
    while (true) {
        Q[i].display(); // Display customer details
        if (i == rear) break; // Stop when we reach the rear
        i = (i + 1) % size; // Move to the next customer in circular manner
    }
}

// Method to close the checkout and display remaining customers
void cst_queue::closeCheckout() {
    if (isEmpty()) {
        cout << "No customers to close." << endl; // No customers in queue
        return;
    }
    cout << "Closing checkout. Remaining customers:" << endl;
    displayCst(); // Display remaining customers
    front = rear = -1; // Reset the queue
    cout << "Checkout closed!" <<endl<<"---------------"<< endl;
}

// Main function to run the customer checking system
int main() {
    cst_queue q; // Create a queue for customers
    int n; // Variable to store user choice
    cout << "Customer checking system \n";
    cout<<"*************************"<<endl;
    while (true) {
        // Display menu options
        cout << "1. Add new customer\n2. Checkout the customer\n3. View customer\n4. Close checkout counter\n5. Exit\n";
        cout << "Enter the choice: "<<endl<<"-----------------"<<endl;
        cin >> n; // Read user choice
        switch (n) {
            case 1:
                q.addNewCst(); // Add new customer
                break;
            case 2:
                q.checkoutCst(); // Checkout a customer
                break;
            case 3:
                q.displayCst(); // Display customers
                break;
            case 4:
                q.closeCheckout(); // Close the checkout
                break;
            case 5:
                cout << "Exiting the system." << endl<<"******************"<<endl; // Exit message
                return 0; // Exit the program normally
            default:
                cout << "Invalid choice!!" << endl; // Handle invalid input
        }
    }
    return 0; // Return from main
}
