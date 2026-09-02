#include <iostream>
using namespace std;

// The Blueprint for a Node
struct Node {
    int data;
    Node* next;
};

// Global Head Pointer (Starts empty)
Node* head = NULL;

// Helper: Insert at end (Just to build the list)
void insert(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    cout << value << " inserted.\n";
}

// 1. Delete at Beginning
void deleteBeg() {
    if (head == NULL) {
        cout << "\nList is empty!\n";
    } else {
        Node* temp = head;      // Hold the current head
        head = head->next;      // Move head to the next node
        cout << "\nDeleted: " << temp->data << endl;
        delete temp;            // Free memory
    }
}

// 2. Delete at End
void deleteEnd() {
    if (head == NULL) {
        cout << "\nList is empty!\n";
    } else if (head->next == NULL) {
        // Special Case: Only 1 node in list
        cout << "\nDeleted: " << head->data << endl;
        delete head;
        head = NULL;
    } else {
        Node* temp = head;
        // Walk until SECOND TO LAST node
        while (temp->next->next != NULL) {
            temp = temp->next;
        }
        // temp is now second to last. temp->next is the last one.
        Node* toDelete = temp->next;
        temp->next = NULL;       // Break the link
        cout << "\nDeleted: " << toDelete->data << endl;
        delete toDelete;         // Free memory
    }
}

// 3. Delete at Any Specific Location
void deleteAtPos() {
    int pos, i;
    if (head == NULL) {
        cout << "\nList is empty!\n";
        return;
    }

    cout << "Enter position to delete (1, 2, 3...): ";
    cin >> pos;

    if (pos == 1) {
        deleteBeg(); // If user wants to delete 1st, reuse that function
        return;
    }

    Node* temp = head;
    // Walk to the node BEFORE the target (pos - 2)
    for (i = 0; i < pos - 2; i++) {
        temp = temp->next;
        // Safety check if position is invalid
        if (temp == NULL || temp->next == NULL) {
            cout << "\nPosition out of range!\n";
            return;
        }
    }

    // temp is now just BEFORE the one to delete
    Node* toDelete = temp->next;
    temp->next = temp->next->next; // Bypass the node to delete
    
    cout << "\nDeleted from pos " << pos << ": " << toDelete->data << endl;
    delete toDelete;
}

// Helper: Display List
void display() {
    if (head == NULL) {
        cout << "\nList is empty.\n";
        return;
    }
    Node* temp = head;
    cout << "\nList: ";
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main() {
    int choice, val;
    
    // Pre-filling list for easy testing
    insert(10); insert(20); insert(30); insert(40);

    while (true) {
        cout << "\n--- LINKED LIST DELETION ---";
        cout << "\n1. Display List";
        cout << "\n2. Delete from Beginning";
        cout << "\n3. Delete from End";
        cout << "\n4. Delete from Specific Position";
        cout << "\n5. Exit";
        cout << "\nEnter Choice: ";
        cin >> choice;

        switch(choice) {
            case 1: display(); break;
            case 2: deleteBeg(); break;
            case 3: deleteEnd(); break;
            case 4: deleteAtPos(); break;
            case 5: return 0;
            default: cout << "Invalid!\n";
        }
    }
}