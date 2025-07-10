#pragma once
#ifndef TREE_H
#define TREE_H

#include <string>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x);
};

TreeNode* createTree(int height);
int height(TreeNode* root);
int diameterOfBinaryTree(TreeNode* root);
void printTree(TreeNode*& root, const std::string& prefix = "", bool isLeft = false);

#endif 
