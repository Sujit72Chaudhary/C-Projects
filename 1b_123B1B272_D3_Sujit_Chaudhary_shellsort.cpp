/*
Name: Sujit Chaudhary
PRN:123B1B2672
Batch: D3
                                          ASSIGNMENT:1(B)

Consider a student database of SY COMP class (at least 15 records). Database contains different 
fields of every student like Roll No, Name and SGPA.
Arrange list of students alphabetically using shell sort 
*/

// Program
#include <iostream>
using namespace std;

// Defining a class 'student' which contains three data members: roll number, name, and SGPA
class student
{
    int rno;          // Roll number of the student (private data member)
    string name;      // Name of the student (private data member, using string to handle names with spaces)
    float sgpa;       // SGPA (Semester Grade Point Average) of the student (private data member)

public:
    // Function to read student details from the user
    void read()
    {
        // Prompt the user to enter the student's name
        cout << "Enter the name: ";
        cin.ignore();              // Ignoring any leftover newline character from the previous input
        getline(cin, name);        // Reading the student's name including spaces
        
        // Prompt the user to enter the student's roll number
        cout << "Enter the roll.no: ";
        cin >> rno;                // Reading the student's roll number

        // Prompt the user to enter the student's SGPA
        cout << "Enter the sgpa: ";
        cin >> sgpa;               // Reading the student's SGPA
    }

    // Function to display the student details
    void display()
    {
        // Displaying the student's name, roll number, and SGPA
        cout << "Name: " << name << endl;   // Display student's name
        cout << "Roll no: " << rno << endl;   // Display student's roll number
        cout << "SGPA: " << sgpa << endl;     // Display student's SGPA
    }

    // Friend function to perform shell sort on an array of 'student' objects
    // This function can access private members of the class
    friend void shellsort(student s[], int n);
};

// Function to sort students using Shell Sort algorithm based on their names (alphabetical order)
void shellsort(student s[], int n)
{
    // Initial gap/interval is half the size of the array
    int interval = n / 2;

    // Loop continues until the interval is reduced to 0
    while (interval >= 1)
    {
        // Loop to compare and rearrange elements based on the current gap
        for (int i = interval; i < n; i++)
        {
            // Store the current student in a temporary variable
            student temp = s[i];
            int j = i - interval;

            // Move elements greater than temp's name (alphabetically) to the right
            for (; j >= 0; j -= interval)
            {
                if (s[j].name > temp.name) // If current student's name is lexicographically greater
                {
                    s[j + interval] = s[j]; // Shift the larger element to the right
                }
                else
                {
                    break; // No more shifting is needed, exit the loop
                }
            }

            // Place the temp student at the correct position
            s[j + interval] = temp;
        }

        // Reduce the interval for the next pass (divide by 2)
        interval /= 2;
    }
}

int main() {
    student sobj[15]; // Array to store details of up to 15 students
    int n;            // Variable to store the number of students

    // Ask the user for the number of students
    cout << "Enter the number of students: ";
    cin >> n;

    // Reading details of each student
    for (int i = 0; i < n; i++)
    {
        sobj[i].read(); // Call the read function to input student details
    }

    // Sort the students alphabetically by their names using Shell Sort
    shellsort(sobj, n);

    cout << endl;
    cout << "After sorting, student details are: " << endl;
    cout << "---------------------------------------" << endl;

    // Display the sorted student details
    for (int i = 0; i < n; i++)
    {
        sobj[i].display(); // Call the display function to show student details
    }

    return 0; // End of the program
}
