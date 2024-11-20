/*

Name: Sujit Chaudhary
PRN:123B1B272
Batch: D3
                                                      Assignment No 2.B

    Problem Statement

    Consider Employee database of PCCOE (at least 20 records). Database contains different fields of 
every employee like EMP-ID, EMP-Name and EMP-Salary.  
Arrange list of Employee alphabetically using Merge Sort.

*/

// Program

#include<iostream>
using namespace std;

class Employee
{
    string name;   // Employee's name
    int emp_id;    // Employee's ID
    float salary;  // Employee's salary

public:
    // Function to read the employee's details
    void read()
    {
        cout << "Enter the employee name: ";
        cin.ignore();                // To ignore any newline character in the input buffer
        getline(cin, name);           // Reading the employee's name, including spaces
        cout << "Enter the employee ID: ";
        cin >> emp_id;                // Reading the employee's ID
        cout << "Enter the salary: ";
        cin >> salary;                // Reading the employee's salary
    }

    // Function to display the employee's details
    void display()
    {
        cout << "Name: " << name << "\n";
        cout << "ID: " << emp_id << "\n";
        cout << "Salary: " << salary << "\n";
    }

    // Declaring friend functions to allow them access to private members of the Employee class
    friend void mergesort(Employee emp[], int left, int right);
    friend void merge(Employee emp[], int low, int mid, int high);
};

// Merge Sort function to sort the employee array
void mergesort(Employee emp[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;  // Find the middle point of the array

        // Recursively sort the first and second halves
        mergesort(emp, left, mid);
        mergesort(emp, mid + 1, right);

        // Merge the sorted halves
        merge(emp, left, mid, right);
    }
}

// Merge function to merge two subarrays of Employee[] into a sorted array
// First subarray: emp[left...mid], second subarray: emp[mid+1...right]
void merge(Employee emp[], int low, int mid, int high)
{
    Employee temp[50]; // Temporary array to hold sorted elements
    int left = low;    // Starting index of the left half of emp[]
    int right = mid + 1;  // Starting index of the right half of emp[]
    int i = 0;        // Index for the temp array

    // Merge the two halves in a sorted manner
    while (left <= mid && right <= high)
    {
        if (emp[left].name <= emp[right].name)  // Compare based on employee name
        {
            temp[i] = emp[left];  // Add the left element if it's smaller
            left++;
        }
        else
        {
            temp[i] = emp[right];  // Otherwise, add the right element
            right++;
        }
        i++;
    }

    // If there are remaining elements in the left half, add them to the temp array
    while (left <= mid)
    {
        temp[i] = emp[left];
        left++;
        i++;
    }

    // If there are remaining elements in the right half, add them to the temp array
    while (right <= high)
    {
        temp[i] = emp[right];
        right++;
        i++;
    }

    // Copy the sorted elements from the temp array back into the original emp array
    for (int k = low; k <= high; k++)
    {
        emp[k] = temp[k - low];
    }
}

int main()
{
    int n;
    cout << "Enter the number of employees: ";
    cin >> n;

    Employee obj[n];  // Array to hold employee objects
    cout<<"Taking input before sorting: "<<endl;
    cout<<"----------------------------"<<endl;
    cout<<" "<<endl;
    // Read employee details
    for (int i = 0; i < n; i++)
    {
        obj[i].read();
    }

    // Perform merge sort on the employee array based on their name
    mergesort(obj, 0, n - 1);
    cout<<"After sorting the employees details: "<<endl;
    // Display sorted employee details
    for (int i = 0; i < n; i++)
    {
        obj[i].display();
    }

    return 0;
}
