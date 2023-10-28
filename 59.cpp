#include <iostream>
#include <algorithm>

// Structure for an AVL tree node
struct AVLNode {
    int data;
    AVLNode* left;
    AVLNode* right;
    int height; // Height of the node

    AVLNode(int val) : data(val), left(nullptr), right(nullptr), height(1) {}
};

// Function to get the height of a node
int getHeight(AVLNode* node) {
    if (node == nullptr) {
        return 0;
    }
    return node->height;
}

// Function to update the height of a node
void updateHeight(AVLNode* node) {
    node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));
}

// Function to perform a right rotation
AVLNode* rightRotate(AVLNode* y) {
    AVLNode* x = y->left;
    AVLNode* T2 = x->right;

    x->right = y;
    y->left = T2;

    updateHeight(y);
    updateHeight(x);

    return x;
}

// Function to perform a left rotation
AVLNode* leftRotate(AVLNode* x) {
    AVLNode* y = x->right;
    AVLNode* T2 = y->left;

    y->left = x;
    x->right = T2;

    updateHeight(x);
    updateHeight(y);

    return y;
}

// Function to balance the AVL tree after deletion
AVLNode* balanceTree(AVLNode* node) {
    if (node == nullptr) {
        return nullptr;
    }

    updateHeight(node);

    int balanceFactor = getHeight(node->left) - getHeight(node->right);

    // Left Heavy
    if (balanceFactor > 1) {
        // Left-Right Case
        if (getHeight(node->left->left) < getHeight
