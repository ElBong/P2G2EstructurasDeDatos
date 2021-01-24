#include "Node.h"
Node::Node() {
	numItems = 0;
	parent = nullptr;
	childArray = new Node * [ORDER];
	for (int i = 0; i < ORDER; i++)
		childArray[i] = nullptr;
	itemArray = new NodeData * [ORDER - 1];
	for (int i = 0; i < ORDER - 1; i++)
		itemArray[i] = nullptr;
}
void Node::connectChild(int childNum, Node* child) {
	childArray[childNum] = child;
	if (child)
		child->parent = this;
}
Node* Node::disconnectChild(int childNum) {
	Node* tempNode = childArray[childNum];
	childArray[childNum] = nullptr;
	return tempNode;
}
Node* Node::getChild(int childNum) {
	return childArray[childNum];
}
Node* Node::getParent() {
	return parent;
}
bool Node::isLeaf() {
	return (childArray[0] == nullptr) ? true : false;
}
int Node::getNumItems() {
	return numItems;
}
void Node::setNumItems(int numItems) {
	this->numItems = numItems;
}
NodeData* Node::getItem(int index) {
	return itemArray[index];
}
NodeData* Node::setItem(int index, NodeData* value) {
	itemArray[index] = value;
	return itemArray[index];
}
bool Node::isFull() {
	return (numItems == ORDER - 1) ? true : false;
}
int Node::insertItem(NodeData* item) {
	// assumes node is not full
	numItems++; // will add new item
	int newKey = item->getData(); // key of new item

	// Should start this for loop at numItems-1, rather than ORDER -2

	for (int j = ORDER - 2; j >= 0; j--) // start on right,
	{ // examine items
		if (itemArray[j] == nullptr) // if item null,
			continue; // go left one cell
		else // not null,
		{ // get its key
			int itsKey = itemArray[j]->getData();
			if (newKey < itsKey) // if it's bigger
				itemArray[j + 1] = itemArray[j]; // shift it right
			else {
				itemArray[j + 1] = item; // insert new item
				return j + 1; // return index to
			} // new item
		} // end else (not null)
	} // end for // shifted all items,
	itemArray[0] = item; // insert new item
	return 0;
}
void Node::insertFront(NodeData* item) {

	int newKey = item->getData(); // key of new item
	numItems++;
	for (int j = numItems - 1; j > 0; j--) {
		itemArray[j] = itemArray[j - 1];
		connectChild(j + 1, disconnectChild(j));
	}
	connectChild(1, disconnectChild(0));
	itemArray[0] = item;
	connectChild(0, nullptr);
}
NodeData** Node::getItmArr() {
	return itemArray;
}
NodeData* Node::removeItem() { //Largest item
	NodeData* temp = itemArray[numItems - 1]; // save item
	itemArray[numItems - 1] = nullptr; // disconnect it
	numItems--; // one less item
	return temp; // return item
}
string Node::displayNode() {
	stringstream s;
	for (int j = 0; j < numItems; j++)
		s << itemArray[j]->toString();
	return s.str();
}
string Node::displayValue(int j) {
	stringstream s;
	s << itemArray[j]->toString();
	return s.str();
}
void Node::removeNodeValue(int value) {
	// Only valid for leafs
	int flag = -1;
	// just delete the value and decrease node size
	for (int i = 0; i < numItems; i++) {
		if (value == itemArray[i]->getData()) {
			flag = i;
		}
		if (flag != -1 && i + 1 < numItems) {
			itemArray[i]->setData(itemArray[i + 1]->getData());
		}
	}
	//delete itemArray[numItems - 1];
	itemArray[numItems - 1] = nullptr; // disconnect it
	numItems--; // one less item
}
void Node::removeValue(int value, string side) {
	// Only valid for leafs
	int flag = -1;
	// just delete the value and decrease node size
	for (int i = 0; i < numItems; i++) {
		if (value == itemArray[i]->getData()) {
			flag = i;
		}
		if (flag != -1 && i + 1 < numItems) {
			itemArray[i]->setData(itemArray[i + 1]->getData());
		}
	}
	//delete itemArray[numItems - 1];
	itemArray[numItems - 1] = nullptr; // disconnect it
	numItems--; // one less item
}
Node* Node::getSibling(int value) {
	// get the sibling
	Node* x = nullptr;
	Node* p = getParent();
	if (numItems != 0) {
		for (int i = 0; i <= p->numItems; i++) {
			if (p->childArray[i]->itemArray[0]->getData() < value) {
				// System.out.println(p.childArray[i].numItems);
				// System.out.println(p.childArray[i].itemArray[0].dData);
				x = p->childArray[i];
			}
		}
	}
	else if (numItems == 0) {
		for (int i = 0; i <= p->numItems; i++) {
			if (p->childArray[i]->itemArray[0] == nullptr) {
				// System.out.println(p.childArray[i].numItems);
				// System.out.println(p.childArray[i].itemArray[0].dData);
				if (i != 0) {
					x = p->childArray[i - 1];
				}
			}
		}
	}
	return x;
}
Node::~Node() {
	for (int i = 0; i < ORDER - 1; i++)
		if (itemArray[i])
			delete itemArray[i];
	for (int i = 0; i < ORDER; i++)
		if (childArray[i])
			delete childArray[i];
	delete[] childArray,delete[] itemArray;
}
