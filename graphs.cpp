#include <iostream>
#include <ctime>
#include "graph.h"

int main() {
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    int height = 4 + std::rand() % 3;
    TreeNode* root = createTree(height);

    std::cout << "Generated binary tree:" << std::endl;
    printTree(root);

    int diameter = diameterOfBinaryTree(root);
    std::cout << "\nDiameter of the tree: " << diameter << std::endl;

    return 0;
}
