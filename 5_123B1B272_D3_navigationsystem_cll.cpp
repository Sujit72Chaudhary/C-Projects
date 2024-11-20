/* 
Name:Sujit Chaudhary
PRN:123B1B272
Batch:D3
                                                    Assignment No:5

Implement a navigation system for a delivery service using a circular linked list to represent routes. 
The navigation system should support the following functionalities:
a. Add route
b. Remove route 
c. Display route.

*/

//program
#include<iostream>
using namespace std;

// Class representing each route node in the circular linked list
class Route {
    string location;  // Location for each route (node)
public:
    Route *next;  // Pointer to the next route (node)
    
    // Constructor to initialize the next pointer
    Route() {
        next = NULL;
    }

    // Function to read the location from the user
    void read_location() {
        cin.ignore();  // Ignore any leftover input from previous operations
        cout << "Enter the route location: ";
        getline(cin, location);  // Read the location from the user
    }

    // Function to return the location
    string get_location() {
        return location;
    }

    // Function to display the location
    void display_location() {
        cout << "Location: " << location <<endl;
    }
};

// Class representing the navigation system using a circular linked list
class NavigationSystem {
    Route *head, *tail;  // Pointers to the head and tail of the circular list
public:
    // Constructor to initialize the head and tail to NULL (empty list)
    NavigationSystem() {
        head = tail = NULL;
    }

    // Destructor to ensure head and tail are set to NULL when object is destroyed
    ~NavigationSystem() {
        head = tail = NULL;
    }

    // Function declarations for the navigation system operations
    void add_route();  // Add a new route to the system
    void remove_route(string location);  // Remove an existing route by location
    void display_routes();  // Display all routes in the system
};

// Function to add a new route to the circular linked list
void NavigationSystem::add_route() {
    Route *new_route = new Route();  // Create a new route node
    new_route->read_location();  // Read the location from the user

    if (head == NULL) {
        // If the list is empty, initialize head and tail to the new route
        head = tail = new_route;
        tail->next = head;  // Point the tail's next to the head to form a circular link
    } else {
        // Insert the new route at the end of the list
        tail->next = new_route;  // Link the last node to the new route
        new_route->next = head;  // Link the new route back to the head (circular)
        tail = new_route;  // Update the tail to the new route
    }
    cout << "Route added successfully!"<<endl;
}

// Function to remove a route from the circular linked list by location
void NavigationSystem::remove_route(string location) {
    if (head == NULL) {
        cout << "No routes to remove, the route list is empty"<<endl;  // Handle empty list case
        return;
    }

    Route *current = head;  // Initialize current pointer to head
    Route *previous = NULL;  // Initialize previous pointer to NULL
    bool found = false;  // Flag to check if the route is found

    // If the head is the route to be removed
    if (head->get_location() == location) {
        found = true;
        // If there is only one node in the list
        if (head == tail) {
            delete head;  // Free memory for the only route
            head = tail = NULL;  // Reset head and tail to NULL
        } else {
            // Update head and tail pointers and remove the head node
            tail->next = head->next;  // Link tail to the new head
            Route *temp = head;
            head = head->next;  // Move head to the next route
            delete temp;  // Free memory for the removed route
        }
    } else {
        // Traverse the list to find the route to remove
        do {
            previous = current;  // Set previous to the current node
            current = current->next;  // Move current to the next node
            if (current->get_location() == location) {
                found = true;  // Route is found
                previous->next = current->next;  // Unlink the current route
                if (current == tail) {
                    tail = previous;  // Update tail if the removed route was the tail
                }
                delete current;  // Free memory for the removed route
                break;
            }
        } while (current != head);  // Stop when we come back to the head
    }

    if (found) {
        cout << "Route removed successfully"<<endl;
    } else {
        cout << "Route not found"<<endl;  // Handle case where the route is not found
    }
}

// Function to display all routes in the circular linked list
void NavigationSystem::display_routes() {
    if (head == NULL) {
        cout << "No routes to display, the route list is empty"<<endl;  // Handle empty list case
        return;
    }

    Route *current = head;  // Initialize current pointer to head
    cout << "Routes in the system: "<<endl;
    // Traverse the list and display each route's location
    do {
        current->display_location();  // Display the location of the current route
        current = current->next;  // Move to the next route
    } while (current != head);  // Stop when we come back to the head
}

// Main function to demonstrate the navigation system
int main() {
    NavigationSystem navSystem;  // Create a navigation system instance
    int choice;  // Variable to store user choice

    while (true) {
        // Display menu options for the navigation system
        cout << "\nNavigation System Menu\n";
        cout << "1. Add Route\n2. Remove Route\n3. Display Routes\n0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;  // Get user choice
        
        // Handle user choice using switch case
        switch (choice) {
            case 1:
                navSystem.add_route();  // Add a new route to the system
                break;
            case 2: {
                string location;
                cin.ignore();  // Ignore any leftover input
                cout << "Enter the route location to remove: ";
                getline(cin, location);  // Get the location to remove
                navSystem.remove_route(location);  // Remove the specified route
                break;
            }
            case 3:
                navSystem.display_routes();  // Display all routes in the system
                break;
            case 0:
                exit(0);  // Exit the program
            default:
                cout << "Invalid choice! Please try again."<<endl;  // Handle invalid input
        }
    }

    return 0;
}
