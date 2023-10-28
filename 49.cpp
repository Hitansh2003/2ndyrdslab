#include <iostream>
#include <map>
#include <queue>

// Structure for a binary tree node
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Structure to represent a node and its horizontal distance
struct HDNode {
    TreeNode* node;
    int hd;

    HDNode(TreeNode* n, int h) : node(n), hd(h) {}
};

// Function to print the top view of a binary tree
void topView(TreeNode* root) {
    if (!root) return;

    std::map<int, int> topViewMap;  // Maps horizontal distance to node value
    std::queue<HDNode> q;  // Queue for level-order traversal

    q.push(HDNode(root, 0));

    while (!q.empty()) {
        HDNode curr = q.front();
        q.pop();
        int hd = curr.hd;
        TreeNode* node = curr.node;

        if (topViewMap.find(hd) == topViewMap.end()) {
            topViewMap[hd] = node->data;
        }

        if (node->left) {
            q.push(HDNode(node->left, hd - 1));
        }

        if (node->right) {
            q.push(HDNode(node->right, hd + 1));
        }
    }

    for (const auto& pair : topViewMap) {
        std::cout << pair.second << " ";
    }
    std::cout << std::endl;
}

int main() {
    // Create a sample binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->left->right->right = new TreeNode(5);
    root->left->right->right->right = new TreeNode(6);

    std::cout << "Top view of the binary tree: ";
    topView(root);

    return 0;
}
