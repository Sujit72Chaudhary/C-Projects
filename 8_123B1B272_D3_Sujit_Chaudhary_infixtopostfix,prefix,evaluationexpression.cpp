#include <iostream>     // Include the iostream library for input-output
#include <string>       // Include the string library for string manipulation
#include <cmath>        // Include the cmath library for mathematical operations
using namespace std;    // Use the standard namespace

#define MAX 100         // Define a constant MAX as 100, which will be used for stack size

// Class to implement a stack for characters (used for operators and parentheses)
class Stack {
    int top;                // Variable to store the index of the top element in the stack
    char arr[MAX];          // Array to store stack elements of type char

public:
    // Constructor to initialize the top of the stack to -1 (indicating an empty stack)
    Stack() { top = -1; }

    // Function to check if the stack is empty
    bool isEmpty() {
        return top == -1;   // If top is -1, the stack is empty
    }

    // Function to check if the stack is full
    bool isFull() {
        return top == MAX - 1;  // If top is MAX - 1, the stack is full
    }

    // Function to push a character onto the stack
    void push(char ch) {
        if (isFull()) {     // If the stack is full, print an overflow message
            cout << "Stack is full! Unable to push more elements." << endl;
        } else {            // Otherwise, increment the top and add the element
            arr[++top] = ch;
        }
    }

    // Function to pop a character from the stack
    char pop() {
        if (isEmpty()) {    // If the stack is empty, print an underflow message
            cout << "Stack is empty! Nothing to pop." << endl;
            return '\0';    // Return a null character if the stack is empty
        } else {            // Otherwise, return the top element and decrement the top
            return arr[top--];
        }
    }

    // Function to peek at the top character of the stack without removing it
    char peek() {
        if (!isEmpty()) {   // If the stack is not empty, return the top element
            return arr[top];
        } else {
            return '\0';    // Return a null character if the stack is empty
        }
    }
};

// Class to implement a stack for integers (used for postfix and prefix evaluation)
class IntStack {
    int top;                // Variable to store the index of the top element in the stack
    int arr[MAX];           // Array to store stack elements of type int

public:
    // Constructor to initialize the top of the stack to -1 (indicating an empty stack)
    IntStack() { top = -1; }

    // Function to check if the stack is empty
    bool isEmpty() {
        return top == -1;   // If top is -1, the stack is empty
    }

    // Function to check if the stack is full
    bool isFull() {
        return top == MAX - 1;  // If top is MAX - 1, the stack is full
    }

    // Function to push an integer onto the stack
    void push(int num) {
        if (isFull()) {     // If the stack is full, print an overflow message
            cout << "Stack is full! Unable to push more elements." << endl;
        } else {            // Otherwise, increment the top and add the element
            arr[++top] = num;
        }
    }

    // Function to pop an integer from the stack
    int pop() {
        if (isEmpty()) {    // If the stack is empty, print an underflow message
            cout << "Stack is empty! Nothing to pop." << endl;
            return -1;      // Return -1 if the stack is empty
        } else {            // Otherwise, return the top element and decrement the top
            return arr[top--];
        }
    }

    // Function to peek at the top integer of the stack without removing it
    int peek() {
        if (!isEmpty()) {   // If the stack is not empty, return the top element
            return arr[top];
        } else {
            return -1;      // Return -1 if the stack is empty
        }
    }
};

// Function to determine the precedence of an operator
int precedence(char op) {
    if (op == '+' || op == '-') return 1;    // Precedence of '+' and '-' is 1
    if (op == '*' || op == '/') return 2;    // Precedence of '*' and '/' is 2
    if (op == '^') return 3;                 // Precedence of '^' is 3
    return 0;                                // Return 0 for non-operators
}

// Function to check if a character is an operator
bool isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');  // Return true for valid operators
}

// Function to check if an operator is left-associative
bool isLeftAssociative(char op) {
    if (op == '^') return false;  // '^' is right-associative, return false
    return true;                  // All others are left-associative, return true
}

// Function to manually reverse a string
string reverseString(string str) {
    int n = str.length();                 // Get the length of the string
    for (int i = 0; i < n / 2; i++) {     // Loop through half the string
        swap(str[i], str[n - i - 1]);     // Swap characters from the start and end
    }
    return str;                           // Return the reversed string
}

// Function to convert an infix expression to postfix
string infixToPostfix(string infix) {
    Stack st;                             // Create a stack to store operators
    string postfix = "";                  // Initialize an empty string for the postfix result

    for (int i = 0; i < infix.length(); i++) {  // Traverse the infix expression
        char c = infix[i];                // Get the current character

        if (isalnum(c)) {                 // If the character is an operand (alphanumeric)
            postfix += c;                 // Add it directly to the postfix result
        } else if (c == '(') {            // If the character is '(', push it to the stack
            st.push(c);
        } else if (c == ')') {            // If the character is ')'
            while (!st.isEmpty() && st.peek() != '(') {   // Pop until '(' is found
                postfix += st.pop();      // Add popped operators to postfix result
            }
            st.pop();                     // Remove the '(' from the stack
        } else if (isOperator(c)) {       // If the character is an operator
            while (!st.isEmpty() && precedence(c) <= precedence(st.peek()) && isLeftAssociative(c)) {
                postfix += st.pop();      // Pop operators with higher or equal precedence
            }
            st.push(c);                   // Push the current operator to the stack
        }
    }

    // Pop any remaining operators from the stack
    while (!st.isEmpty()) {
        postfix += st.pop();
    }

    return postfix;                       // Return the resulting postfix expression
}

// Function to convert an infix expression to prefix
string infixToPrefix(string infix) {
    infix = reverseString(infix);         // Reverse the infix expression

    // Swap '(' with ')' and vice versa
    for (int i = 0; i < infix.length(); i++) {
        if (infix[i] == '(') infix[i] = ')';
        else if (infix[i] == ')') infix[i] = '(';
    }

    string postfix = infixToPostfix(infix);   // Convert the modified infix to postfix
    return reverseString(postfix);            // Reverse the postfix to get the prefix
}

// Function to evaluate a postfix expression
int evaluatePostfix(string postfix) {
    IntStack st;                            // Create a stack to store operands

    for (int i = 0; i < postfix.length(); i++) {  // Traverse the postfix expression
        char c = postfix[i];                // Get the current character

        if (isalnum(c)) {                   // If the character is an operand
            st.push(c - '0');               // Push it to the stack (convert char to int)
        } else if (isOperator(c)) {         // If the character is an operator
            int val1 = st.pop();            // Pop the first operand
            int val2 = st.pop();            // Pop the second operand

            switch (c) {                    // Perform the operation based on the operator
                case '+': st.push(val2 + val1); break;
                case '-': st.push(val2 - val1); break;
                case '*': st.push(val2 * val1); break;
                case '/': st.push(val2 / val1); break;
                case '^': st.push(pow(val2, val1)); break;
            }
        }
    }

    return st.pop();                        // Return the final result from the stack
}

// Function to evaluate a prefix expression
int evaluatePrefix(string prefix) {
    IntStack st;                            // Create a stack to store operands

    // Traverse the prefix expression from right to left
    for (int i = prefix.length() - 1; i >= 0; i--) {
        char c = prefix[i];                 // Get the current character

        if (isalnum(c)) {                   // If the character is an operand
            st.push(c - '0');               // Push it to the stack (convert char to int)
        } else if (isOperator(c)) {         // If the character is an operator
            int val1 = st.pop();            // Pop the first operand
            int val2 = st.pop();            // Pop the second operand

            switch (c) {                    // Perform the operation based on the operator
                case '+': st.push(val1 + val2); break;
                case '-': st.push(val1 - val2); break;
                case '*': st.push(val1 * val2); break;
                case '/': st.push(val1 / val2); break;
                case '^': st.push(pow(val1, val2)); break;
            }
        }
    }

    return st.pop();                        // Return the final result from the stack
}

// Main function to display the menu and interact with the user
int main() {
    string infixExp, postfixExp, prefixExp;  // Variables to store expressions
    int choice;                             // Variable to store user choice

    // Loop to display the menu until the user chooses to exit
    do {
        cout << "\n Expression Converter and Evaluator\n";
        cout<<"************************************"<<endl;
        cout << "1. Convert Infix to Postfix Expression\n";
        cout << "2. Convert Infix to Prefix Expression\n";
        cout << "3. Evaluate Postfix Expression\n";
        cout << "4. Evaluate Prefix Expression\n";
        cout << "5. Exit\n";
        cout << "Please enter your choice: ";
        cin >> choice;                      // Get the user's choice

        switch (choice) {
            case 1:
                cout << "Enter an infix expression: ";
                cin >> infixExp;            // Get the infix expression from the user
                postfixExp = infixToPostfix(infixExp);    // Convert infix to postfix
                cout<<"------------------------------------------------------"<<endl;
                cout << "The equivalent postfix expression is: " << postfixExp << endl;
                cout<<"--------------------------------------------------------"<<endl;
                break;

            case 2:
                cout << "Enter an infix expression: ";
                cin >> infixExp;            // Get the infix expression from the user
                prefixExp = infixToPrefix(infixExp);      // Convert infix to prefix
                cout<<"-----------------------------------------------------"<<endl;
                cout << "The equivalent prefix expression is: " << prefixExp << endl;
                cout<<"------------------------------------------------------"<<endl;
                break;

            case 3:
                if (postfixExp.empty()) {   // Check if a postfix expression is available
                    cout << "No postfix expression available. Please convert an infix expression first.\n";
                } else {
                    cout << "Postfix expression to evaluate: " << postfixExp << endl;
                    cout<<"-------------------------------------"<<endl;
                    cout << "Evaluation result: " << evaluatePostfix(postfixExp) << endl;
                    cout<<"-------------------------------------"<<endl;
                }
                break;

            case 4:
                if (prefixExp.empty()) {    // Check if a prefix expression is available
                    cout << "No prefix expression available. Please convert an infix expression first.\n";
                } else {
                    cout << "Prefix expression to evaluate: " << prefixExp << endl;
                    cout<<"----------------------------------"<<endl;
                    cout << "Evaluation result: " << evaluatePrefix(prefixExp) << endl;
                    cout<<"----------------------------------"<<endl;
                }
                break;

            case 5:
                cout << "Exiting the program.Thank you!" << endl;
                cout<<"************************************"<<endl;
                break;

            default:
                cout <<"Invalid choice! Please enter a valid option ->>>>>>>>." << endl;
        }
    } while (choice != 5);                 // Loop until the user chooses to exit

    return 0;
}
