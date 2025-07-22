//BinarySearchTree.h
class BST {
private:
	struct node 
	{
		int data;
		node* left;
		node* right;
	};

	node* root;
	void addNode(int key , node* ptr);
	void setPrintTree(node* ptr);
	void delNodePrivate(int key , node* head);
	void delRootNode();
	int smallestNumPrivate(node* ptr);
	void delMatchNode(node* head, node* match, bool left);

public:
	BST();
	node* makeNode(int key);
	void sendData(int key);
	void printTree();
	void delNode(int key);
	int smallestNum();
};
