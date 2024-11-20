/*
Name:Sujit Chaudhary
PRN:123B1B272
Division:D
Batch:D3
                                          ASSIGNMENT NO.1(A)

Consider a student database of SY COMP class (at least 15 records). Database contains different fields of every student like Roll No, Name and SGPA. 
a.) Design a roll call list, arrange list of students according to roll numbers in ascending order using Insertion Sort.
*/
#include <iostream> 
using namespace std;

// Defining a class 'student' which contains three data members: roll number, name, and SGPA
class student
{
    int rno;           // Roll number of the student
    char name[50];     // Name of the student (maximum 50 characters)
    float sgpa;        // SGPA (Semester Grade Point Average) of the student

public:
    // Function to read student details from the user
    void read()
    {
        cout<<"Enter the roll number: ";
        cin>>rno;                    // Reading roll number
        cout<<"Enter the student name: ";
        cin.ignore();                 // Ignoring leftover newline from previous input
        cin.getline(name,50);         // Reading the name of the student (including spaces)
        cout<<"Enter the SGPA: ";
        cin>>sgpa;                    // Reading the SGPA
    }

    // Function to display the student details
    void display()
    {
        cout<<"Roll.no: "<<rno<<endl; // Display roll number
        cout<<"Student name: "<<name<<endl; // Display name
        cout<<"SGPA: "<<sgpa<<endl;  // Display SGPA
    }

    // Friend function to perform insertion sort on an array of 'student' objects
    // This function has access to private members of the class
    friend void insertionsort(int n, student s[]);
};

// Function to sort the students based on their roll numbers using insertion sort
void insertionsort(int n, student s[])
{
    for(int i = 1; i < n; i++)
    {
        student x = s[i];  // The current student to be placed in sorted order
        int j = i - 1;
        // Moving elements that are greater than the current student's roll number to one position ahead
        while(j >= 0 && x.rno <= s[j].rno)
        {
            s[j + 1] = s[j]; // Shift elements to the right
            j--;
        }
        s[j + 1] = x; // Place the current student at its correct position
    }
}

int main() {
    student sobj[20]; // Array to hold details of up to 10 students
    int n;

    // Asking the user for the number of students
    cout<<"Enter the number of the student: ";
    cin>>n;

    // Reading details for each student
    for(int i = 0; i < n; i++)
    {
        sobj[i].read(); // Read details of each student
    }

    // Sorting the students based on their roll numbers
    insertionsort(n, sobj);

    // Displaying the sorted student details
    cout<<"After sorting, student details are: "<<endl;
    cout<<"------------------------------------\n";
    for(int i = 0; i < n; i++)
    {
        sobj[i].display(); // Display details of each student
    }

    return 0; 
}
