#pragma once
#include "Node.h"

class TwoFour {
private:
	Node* root;
	int size;
	string recDisplayTree(Node* thisNode, int level, int childNumber);
public:
	TwoFour();
	~TwoFour();
	int getSize();
	void insert(int dValue);
	void split(Node* thisNode);
	Node* getNextChild(Node* theNode, int theValue);
	string toString(int = 0); //displayTree(int i)
	string inorderDisplay(Node* thisNode, int level, int childNumber);
	Node* find(int theValue);
	Node* findvalue(Node* theNode, int theValue);
	Node* remove(Node* currnode, int theValue);
	Node* removeLeaf_cases(Node* thisNode, int theValue);
	Node* balancetree(Node* currnode);
	Node* getinordernode(Node* thisNode);
	//This ones are new
	void recMakeEmpty(Node* thisNode, int level, int childNumber);
};