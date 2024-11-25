#include <iostream>

using namespace std;

// Structure for BST Node
struct Node {
    int data;
    Node* left;
    Node* right;

    // Constructor to create a new node
    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

// Function to insert a new node in BST
Node* insert(Node* root, int value) {
    if (root == nullptr) {
        return new Node(value);  // If the tree is empty, return a new node
    }

    // Otherwise, recur down the tree
    if (value < root->data) {
        root->left = insert(root->left, value);  // Insert in left subtree
    } else if (value > root->data) {
        root->right = insert(root->right, value);  // Insert in right subtree
    }

    return root;  // Return the unchanged root pointer
}

// Function to search a value in the BST
Node* search(Node* root, int value) {
    // Base cases: root is null or the value is present at the root
    if (root == nullptr || root->data == value) {
        return root;
    }

    // Value is greater than root's data
    if (value > root->data) {
        return search(root->right, value);
    }

    // Value is smaller than root's data
    return search(root->left, value);
}

// Function to find the minimum value node in a tree
Node* minValueNode(Node* node) {
    Node* current = node;
    while (current && current->left != nullptr) {
        current = current->left;
    }
    return current;
}

// Function to delete a node in the BST
Node* deleteNode(Node* root, int value) {
    // Base case: If the tree is empty
    if (root == nullptr) {
        return root;
    }

    // If the value to be deleted is smaller than the root's data, then it lies in the left subtree
    if (value < root->data) {
        root->left = deleteNode(root->left, value);
    }

    // If the value to be deleted is greater than the root's data, then it lies in the right subtree
    else if (value > root->data) {
        root->right = deleteNode(root->right, value);
    }

    // If the value is the same as the root's data, then this is the node to be deleted
    else {
        // Node with only one child or no child
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Node with two children: Get the inorder successor (smallest in the right subtree)
        Node* temp = minValueNode(root->right);

        // Copy the inorder successor's content to this node
        root->data = temp->data;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

// Function for In-order traversal of the BST
void inorder(Node* root) {
    if (root != nullptr) {
        inorder(root->left);  // Visit left subtree
        cout << root->data << " ";  // Visit node
        inorder(root->right);  // Visit right subtree
    }
}

int main() {
    Node* root = nullptr;

    // Insert nodes into the BST
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    cout << "In-order traversal: ";
    inorder(root);  // Output: 20 30 40 50 60 70 80
    cout << endl;

    // Search for a value in the BST
    int searchValue = 40;
    Node* result = search(root, searchValue);
    if (result != nullptr) {
        cout << "Node " << searchValue << " found in the tree." << endl;
    } else {
        cout << "Node " << searchValue << " not found in the tree." << endl;
    }

    // Delete a node from the BST
    int deleteValue = 20;
    root = deleteNode(root, deleteValue);
    cout << "In-order traversal after deleting " << deleteValue << ": ";
    inorder(root);  // Output: 30 40 50 60 70 80
    cout << endl;

    return 0;
}
