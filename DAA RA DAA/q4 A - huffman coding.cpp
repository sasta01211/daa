#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

// A tree node structure to store a character, its frequency, and pointers to its left and right children
struct Node {
    char ch;
    int freq;
    Node* left;
    Node* right;

    Node(char ch, int freq) {
        this->ch = ch;
        this->freq = freq;
        left = right = nullptr;
    }
};

// Comparator function to create a min-heap
struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};

// Function to generate the Huffman codes
void generateHuffmanCodes(Node* root, const string& str, unordered_map<char, string>& huffmanCodes) {
    if (root == nullptr) return;

    // If it's a leaf node, store the code for the character
    if (!root->left && !root->right) {
        huffmanCodes[root->ch] = str;
    }

    // Recur for left and right subtrees
    generateHuffmanCodes(root->left, str + "0", huffmanCodes);
    generateHuffmanCodes(root->right, str + "1", huffmanCodes);
}

// Function to build the Huffman tree
Node* buildHuffmanTree(const unordered_map<char, int>& freq) {
    priority_queue<Node*, vector<Node*>, Compare> minHeap;

    // Create a leaf node for each character and push it to the min-heap
    for (const auto& pair : freq) {
        minHeap.push(new Node(pair.first, pair.second));
    }

    // Build the tree
    while (minHeap.size() > 1) {
        Node* left = minHeap.top();
        minHeap.pop();
        Node* right = minHeap.top();
        minHeap.pop();

        // Create a new internal node with a frequency equal to the sum of the two nodes' frequencies
        Node* internalNode = new Node('\0', left->freq + right->freq);
        internalNode->left = left;
        internalNode->right = right;

        // Push the internal node back into the min-heap
        minHeap.push(internalNode);
    }

    return minHeap.top(); // The root of the Huffman tree
}

int main() {
    // Character and frequency pairs
    unordered_map<char, int> freq = {{'A', 5}, {'B', 9}, {'C', 12}, {'D', 13}, {'E', 16}, {'F', 45}};
    
    // Build the Huffman tree
    Node* root = buildHuffmanTree(freq);

    // Generate Huffman codes
    unordered_map<char, string> huffmanCodes;
    generateHuffmanCodes(root, "", huffmanCodes);

    // Print the Huffman codes
    cout << "Character and Huffman Code:" << endl;
    for (const auto& pair : huffmanCodes) {
        cout << pair.first << ": " << pair.second << endl;
    }

    return 0;
}
