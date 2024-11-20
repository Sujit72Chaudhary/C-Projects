
/*
Name:Sujit Chaudhary
PRN: 123B1B272
Batch: D3
                                                        Assignment No:7
Implement a browser history management system using a stack data structure to track the user's browsing history. 
The system should support the following functionalities: 
a. Add visited page 
b. Navigate back 
c. View current page 
d. Check if history is empty or not Assume no upper bound on number of pages visited
*/
#include<iostream>
#include<string>
using namespace std;

// Class to represent a webpage
class WebPage {
    string site;      // Variable to store the site name (URL or name of the webpage)
public:
    WebPage *next;    // Pointer to the next webpage in the stack (linked list structure)

    // Constructor to initialize a new webpage and set the next pointer to NULL
    WebPage() {
        next = NULL;
    }

    // Function to input the name of the webpage from the user
    void read() {
        cout << "Enter the name of the webpage: ";
        cin >> site;
    }

    // Function to display the current webpage details
    void display() {
        cout << "Current webpage: " << site << endl;
    }

    // Getter function to retrieve the name of the site
    string getSite() {
        return site;
    }
};

// Class to represent the browser history using a stack
class BrowserHistory {
    WebPage *top;  // Pointer to the top of the stack, which represents the current page
public:
    // Constructor to initialize the stack with top set to NULL, meaning the stack is empty initially
    BrowserHistory() {
        top = NULL;
    }

    // Function to add a new page to the history (push operation)
    void addNewPage() {
        WebPage *p = new WebPage();  // Create a new webpage object
        p->read();                   // Get the site details from the user
        p->next = top;               // The new page's next pointer points to the current top of the stack
        top = p;                     // Update the top to the new page
    }

    // Function to navigate back in history (pop operation)
    void navigateBack() {
        if (top != NULL) {            // Check if there is any page in history
            WebPage *temp = top;      // Temporarily store the current top page
            top = top->next;          // Move the top pointer to the previous page in the stack
            cout << "Navigated back from: " << temp->getSite() << endl;  // Display the page that was navigated back from
            delete temp;              // Delete the old top page to free up memory
        } else {
            cout << "No pages to navigate back to." << endl;  // Display message if there is no page to go back to
        }
    }

    // Function to display the current page
    void viewCurrentPage() {
        if (top != NULL) {            // Check if there is a current page
            top->display();           // Display the details of the current (top) page
        } else {
            cout << "No pages in history." << endl;  // If the history is empty, display this message
        }
    }

    // Function to check if the browsing history is empty
    bool isHistoryEmpty() {
        return top == NULL;           // If the top is NULL, the stack is empty
    }

    // Function to display the entire browsing history
    void displayHistory() {
        if (top == NULL) {            // Check if the history is empty
            cout << "No browsing history." << endl;
            return;
        }

        WebPage *temp = top;          // Use a temporary pointer to traverse the stack
        cout << "Browsing history: " << endl;
        while (temp != NULL) {        // Traverse through the stack (linked list)
            temp->display();          // Display each page in the history
            temp = temp->next;        // Move to the next page in the stack
        }
    }
};

// Main function to run the browser history system
int main() {
    BrowserHistory browser;  // Create an instance of the browser history class
    int choice;              // Variable to store the user's choice
    
    // Loop until the user chooses to exit
    do {
        // Display the menu
        cout << "\n1. Add a new page\n2. Navigate back\n3. View current page\n4. Check if history is empty\n5. Display history\n6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;       // Get the user's choice
        cout<<"---------------------"<<endl;

        // Perform the operation based on the user's choice
        switch(choice) {
            case 1:
                browser.addNewPage();      // Add a new page to the browsing history
                break;
            case 2:
                browser.navigateBack();    // Navigate back to the previous page
                break;
            case 3:
                browser.viewCurrentPage(); // View the current page
                break;
            case 4:
                // Check if history is empty
                if (browser.isHistoryEmpty())
                    cout << "History is empty." << endl;
                else
                    cout << "History is not empty." << endl;
                break;
            case 5:
                browser.displayHistory();  // Display the entire browsing history
                break;
            case 6:
                cout << "Exiting..." << endl;  // Exit the program
                break;
            default:
                cout << "Invalid choice!" << endl;  // Handle invalid input
        }
    } while(choice != 6);  // Repeat the loop until the user chooses to exit

    return 0;  // Return success
}
