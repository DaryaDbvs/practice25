#include "graph.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

TreeNode::TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

TreeNode* createTree(int height) {
    if (height == 0) return nullptr;

    TreeNode* node = new TreeNode(rand() % 100);

    if (rand() % 3) {
        node->left = createTree(height - 1);
    }
    if (rand() % 3) {
        node->right = createTree(height - 1);
    }

    return node;
}

int height(TreeNode* root) {
    if (root == nullptr) return 0;
    return 1 + std::max(height(root->left), height(root->right));
}

int diameterOfBinaryTree(TreeNode* root) {
    if (root == nullptr) return 0;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    int leftDiameter = diameterOfBinaryTree(root->left);
    int rightDiameter = diameterOfBinaryTree(root->right);

    return std::max({ leftDiameter, rightDiameter, leftHeight + rightHeight });
}

void printTree(TreeNode*& root, const std::string& prefix, bool isLeft) {
    if (root == nullptr) return;

    std::cout << prefix;
    std::cout << (isLeft ? "|-- " : "|__ ");
    std::cout << root->val << std::endl;

    printTree(root->left, prefix + (isLeft ? "|   " : "    "), true);
    printTree(root->right, prefix + (isLeft ? "|   " : "    "), false);
}
