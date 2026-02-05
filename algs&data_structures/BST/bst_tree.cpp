#include "bst_tree.h"
#include <iostream>

//constructor
BSTNode::BSTNode(int key_) {
	key = key_;
	Left = nullptr;
	Right = nullptr;
	Parent = nullptr;
}

//min
BSTNode* BSTNode::min(BSTNode* root) {
	while (root->Left != nullptr) {
		root = root->Left;
	}
	return root;
}

//max
BSTNode* BSTNode::max(BSTNode* root) {
	while (root->Right != nullptr) {
		root = root->Right;
	}
	return root;
}


//insert
BSTNode* BSTNode::Insert(BSTNode* node, int key_) {
	if (node == nullptr) {
		return new BSTNode(key_);
	}

	if (key_ < node->key) {
		BSTNode* leftChild = Insert(node->Left, key_);
		node->Left = leftChild;
		leftChild->Parent = node;
	}
	else if (key_ > node->key) {
		BSTNode* rightChild = Insert(node->Right, key_);
		node->Right = rightChild;
		rightChild->Parent = node;
	}

	return node;
}

//remove
BSTNode* BSTNode::Remove(BSTNode* root, int key_) {
	
	if (root == nullptr) return nullptr;
	
	if (key_ < root->key) {
		root->Left = Remove(root->Left, key_); 
	}
	else if (key_ > root->key) {
		root->Right = Remove(root->Right, key_); 
	}
	else {
		if (root->Left == nullptr && root->Right == nullptr) {
			delete root;
			return nullptr;
		}
	
		else if (root->Left == nullptr) {
			BSTNode* temp = root->Right;
			temp->Parent = root->Parent;
			delete root;
			return temp;
		}
	
		else if (root->Right == nullptr) {
			BSTNode* temp = root->Left;
			temp->Parent = root->Parent;
			delete root;
			return temp;
		}

	
		BSTNode* temp = min(root->Right);
		root->key = temp->key;
		root->Right = Remove(root->Right, temp->key);

	}



}

//InOrder print - printing sorted tree from lowest to highest key
void BSTNode::printTreeInOrder(BSTNode* node) {
	if (node == nullptr) return;

	printTreeInOrder(node->Left);
	std::cout << node->key<<" ";
	printTreeInOrder(node -> Right);
}

//PostOrder print - children first, then root
void BSTNode::printTreePostOrder(BSTNode* node) {
	if (node == nullptr) return;

	printTreePostOrder(node->Left);
	printTreePostOrder(node->Right);
	std::cout << node->key<<" ";
}

//PreOrder print
void BSTNode::printTreePreOrder(BSTNode* node) {
	if (node == nullptr) return;

	std::cout << node->key<<" ";
	printTreePreOrder(node->Left);
	printTreePreOrder(node->Right);
}

//hight
int BSTNode::hight(BSTNode* root) {
	if (root == nullptr) return -1;
	
	int hight_l = hight(root->Left);
	int hight_r = hight(root->Right);


	return 1 + ((hight_r > hight_l) ? hight_r : hight_l);

}

BSTNode* BSTNode::inOrderSuccessor(BSTNode* n) {
	
	if (n->Right != nullptr) return min(n->Right);

	BSTNode* p = n->Parent;
	while (p != nullptr && n == p->Right) {
		n = p;
		p = p->Parent;
	}
	return p;
}

BSTNode* BSTNode::inOrderPredeccessor(BSTNode* n) {

	if (n->Left != nullptr) {
		return max(n->Left);
	}

	BSTNode* p = n->Parent;
	while (p != nullptr && n == p->Left) {
		n = p;
		p = p->Parent;
	}
	return p;

}
