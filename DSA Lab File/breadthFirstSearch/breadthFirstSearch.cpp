#include <iostream>
#include <queue> // We include the standard Queue library to make it easy
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

// Helper: Build a sample tree manually
Node* buildSampleTree() {
    /* Tree Structure:
             1        (Level 0)
           /   \
          2     3     (Level 1)
         / \   / \
        4   5 6   7   (Level 2)
    */
    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);
    return root;
}

// --- THE BFS ALGORITHM (Level Order) ---
void performBFS(Node* root) {
    // Base case: If tree is empty, do nothing
    if (root == NULL) return;

    // 1. Create a Queue and push the root
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        // 2. Get the node at the front
        Node* current = q.front();
        cout << current->data << " -> ";
        q.pop(); // Remove it from queue

        // 3. Add its children to the queue (if they exist)
        if (current->left != NULL) {
            q.push(current->left);
        }
        if (current->right != NULL) {
            q.push(current->right);
        }
    }
}

int main() {
    // 1. Build the tree
    Node* root = buildSampleTree();

    cout << "Breadth First Search (BFS) / Level Order Traversal:\n";
    cout << "Start: ";

    // 2. Run BFS
    performBFS(root);

    cout << "End" << endl;

    return 0;
}