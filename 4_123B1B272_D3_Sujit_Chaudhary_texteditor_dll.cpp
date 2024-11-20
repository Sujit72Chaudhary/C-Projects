/*
Name:Sujit Chaudhary
PRN:123B1B272
Batch: D3
                                                       Assignment No 4
Problem Statement

Implement a simple text editor application using a doubly linked list to manage the text buffer. 
Text editor should support the following functionalities:  
a. Insert text 
b. Delete text 
c. Display text 
d. Search text 
e. Print text in reverse 
*/

// Program
#include<iostream>
using namespace std;

// Class representing each text entry in the editor
class Editor {
    string text; // The text content stored in each editor node
public:
    Editor *next; // Pointer to the next node in the doubly linked list
    Editor *prev; // Pointer to the previous node in the doubly linked list
    
    // Constructor to initialize next and prev pointers to NULL
    Editor() {
        prev = next = NULL;
    }

    // Function to read text input from the user
    void read() {
        cin.ignore(); // Ignore any leftover input from previous operations
        cout << "Enter the text: ";
        getline(cin, text); // Read a line of text from the user
    }

    // Destructor to ensure pointers are set to NULL when an object is destroyed
    ~Editor() { 
        prev = next = NULL;
    }

    // Function to return the stored text content
    string gettext() {
        return text;
    }

    // Function to display the text content
    void display() {
        cout << "Text In Editor: " << text << "\n";
    }
};

// Class representing the text editor, managing a collection of Editor nodes (doubly linked list)
class text_editor {
    Editor *head, *tail; // Pointers to the head and tail of the linked list
public:
    // Constructor to initialize head and tail to NULL (empty list)
    text_editor() {
        head = tail = NULL;
    }

    // Destructor to ensure head and tail are set to NULL when the object is destroyed
    ~text_editor() {
        head = tail = NULL;
    }

    // Function declarations for the text editor operations
    void add_text(); // Add text at the end
    void display_text(); // Display all text entries
    void add_text_at_begin(); // Add text at the beginning
    void add_text_at_any(string s); // Add text after a specific entry
    void display_rev(); // Display text in reverse order
    void search(string sc); // Search for a specific text entry
    void delete_text(string d); // Delete a specific text entry
};

// Function to add text to the end of the doubly linked list
void text_editor::add_text() {
    Editor *nn, *cn;
    nn = new Editor(); // Create a new Editor node
    nn->read(); // Read the text from the user
    if (head == NULL) {
        // If the list is empty, initialize head and tail to the new node
        head = tail = nn;
    } else {
        // Traverse to the end and add the new node
        for (cn = head; cn->next != NULL; cn = cn->next);
        cn->next = nn; // Link the last node to the new node
        nn->prev = cn; // Link the new node to the previous node
        tail = nn; // Update the tail pointer
    }
}

// Function to display all text entries in the linked list
void text_editor::display_text() {
    Editor *cn;
    if (head == NULL) {
        cout << "List Empty!!\n"; // Handle empty list case
        return;
    }
    for (cn = head; cn != NULL; cn = cn->next) {
        cn->display(); // Display each text entry
    }
}

// Function to add text at the beginning of the linked list
void text_editor::add_text_at_begin() {
    Editor *nn = new Editor(); // Create a new Editor node
    nn->read(); // Read the text from the user
    nn->next = head; // Link the new node to the current head
    if (head != NULL) {
        head->prev = nn; // Update the previous pointer of the old head
    }
    head = nn; // Update the head to the new node
}

// Function to add text after a specific entry in the linked list
void text_editor::add_text_at_any(string s) {
    Editor *cn = head, *nn = new Editor();
    nn->read(); // Read the text from the user

    if (head == NULL) {
        // If the list is empty, initialize head and tail to the new node
        head = tail = nn;
        return;
    }

    // Traverse the list to find the node with the matching text
    while (cn != NULL && cn->gettext() != s) {
        cn = cn->next;
    }

    if (cn != NULL) { // If the matching text is found
        nn->next = cn->next; // Link the new node to the next node
        nn->prev = cn; // Link the new node to the current node

        if (cn->next != NULL) {
            cn->next->prev = nn; // Update the previous pointer of the next node
        } else {
            tail = nn; // Update the tail if the new node is added at the end
        }
        cn->next = nn; // Link the current node to the new node
    } else {
        cout << "Text not found!\n"; // Handle case where the text is not found
    }
}

// Function to display all text entries in reverse order (from tail to head)
void text_editor::display_rev() {
    Editor *cn;
    if (head == NULL) {
        cout << "List Empty\n"; // Handle empty list case
        return;
    }
    for (cn = tail; cn != NULL; cn = cn->prev) {
        cn->display(); // Display each text entry in reverse order
    }
}

// Function to delete a specific text entry from the linked list
void text_editor::delete_text(string d) {
    if (head == NULL) {
        cout << "Text editor is empty!!\n"; // Handle empty list case
        return;
    }

    Editor *cn = head;

    // Traverse the list to find the node with the matching text
    while (cn != NULL && cn->gettext() != d) {
        cn = cn->next;
    }

    if (cn == NULL) {
        cout << "Text not found!\n"; // Handle case where the text is not found
        return;
    }

    // Unlink and delete the node
    if (cn == head) {  // If the node to be deleted is the head
        head = cn->next; // Update head to the next node
        if (head != NULL) {
            head->prev = NULL; // Update the previous pointer of the new head
        }
    } else if (cn == tail) {  // If the node to be deleted is the tail
        tail = cn->prev; // Update tail to the previous node
        if (tail != NULL) {
            tail->next = NULL; // Update the next pointer of the new tail
        }
    } else {  // For a middle node
        cn->prev->next = cn->next; // Link the previous node to the next node
        cn->next->prev = cn->prev; // Link the next node to the previous node
    }

    delete cn; // Free the memory allocated for the node
}

// Function to search for a specific text entry in the linked list
void text_editor::search(string s) {
    Editor *cn = head; // Start the search from the head
    bool found = false;
    
    while (cn != NULL) {
        if (s == cn->gettext()) {
            cout << "Text is found!!\n"; // Display if the text is found
            cn->display();
            found = true;
            break; // Exit the loop when the first match is found
        }
        cn = cn->next; // Move to the next node
    }

    if (!found) {
        cout << "Text not found.\n"; // Handle case where the text is not found
    }
}

int main() {
    text_editor T; // Create a text editor instance
    int choice;
    while (true) {
        // Display menu options
        cout << "Simple Text Editor \n";
        cout << "1. Add New Text\n2. Display Text list\n3. Add Text at Beginning\n";
        cout << "4. Display list in reverse\n5. Add at any position\n6. Delete text\n";
        cout << "7. To search text\n0. Exit\n";
        cout << "Enter the choice: ";
        cin >> choice;
        
        // Handle user choice
        switch (choice) {
            case 1:
                T.add_text(); // Add new text to the list
                break;
            case 2:
                T.display_text(); // Display all text entries
                break;
            case 3:
                T.add_text_at_begin(); // Add text at the beginning of the list
                break;
            case 4:
                T.display_rev(); // Display the list in reverse order
                break;
            case 5: {
                string s;
                cin.ignore(); // Ignore any leftover input
                cout << "Enter the text to insert after: ";
                getline(cin, s); // Get the text to insert after
                T.add_text_at_any(s); // Add text after the specified entry
                break;
            }
            case 6: {
                string d;
                cin.ignore(); // Ignore any leftover input
                cout << "Enter the text to delete: ";
                getline(cin, d); // Get the text to delete
                T.delete_text(d); // Delete the specified entry
                break;
            }
            case 7: {
                string e;
                cin.ignore(); // Ignore any leftover input
                cout << "Enter the text to search: ";
                getline(cin, e); // Get the text to search
                T.search(e); // Search for the specified text
                break;
            }
            case 0:
                exit(0); // Exit the program
            default:
                cout << "Invalid choice!!\nTry Again\n"; // Handle invalid input
        }
    }
    return 0;
}
