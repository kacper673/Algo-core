#ifndef BST_H
#define BST_H

class BSTNode
{
public:
	BSTNode(int key_);

	static BSTNode* Insert(BSTNode* node, int key_);
	static BSTNode* Remove(BSTNode* root, int key_);

	static void printTreePreOrder(BSTNode* node);
	static void printTreePostOrder(BSTNode* node);
	static void printTreeInOrder(BSTNode* node);

	static BSTNode* min(BSTNode* root);
	static BSTNode* max(BSTNode* root);

	static BSTNode* inOrderSuccessor(BSTNode* n);
	static BSTNode* inOrderPredeccessor(BSTNode* n);

	static int hight(BSTNode* root);
	
	static int getKey(BSTNode* root) { return root->key; }
private:
	int key;
	BSTNode* Left;
	BSTNode* Right;
	BSTNode* Parent;
};




#endif 