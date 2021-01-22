#pragma once
#include "Node.h"

class TwoFour {
private: 
	Node* root;
	void recDisplayTree(Node* thisNode, int level, int childNumber);
public:
	 TwoFour();
	 ~TwoFour();
	 void insert(int dValue);
	 void split(Node* thisNode);
	 Node* getNextChild(Node* theNode, int theValue);
	 void displayTree(int i);
	 void inorderdisplay(Node* thisNode, int level, int childNumber);
	 Node* find(int theValue);
	 Node* findvalue(Node* theNode, int theValue);
	 Node* remove(Node* currnode, int theValue);
	 Node* removeLeaf_cases(Node* thisNode, int theValue);
	 Node* balancetree(Node* currnode);
	 Node* getinordernode(Node* thisNode);
};