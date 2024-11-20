/*
Name: Sujit Chaudhary
PRN:123B1B272
Batch: D3
                                                         s Assignment No 3
        

Probelm statement

Consider the playlist in a music player. Implement a playlist feature in music player application 
using singly linked list. Each song in the playlist is represented as a node in the linked list. Each 
node contains information about the song (such as title or artist or duration, etc.).  
The playlist should allow users to:  
a. Add songs 
b. Remove songs 
c. Display the entire playlist 
d. Play specific songs 

*/

// Program

#include <iostream>
#include <cstring>
using namespace std;

// Class to represent a song in the playlist
class song {
    string title;   // Song title
    string singer;  // Singer's name
    float time;     // Duration of the song in minutes
public:
    song *next;     // Pointer to the next song in the playlist

    // Constructor to initialize the next pointer
    song() {
        next = NULL;
    }

    // Method to read song details from the user
    void read() {
        cout << "Enter the song title: ";
        cin.ignore();  // Ignoring newline character left in the buffer from previous input
        getline(cin, title);  // Reading song title
        cout << "Enter the singer name: ";
        getline(cin, singer); // Reading singer's name
        cout << "Enter duration of song: ";
        cin >> time;  // Reading the song's duration
    }

    // Getter for the song title
    string get_title() {
        return title;
    }

    // Setter to modify the singer's name
    string setsinger(string st) {
        singer = st;
        return singer;
    }

    // Method to display song details
    void display() {
        cout << "Song Title: " << title << "\n";
        cout << "Singer Name: " << singer << "\n";
        cout << "Duration of song: " << time << " minutes\n";
    }
};

// Class to represent the playlist (a linked list of songs)
class playlist {
    song *head;  // Head pointer for the playlist (first song)
public:
    // Constructor to initialize the head pointer
    playlist() {
        head = NULL;
    }

    // Destructor to free dynamically allocated memory for songs
    ~playlist() {
        song *current = head;
        while (current != NULL) {
            song *next = current->next;
            delete current;  // Delete each song node
            current = next;
        }
    }

    // Method to add a song to the end of the playlist
    void add_song() {
        song *nn = new song;  // Create a new song node
        nn->read();  // Read song details
        if (head == NULL) {
            head = nn;  // If playlist is empty, set head to new node
        } else {
            song *cn = head;
            while (cn->next != NULL) {  // Traverse to the last node
                cn = cn->next;
            }
            cn->next = nn;  // Link the new node at the end
        }
    }

    // Method to delete a song from the playlist by title
    void delete_song(string title) {
        song *cn = head;
        song *prev = NULL;

        // Traverse the playlist to find the song
        while (cn != NULL && cn->get_title() != title) {
            prev = cn;
            cn = cn->next;
        }

        // If song not found
        if (cn == NULL) {
            cout << "Song not found!" << endl;
            return;
        }

        // If the song to delete is the first one
        if (prev == NULL) {
            head = cn->next;
        } else {
            prev->next = cn->next;  // Skip the node to be deleted
        }

        delete cn;  // Free the memory of the deleted song
        cout << "Song deleted." << endl;
    }

    // Method to display the entire playlist
    void displayplaylist() {
        if (head == NULL) {
            cout << "Playlist is empty\n";  // If playlist is empty
            return;
        }

        song *cn = head;
        while (cn != NULL) {
            cn->display();  // Display details of each song
            cn = cn->next;
        }
    }

    // Method to add a new song at the beginning of the playlist
    void add_begin() {
        song *nn = new song;  // Create a new song node
        nn->read();  // Read song details
        nn->next = head;  // Link the new node to the current head
        head = nn;  // Set the new node as the head of the list
    }

    // Method to insert a song after a given title
    void insertion_at_any(string aftertitle) {
        song *nn = new song;  // Create a new song node
        nn->read();  // Read song details
        song *cn = head;

        // Traverse the playlist to find the song with the specified title
        while (cn != NULL) {
            if (aftertitle == cn->get_title()) {
                nn->next = cn->next;  // Link the new song to the next node
                cn->next = nn;  // Insert the new node after the current node
                return;
            }
            cn = cn->next;
        }
        cout << "Song with the title '" << aftertitle << "' not found.\n";
    }

    // Method to modify the singer of a song by title
    void modify(string title, string singer) {
        song *cn = head;

        // Traverse the playlist to find the song
        while (cn != NULL) {
            if (title == cn->get_title()) {
                cn->setsinger(singer);  // Modify the singer's name
                cout << "Singer modified.\n";
                return;
            }
            cn = cn->next;
        }
        cout << "Song not found!\n";  // If song is not found
    }

    // Method to search for a song by its title
    void search(string title) {
        song *cn = head;

        // Traverse the playlist to find the song
        while (cn != NULL) {
            if (cn->get_title() == title) {
                cout << "Song is found\n";
                cn->display();  // Display the found song
                return;
            }
            cn = cn->next;
        }
        cout << "Song is not found\n";  // If song is not found
        cout<<"---------------------"<<endl;
    }
};

// Main function to manage the playlist through user inputs
int main() {
    playlist pg;  // Create a playlist object
    int choice;

    // Loop to continuously display menu and perform actions
    while (true) {
        cout << "1. Add Song\n2. Delete Song\n3. Display Playlist\n4. Add song at beginning\n5. Insert song at any\n6. Modify singer name\n7. Search Song\n8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cout<<"--------------------"<<endl;

        // Switch case to handle user choices
        switch (choice) {
            case 1: {
                int n;
                cout << "Enter the number of songs: ";
                cin >> n;  // Get number of songs to add
                for (int i = 0; i < n; i++) {
                    pg.add_song();  // Add the specified number of songs
                }
                break;
            }
            case 2: {
                string title;
                cin.ignore();
                cout << "Enter the title: ";
                getline(cin, title);  // Get the title of the song to delete
                pg.delete_song(title);  // Delete the song
                break;
            }
            case 3: {
                pg.displayplaylist();  // Display all songs in the playlist
                break;
            }
            case 4: {
                pg.add_begin();  // Add a song at the beginning of the playlist
                break;
            }
            case 5: {
                string aftertitle;
                cin.ignore();
                cout << "Enter the title where to insert: ";
                getline(cin, aftertitle);  // Get the title after which to insert the song
                pg.insertion_at_any(aftertitle);  // Insert the song after the specified title
                break;
            }
            case 6: {
                cin.ignore();
                string title, singer;
                cout << "Enter song title: ";
                getline(cin, title);  // Get the song title to modify
                cout << "Enter new singer name: ";
                getline(cin, singer);  // Get the new singer's name
                pg.modify(title, singer);  // Modify the singer name
                break;
            }
            case 7: {
                cin.ignore();
                string title;
                cout << "Enter the song title to search: ";
                getline(cin, title);  // Get the title to search for
                pg.search(title);  // Search for the song
                break;
            }
            case 8:
                exit(0);  // Exit the program
            default:
                cout << "Invalid choice! Please enter a valid option." << endl;
        }
    }
    return 0;
}

