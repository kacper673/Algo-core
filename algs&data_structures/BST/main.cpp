#include "bst_tree.h"
#include <iostream>

int main() {
    BSTNode* root = nullptr;
    
    root = BSTNode::Insert(root, 10);
    root = BSTNode::Insert(root, 5);
    root = BSTNode::Insert(root, 15);
    root = BSTNode::Insert(root, 2);
    root = BSTNode::Insert(root, 7);
    root = BSTNode::Insert(root, 20);

  
    std::cout << "In-order:\n";
    BSTNode::printTreeInOrder(root);

    std::cout << "\nPre-order:\n";
    BSTNode::printTreePreOrder(root);

    std::cout << "\nPost-order:\n";
    BSTNode::printTreePostOrder(root);

    std::cout << "\nMin:\n";
    std::cout << BSTNode::getKey(BSTNode::min(root));
    
    std::cout << "\nMax:\n";
    std::cout << BSTNode::getKey(BSTNode::max(root));


    std::cout << "\nRoot key\n";
    std::cout << BSTNode::getKey(root);

    std::cout << "\nInOrderSuccessor:\n";
    std::cout<<BSTNode::getKey(BSTNode::inOrderSuccessor(root));

    std::cout << "\nInOrderPredecessor:\n";
    std::cout << BSTNode::getKey(BSTNode::inOrderPredeccessor(root));
    
    std::cout << "\nHight:\n";
    std::cout<<BSTNode::hight(root)<<"\n";

    BSTNode::Remove(root, 7);

    std::cout << "In-order after one delete:\n";
    BSTNode::printTreeInOrder(root);

	return 0;
}