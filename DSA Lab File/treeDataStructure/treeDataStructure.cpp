#include <iostream>
using namespace std;

// The Blueprint for a Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Function to Create a New Node
Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// 1. Insertion Function (Recursive)
Node* insert(Node* root, int value) {
    // If the spot is empty, put the new node here
    if (root == NULL) {
        return createNode(value);
    }

    // If value is smaller, go to Left subtree
    if (value < root->data) {
        root->left = insert(root->left, value);
    }
    // If value is larger, go to Right subtree
    else if (value > root->data) {
        root->right = insert(root->right, value);
    }

    // Return the unchanged root pointer
    return root;
}

// 2. Inorder Traversal (Left -> Root -> Right)
void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);       // Visit Left
        cout << root->data << " "; // Visit Root
        inorder(root->right);      // Visit Right
    }
}

// 3. Preorder Traversal (Root -> Left -> Right)
void preorder(Node* root) {
    if (root != NULL) {
        cout << root->data << " "; // Visit Root
        preorder(root->left);      // Visit Left
        preorder(root->right);     // Visit Right
    }
}

// 4. Postorder Traversal (Left -> Right -> Root)
void postorder(Node* root) {
    if (root != NULL) {
        postorder(root->left);     // Visit Left
        postorder(root->right);    // Visit Right
        cout << root->data << " "; // Visit Root
    }
}

int main() {
    Node* root = NULL; // Initially the tree is empty
    int choice, val;

    // Pre-filling some data for testing
    // Tree Structure:
    //      50
    //     /  \
    //   30    70
    //   / \
    //  20 40
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);

    while (true) {
        cout << "\n--- BINARY SEARCH TREE OPERATIONS ---";
        cout << "\n1. Insert Node";
        cout << "\n2. Inorder Traversal (Sorted)";
        cout << "\n3. Preorder Traversal";
        cout << "\n4. Postorder Traversal";
        cout << "\n5. Exit";
        cout << "\nEnter Choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> val;
                root = insert(root, val);
                break;
            case 2:
                cout << "Inorder: ";
                inorder(root);
                cout << endl;
                break;
            case 3:
                cout << "Preorder: ";
                preorder(root);
                cout << endl;
                break;
            case 4:
                cout << "Postorder: ";
                postorder(root);
                cout << endl;
                break;
            case 5:
                return 0;
            default:
                cout << "Invalid Choice!\n";
        }
    }
    return 0;
}