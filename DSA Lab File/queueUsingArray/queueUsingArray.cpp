#include <iostream>
using namespace std;

#define MAX 100

// Global Variables
int queue[MAX];
int front = -1;
int rear = -1;
int n; // Size requested by user

// 1. Insertion Operation (Enqueue)
void enqueue() {
    int value;
    if (rear == n - 1) {
        // If the rear reached the end of the array
        cout << "\nQueue Overflow! Queue is full.\n";
    } else {
        if (front == -1) {
            front = 0; // If inserting the first element, set front to 0
        }
        cout << "Enter value to insert: ";
        cin >> value;
        rear++; // Move rear pointer forward
        queue[rear] = value;
        cout << value << " inserted into queue.\n";
    }
}

// 2. Deletion Operation (Dequeue)
void dequeue() {
    if (front == -1 || front > rear) {
        // If front is -1 (empty) or front crossed rear (all deleted)
        cout << "\nQueue Underflow! Queue is empty.\n";
        // Resetting pointers for safety
        front = -1;
        rear = -1;
    } else {
        cout << queue[front] << " deleted from queue.\n";
        front++; // Move front pointer forward (Line moves up)
    }
}

// 3. Traverse Operation (Display)
void traverse() {
    if (front == -1 || front > rear) {
        cout << "\nQueue is empty.\n";
    } else {
        cout << "\nQueue elements (Front to Rear): ";
        for (int i = front; i <= rear; i++) {
            cout << queue[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    int choice;
    cout << "Enter size of queue (max 100): ";
    cin >> n;

    while (true) {
        cout << "\n--- QUEUE OPERATIONS ---";
        cout << "\n1. Enqueue (Insert)";
        cout << "\n2. Dequeue (Delete)";
        cout << "\n3. Traverse (Display)";
        cout << "\n4. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: traverse(); break;
            case 4: return 0;
            default: cout << "Invalid Choice!";
        }
    }
    return 0;
}