#pragma once
#include "NodeData.h"
class Node {
private:
	static const int ORDER = 4;
	int numItems;
	Node* parent;
	Node** childArray;
	NodeData** itemArray;
public:
	Node();
	void connectChild(int childNum, Node* child);
	Node* disconnectChild(int childNum);
	Node* getChild(int childNum);
	Node* getParent();
	bool isLeaf();
	int getNumItems();
	void setNumItems(int numItems);
	NodeData* getItem(int index);
	NodeData* setItem(int index, NodeData* value);
	bool isFull();
	int insertItem(NodeData* item);
	void insertFront(NodeData* item);
	NodeData* removeItem(); //Largest item
	string displayNode();
	string displayValue(int j);
	void removeNodeValue(int value);
	void removeValue(int value,string side);
	Node* getSibling(int value);
};
