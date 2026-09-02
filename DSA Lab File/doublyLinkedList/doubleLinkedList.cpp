#include <iostream>
using namespace std;

// The Blueprint for a Doubly Linked Node
struct Node {
    int data;
    Node* next; // Pointer to next node
    Node* prev; // Pointer to previous node
};

Node* head = NULL; // Global Head Pointer

// 1. Insert at Beginning
void insertFront() {
    int value;
    cout << "Enter value to insert at front: ";
    cin >> value;

    Node* newNode = new Node();
    newNode->data = value;
    newNode->prev = NULL; // It will be the first, so no previous
    newNode->next = head; // It points to the old head

    // If list wasn't empty, the old head must point back to new node
    if (head != NULL) {
        head->prev = newNode;
    }

    head = newNode; // Update head to the new node
    cout << value << " inserted at front.\n";
}

// 2. Insert at End
void insertEnd() {
    int value;
    cout << "Enter value to insert at end: ";
    cin >> value;

    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = NULL; // It will be last, so next is NULL

    if (head == NULL) {
        newNode->prev = NULL;
        head = newNode;
        return;
    }

    Node* temp = head;
    // Walk to the last node
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // Connect them
    temp->next = newNode; // Last node points to new node
    newNode->prev = temp; // New node points back to last node
    cout << value << " inserted at end.\n";
}

// 3. Insert After a specific value
void insertAfter() {
    int key, value;
    cout << "Enter value to search for: ";
    cin >> key;
    cout << "Enter new value to insert after it: ";
    cin >> value;

    Node* temp = head;
    // Find the key
    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Key " << key << " not found!\n";
        return;
    }

    // Create the new node
    Node* newNode = new Node();
    newNode->data = value;

    // The 4 Connection Logic
    newNode->next = temp->next; // 1. New node points to next person
    newNode->prev = temp;       // 2. New node points to current person
    
    if (temp->next != NULL) {
        temp->next->prev = newNode; // 3. Next person points back to new node
    }
    temp->next = newNode;       // 4. Current person points to new node

    cout << value << " inserted after " << key << ".\n";
}

// 4. Traverse Forward
void traverseForward() {
    if (head == NULL) {
        cout << "\nList is empty.\n";
        return;
    }
    Node* temp = head;
    cout << "\nForward: ";
    while (temp != NULL) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

// 5. Traverse Backward (Unique to DLL)
void traverseBackward() {
    if (head == NULL) return;

    Node* temp = head;
    // Go to the last node first
    while (temp->next != NULL) {
        temp = temp->next;
    }

    cout << "Backward: ";
    while (temp != NULL) {
        cout << temp->data << " <-> ";
        temp = temp->prev; // Move backwards
    }
    cout << "NULL\n";
}

int main() {
    int choice;
    while (true) {
        cout << "\n--- DOUBLY LINKED LIST ---";
        cout << "\n1. Insert at Front";
        cout << "\n2. Insert at End";
        cout << "\n3. Insert After Value";
        cout << "\n4. Display (Forward & Backward)";
        cout << "\n5. Exit";
        cout << "\nEnter Choice: ";
        cin >> choice;

        switch(choice) {
            case 1: insertFront(); break;
            case 2: insertEnd(); break;
            case 3: insertAfter(); break;
            case 4: traverseForward(); traverseBackward(); break;
            case 5: return 0;
            default: cout << "Invalid!\n";
        }
    }
}