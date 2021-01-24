#pragma once
#include "Node.h"
#include "RuntimeException.h"
class TwoFour {
private:
	Node* root;
	int size;
	string recDpyTree(Node* cursor, int lvl, int chdNbr);//Recursive display tree
public:
	TwoFour();
	~TwoFour();
	void insert(int value);
	void split(Node* node);
	Node* getNextChild(Node* node, int value);
	string toString(int = 0); //displayTree(int i)
	string inOrderDisplay(Node* cursor, int lvl, int chdNbr);
	Node* find(int value);
	Node* findValue(Node* cursor, int value);
	Node* remove(Node* cursor, int value);
	Node* removeLeafCases(Node* node, int value);
	Node* balanceTree(Node* node);
	Node* getInOrdNode(Node* node);
	//This ones are new
	void recMakeEmpty(Node* cursor, int level, int chdNbr);
	bool isEmpty();
	int getSize();
};