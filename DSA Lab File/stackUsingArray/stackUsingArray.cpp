#include <iostream>
using namespace std;

#define MAX 100 // Maximum size of the stack

// Global Variables (to keep it simple for beginners)
int stack[MAX];
int top = -1; // -1 means stack is initially empty
int n; // Size requested by user

// 1. Push Operation (Add element)
void push() {
    int value;
    if (top == n - 1) {
        // If top reached the limit, we can't add more
        cout << "\nStack Overflow! Cannot push more elements.\n";
    } else {
        cout << "Enter value to push: ";
        cin >> value;
        top++; // Move top pointer up
        stack[top] = value; // Put value there
        cout << value << " pushed into stack.\n";
    }
}

// 2. Pop Operation (Remove element)
void pop() {
    if (top == -1) {
        // If top is -1, there is nothing to remove
        cout << "\nStack Underflow! Stack is empty.\n";
    } else {
        // We just move the top pointer down. The data is logically "deleted"
        cout << stack[top] << " popped from stack.\n";
        top--; 
    }
}

// 3. Traverse Operation (Display all elements)
void traverse() {
    if (top == -1) {
        cout << "\nStack is empty.\n";
    } else {
        cout << "\nStack elements (Top to Bottom): \n";
        // Loop from top down to 0
        for (int i = top; i >= 0; i--) {
            cout << stack[i] << endl;
        }
    }
}

int main() {
    int choice;
    
    cout << "Enter size of stack (max 100): ";
    cin >> n;

    // Menu Driven Program
    while (true) {
        cout << "\n--- STACK OPERATIONS ---";
        cout << "\n1. Push";
        cout << "\n2. Pop";
        cout << "\n3. Traverse (Display)";
        cout << "\n4. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: traverse(); break;
            case 4: cout << "Exiting..."; return 0;
            default: cout << "Invalid Choice! Try again.";
        }
    }
    return 0;
}