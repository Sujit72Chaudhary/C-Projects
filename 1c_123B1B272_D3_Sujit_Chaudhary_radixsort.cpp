/*

 Name: Sujit Chaudhary
 PRN: 123B1B272
 Batch: D3
                                                        ASSIGNMENT NO 1(C)

Problem Statement

Consider a student database of SY COMP class (at least 15 records). Database contains different 
fields of every student like Roll No, Name and SGPA.

 Arrange list of students to find out first ten toppers from a class using Radix sort
*/

// Program

#include <iostream>
using namespace std;

class student // Defining a class 'student' with private members: name, roll number, and marks
{
    string name;  // Name of the student
    int rno;      // Roll number of the student
    int marks;    // Marks of the student (or SGPA)

public:
    // Member function to read student details from the user
    void read()
    {
        cout << "Enter the name: ";
        cin.ignore();                   // Ignoring leftover newline character
        getline(cin, name);             // Reading the full name of the student (including spaces)
        cout << "Enter the roll_no: ";
        cin >> rno;                     // Reading the student's roll number
        cout << "Enter the marks: ";
        cin >> marks;                   // Reading the student's marks (SGPA)
    }

    // Member function to display the student's details
    void display()
    {
        cout << "Name: " << name << endl;   // Display the name
        cout << "Roll_No: " << rno << endl; // Display the roll number
        cout << "Marks: " << marks << endl; // Display the marks (SGPA)
    }

    // Friend function to find the maximum mark in the list of students
    friend int getMax(student s[], int n);

    // Friend function for counting sort based on a specific digit (for radix sort)
    friend void countsort(student s[], int n, int EXP);
};

// Function to find the maximum mark in the list of students
int getMax(student s[], int n)
{
    int max = s[0].marks;  // Start by assuming the first student's mark is the maximum
    for (int i = 1; i < n; i++)
    {
        if (s[i].marks > max)  // If current student's mark is greater than 'max', update 'max'
        {
            max = s[i].marks;
        }
    }
    return max;  // Return the highest mark found
}

// Function to perform counting sort on the marks of students based on a specific digit (EXP)
void countsort(student s[], int n, int EXP)
{
    student* output = new student[n];   // Creating a temporary array to store sorted students
    int count[10] = {0};                // Count array to store the count of occurrences of digits (0-9)

    // Count occurrences of each digit (based on the EXP position)
    for (int i = 0; i < n; i++)
    {
        int digit = (s[i].marks / EXP) % 10;
        count[digit]++;
    }

    // Update the count array to get the correct positions of elements
    for (int i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }

    // Build the sorted array using the count array
    for (int i = n - 1; i >= 0; i--)
    {
        int digit = (s[i].marks / EXP) % 10;
        output[count[digit] - 1] = s[i];   // Place student at the correct position
        count[digit]--;                    // Decrement the count
    }

    // Copy the sorted students from output[] back to the original array
    for (int i = 0; i < n; i++)
    {
        s[i] = output[i];
    }

    delete[] output;  // Free the dynamically allocated memory for the output array
}

int main()
{
    int n;
    cout << "Enter the number of the student: ";
    cin >> n;  // Read the number of students
    cout << "Before sorting the input details are: " << endl;
    cout << "--------------------------------------" << endl;

    student* s = new student[n];  // Dynamically allocate memory for 'n' students

    // Loop to read details of each student
    for (int i = 0; i < n; i++)
    {
        s[i].read();  // Read student details
    }

    // Find the maximum mark to determine the number of digits
    int max = getMax(s, n);
    cout << "Max mark: " << max << endl;

    // Perform radix sort using counting sort for each digit position (units, tens, hundreds, etc.)
    for (int i = 1; max / i > 0; i *= 10)
    {
        countsort(s, n, i);  // Perform counting sort on each digit
    }

    // Display the sorted student details
    cout << "After sorting student details are: " << endl;
    cout << "--------------------------------------" << endl;
    for (int i = 0; i < n; i++)
    {
        s[i].display();  // Display student details after sorting
        cout << "\n";
    }

    delete[] s;  // Free the dynamically allocated memory for the student array

    return 0;  // End of program
}
