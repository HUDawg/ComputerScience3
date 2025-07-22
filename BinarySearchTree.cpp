//BinarySearchTree.cpp
#include <iostream>
#include <cstdlib>

#include "BinarySearchTree.h"

using namespace std;

BST::BST() 
{
		root = NULL;
}

BST::node* BST::makeNode(int key)
{
		node* c = new node;
		c->data = key;
		c->left = NULL;
		c->right = NULL;

		return c;
}

void BST::sendData(int key)
{
	addNode(key, root);
}

void BST::addNode(int key, node* ptr)
{
	if(root == NULL){
		root = makeNode(key);
	}
	else if(key < ptr->data)
	{
		if(ptr->left != NULL){
			addNode(key , ptr->left);
		}
		else
		{
			ptr->left = makeNode(key);
		}
	}
	else if(key > ptr->data)
	{
		if(ptr->right != NULL){
			addNode(key , ptr->right);
		}
		else
		{
			ptr->right = makeNode(key);
		}
	}
	else
	{
		cout << "Data " << key << " has been used." << endl;
	}
}

void BST::printTree()
{
	setPrintTree(root);
}

void BST::setPrintTree(node* ptr)
{
	if(root != NULL)
	{
		if(ptr->left != NULL)
		{
			setPrintTree(ptr->left);
		}

		cout << ptr->data << " ";
		
		if(ptr->right != NULL)
		{
			setPrintTree(ptr->right);
		}
	}
	else
	{
		cout << " Tree Empty " ;
	}
}

void BST::delNode(int key)
{
	delNodePrivate(key,root);
}

void BST::delNodePrivate(int key , node* head)
{
	if(root != NULL)
	{
		if(root->data == key)
		{
			delRootNode(); 								//RemoveRootMatch
		}
		else
		{
			if(key < head->data && head->left != NULL)
			{
				head->left->data == key ?
				delMatchNode(head , head->left , true) :		//RemoveMatch
				delNodePrivate(key,head->left);
			}
			else if(key > head->data && head->right != NULL)
			{
				head->right->data == key ?
				delMatchNode(head , head->right , false) :		//RemoveMatch
				delNodePrivate(key , head->right);
			}
			else
			{
				cout << "The key "<< key << "was not found in tree" << endl;
			}
		}
	}
	else
	{
		cout << " Tree is empty \n";
	}
}

void BST::delRootNode()
{
	if(root != NULL)
	{
		node* tempPtr = root;
		int tempKey = root->data;
		int smallestInRightSubTree;

		if(root->left == NULL && root->right == NULL){
			root = NULL;
			delete tempPtr;
		}
		else if(root->left == NULL && root->right != NULL){
			root = root->right;
			tempPtr->right = NULL;
			delete tempPtr;
			cout << "The root node with key " << tempKey << " was deleted."
					"The root contains data " << root->data << endl;
		}
		else if(root->left != NULL && root->right == NULL){
			root = root->left;
			tempPtr->left = NULL;
			delete tempPtr;
			cout << "The root node with key " << tempKey << " was deleted."
					"The root contains data " << root->data << endl;
		}
		else
		{
			smallestInRightSubTree = smallestNumPrivate(root->right);
			delNodePrivate(smallestInRightSubTree , root);
			root->data = smallestInRightSubTree;
			cout << "The root key with key " << tempKey 
				 << " was overwritten with key"
				 << root->data << endl; 
		}
	}
	else
	{
		cout << "Tree is empty" << endl;
	}
}


void BST::delMatchNode(node* head, node* match, bool left){
	if(root != NULL){
		node* delPtr;
		int matchKey = match->data;
		int smallestInRightSubTree;

		if(match->left == NULL && match->right == NULL)
		{
			delPtr = match;
			left == true ? head->left = NULL : head->right = NULL;
			delete delPtr;
			cout << "The node contains key " << matchKey << " was deleted."
				 << endl;
		}
		else if(match->left == NULL && match->right != NULL)
		{
			left == true ? head->left = match->right : head->right = match->right;
			match->right = NULL;
			delPtr = match;
			delete delPtr;
			cout << "The node with key " << matchKey << " was deleted." << endl;
		}
		else if(match->left != NULL && match->right == NULL)
		{
			left == true ? head->left = match->left : head->right = match->left;
			match->left = NULL;
			delPtr = match;
			delete delPtr;
			cout << "The node with key " << matchKey << " was deleted." << endl;
		}
		else
		{
			smallestInRightSubTree = smallestNumPrivate(match->right);
			delNodePrivate(smallestInRightSubTree , match);
			match->data = smallestInRightSubTree;
		}
	}
	else{
		cout << "Cant Remove Node Tree is emty. " << endl;
	}
}


int BST::smallestNum()
{
	return smallestNumPrivate(root);
}


int BST::smallestNumPrivate(node* ptr)
{
	if(root != NULL)
	{
		if(ptr->left != NULL)
		{
			return smallestNumPrivate(ptr->left);
		}
		else
		{
			return ptr->data;
		}
	}
	else
	{
		cout << "Tree is empty " << endl ;
		return -200; 
	}
}
