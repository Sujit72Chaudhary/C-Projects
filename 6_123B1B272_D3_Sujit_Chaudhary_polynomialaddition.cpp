
/*

Name: Sujit Chaudhary
PRN: 123B1B272
Batch: D3
                                                      Assignment No.6
Problem Statement

Consider two polynomial expressions of any degree. Design solution to perform addition of these 
two polynomials with suitable data structure and display results. 

*/

#include<iostream>
using namespace std;

// Forward declaration of the class polynomial_exp
class polynomial_exp;

class polynomial {
    // Private members to store coefficient and power of a term
    int coeff;
    int pow;
public:
    // Pointer to the next node (term in the polynomial)
    polynomial* next;

    // Constructor to initialize next pointer to NULL
    polynomial() {
        next = NULL;
    }

    // Function to read the coefficient and power of a polynomial term
    void read() {
        cout << "Enter the coefficient: ";
        cin >> coeff;
        cout << "Enter the power: ";
        cin >> pow;
    }

    // Function to display a single polynomial term
    void display() {
        cout << coeff << "x^" << pow;
        // If there is a next term, display a "+" sign
        if (next != NULL) {
            cout << " + ";
        }
    }

    // Friend function declaration to allow access to private members of the class
    friend void addpolynomial(polynomial_exp& p1, polynomial_exp& p2);
};

// Class to handle the entire polynomial expression
class polynomial_exp {
    // Pointer to the head of the linked list of polynomial terms
    polynomial* head;
public:
    // Constructor to initialize the head pointer to NULL
    polynomial_exp() {
        head = NULL;
    }

    // Function to insert a new term into the polynomial expression
    void insertnode() {
        // Create a new polynomial term (node)
        polynomial* nn = new polynomial;
        nn->read();  // Read the term data (coefficient and power)
        
        // If the list is empty, set the new node as the head
        if (head == NULL) {
            head = nn;
        } else {
            // Traverse to the end of the list and insert the new node
            polynomial* cn = head;
            while (cn->next != NULL) {
                cn = cn->next;
            }
            cn->next = nn;  // Insert the new node at the end
        }
    }

    // Function to display the entire polynomial expression
    void displaypoly() {
        polynomial* cn = head;
        // Traverse through the list and display each term
        while (cn != NULL) {
            cn->display();
            cn = cn->next;
        }
        cout << endl;  // End with a new line after displaying the polynomial
    }

    // Friend function to allow access to the private members
    friend void addpolynomial(polynomial_exp& p1, polynomial_exp& p2);
};

// Function to add two polynomials
void addpolynomial(polynomial_exp& p1, polynomial_exp& p2) {
    // Pointers to traverse the two polynomials to be added
    polynomial* cn1 = p1.head;
    polynomial* cn2 = p2.head;
    
    // The resulting polynomial
    polynomial_exp p3;
    polynomial* cn3 = NULL;

    // Loop through both polynomials while both have terms
    while (cn1 != NULL && cn2 != NULL) {
        // Create a new node for the resulting polynomial
        polynomial* nn = new polynomial;
        if (p3.head == NULL) {
            p3.head = nn;  // Set the new node as head if it's the first node
            cn3 = nn;
        } else {
            cn3->next = nn;  // Link the new node to the result list
            cn3 = cn3->next;
        }

        // Compare the powers of terms in both polynomials
        if (cn1->pow > cn2->pow) {
            // If the power of the first term is greater, copy it to the result
            nn->pow = cn1->pow;
            nn->coeff = cn1->coeff;
            cn1 = cn1->next;  // Move to the next term in the first polynomial
        } else if (cn1->pow < cn2->pow) {
            // If the power of the second term is greater, copy it to the result
            nn->pow = cn2->pow;
            nn->coeff = cn2->coeff;
            cn2 = cn2->next;  // Move to the next term in the second polynomial
        } else {
            // If the powers are the same, add the coefficients
            nn->pow = cn1->pow;
            nn->coeff = cn1->coeff + cn2->coeff;
            cn1 = cn1->next;  // Move to the next term in both polynomials
            cn2 = cn2->next;
        }
    }

    // If any terms are left in the first polynomial, add them to the result
    while (cn1 != NULL) {
        polynomial* nn = new polynomial;
        cn3->next = nn;  // Link the new node to the result
        cn3 = cn3->next;
        nn->pow = cn1->pow;
        nn->coeff = cn1->coeff;
        cn1 = cn1->next;
    }

    // If any terms are left in the second polynomial, add them to the result
    while (cn2 != NULL) {
        polynomial* nn = new polynomial;
        cn3->next = nn;  // Link the new node to the result
        cn3 = cn3->next;
        nn->pow = cn2->pow;
        nn->coeff = cn2->coeff;
        cn2 = cn2->next;
    }

    // Display the resulting polynomial
    cout << "The sum of the polynomials is: "<<endl;
    cout<<"-----------------------------"<<endl;
    p3.displaypoly();
}

int main() {
    polynomial_exp p1, p2;
     int m,n,t;
    // Insert and display the first polynomial
    cout<<"Enter the number of test cases: ";
    cin>>t;
    while(t--)
    {
    cout<<"Enter the number of terms of first polynomial: ";
    cin>>m;
    cout << "Enter the first polynomial:\n";
    for(int i=0;i<m;i++)
    {
        p1.insertnode();
    }
    cout << "First polynomial: "<<endl;
    cout<<"-------------------"<<endl;
    p1.displaypoly();
    // Insert and display the second polynomial
    cout<<"Enter the number term of second polynomial: ";
    cin>>n;
    cout << "Enter the second polynomial:\n";
    for(int i=0;i<n;i++)
    {
    p2.insertnode();
    }
    cout << "Second polynomial: "<<endl;
    cout<<"--------------------"<<endl;
    p2.displaypoly();
    // Add the two polynomials and display the result
    addpolynomial(p1, p2);
    }
    return 0;
}
