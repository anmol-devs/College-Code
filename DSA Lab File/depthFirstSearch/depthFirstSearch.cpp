#include <iostream>
using namespace std;

// The Blueprint for a Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Function to create a new node
Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Helper: Simple insertion to build the tree manually
// We are doing manual linking to keep the DFS logic pure and simple
Node* buildSampleTree() {
    /* Tree Structure:
            1
           / \
          2   3
         / \
        4   5
    */
    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    
    return root;
}

// --- THE DFS ALGORITHM (Recursive) ---
// This follows Preorder logic: Root -> Left -> Right
void performDFS(Node* node) {
    if (node == NULL) {
        return; // Base Case: We hit a dead end (wall)
    }

    // 1. Visit the Node (Print it)
    cout << node->data << " -> ";

    // 2. Dive Deeper into Left Branch
    performDFS(node->left);

    // 3. Dive Deeper into Right Branch
    performDFS(node->right);
}

int main() {
    // 1. Build the tree
    Node* root = buildSampleTree();

    cout << "Depth First Search (DFS) Traversal:\n";
    cout << "Start: ";
    
    // 2. Start the DFS
    performDFS(root);
    
    cout << "End" << endl;

    return 0;
}