//BST.cpp
#include <iostream>
#include <cstdlib>

#include "BinarySearchTree.cpp"

using namespace std;

int main()
{
	int input = 0;

	int keyData[15] = {23,56,78,3,1,8,4,7,5,90,67,45,91,65,100};

	BST tree;

	cout << "Printing the tree" << endl ;

	tree.printTree();

	for(int i = 0; i < 15 ; i++ ){
		tree.sendData(keyData[i]);
	}

	tree.printTree();

	cout << "Enter nodes to delete. Enter -1 to stop." << endl;

	while(input != -1)
	{
		cout << "Delete Node: ";
		cin >> input;
		if(input != -1)
		{
			cout << endl;
			tree.delNode(input);
			tree.printTree();
			cout << endl;
		}

	}
	return 0;
}
