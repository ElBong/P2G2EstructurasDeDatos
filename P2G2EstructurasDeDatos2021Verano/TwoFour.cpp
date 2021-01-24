
#include "TwoFour.h"
TwoFour::TwoFour() {
	root = new Node();
	size = 0;
}
bool TwoFour::isEmpty() { return size == 0; }
TwoFour::~TwoFour() {
	//recMakeEmpty(root, 0, 0);
	size = 0;
}
int TwoFour::getSize()
{
	return this->size;
}
void TwoFour::recMakeEmpty(Node* thisNode, int level, int childNumber) {
	if (thisNode) {
		if (thisNode->isLeaf()) delete thisNode;
		int numItems = thisNode->getNumItems();
		Node* nextNode = nullptr;
		for (int j = 0; j < numItems + 1; j++) {
			nextNode = thisNode->getChild(j);
			if (nextNode)
				recDisplayTree(nextNode, level + 1, j);
			else
				return;
		}
	}
}
string TwoFour::recDisplayTree(Node* thisNode, int level, int childNumber)
{
	stringstream s;
	s << "Level = " << level << ". Child = " << childNumber << ": ";
	s << thisNode->displayNode() << "\n";
	// call ourselves for each child of this node
	int numItems = thisNode->getNumItems();
	Node* nextNode = nullptr;
	for (int j = 0; j < numItems + 1; j++) {
		nextNode = thisNode->getChild(j);
		if (nextNode)
			s << recDisplayTree(nextNode, level + 1, j);
		else
			return s.str();
	}
	return s.str();
}

void TwoFour::insert(int dValue)
{
	Node* curNode = root;
	NodeData* tempItem = new NodeData(dValue);

	while (true) {
		if (curNode->isFull()) // if node full,
		{
			split(curNode); // split it
			curNode = curNode->getParent(); // back up
											// search once
			curNode = getNextChild(curNode, dValue);
		} // end if(node is full)

		else if (curNode->isLeaf()) // if node is leaf,
			break; // go insert
		// node is not full, not a leaf; so go to lower level
		else
			curNode = getNextChild(curNode, dValue);
	} // end while

	curNode->insertItem(tempItem); // insert new NodeData
	size++;
	// end insert()
}

void TwoFour::split(Node* thisNode)
{
	// assumes node is full
	NodeData* itemB;
	NodeData* itemC;
	Node* parent;
	Node* child2;
	Node* child3;
	int itemIndex;

	itemC = thisNode->removeItem(); // remove items from
	itemB = thisNode->removeItem(); // this node
	child2 = thisNode->disconnectChild(2); // remove children
	child3 = thisNode->disconnectChild(3); // from this node

	Node* newRight = new Node(); // make new node

	if (thisNode == root) // if this is the root,
	{
		root = new Node(); // make new root
		parent = root; // root is our parent
		root->connectChild(0, thisNode); // connect to parent
	}
	else
		// this node not the root
		parent = thisNode->getParent(); // get parent

	// deal with parent
	itemIndex = parent->insertItem(itemB); // item B to parent
	int n = parent->getNumItems(); // total items?

	for (int j = n - 1; j > itemIndex; j--) // move parent's
	{ // connections
		Node* temp = parent->disconnectChild(j); // one child
		parent->connectChild(j + 1, temp); // to the right
	}
	// connect newRight to parent
	parent->connectChild(itemIndex + 1, newRight);

	// deal with newRight
	newRight->insertItem(itemC); // item C to newRight
	newRight->connectChild(0, child2); // connect to 0 and 1
	newRight->connectChild(1, child3); // on newRight
} // end split()

Node* TwoFour::getNextChild(Node* theNode, int theValue)
{
	// Should be able to do this w/o a loop, since we should know
		// index of correct child already

	int j;
	// assumes node is not empty, not full, not a leaf
	int numItems = theNode->getNumItems();
	for (j = 0; j < numItems; j++) // for each item in node
	{ // are we less?
		if (theValue < theNode->getItem(j)->getData())
			return theNode->getChild(j); // return left child
	} // end for // we're greater, so
	return theNode->getChild(j); // return right child
}

string TwoFour::toString(int i) {
	stringstream s;
	if (!this->isEmpty()) {
		s << "Cantidad de datos en el árbol: " << size << ".\n";
		if (i == 0) s << recDisplayTree(root, 0, 0);
		else s << inorderDisplay(root, 0, 0);
		s << "\n";
	}else
		s << "El árbol se encuentra vacío.\n";
	return s.str();
}

string TwoFour::inorderDisplay(Node* thisNode, int level, int childNumber) {
	stringstream s;
	int numItems = thisNode->getNumItems();
	for (int j = 0; j < numItems + 1; j++) {
		Node* nextNode = thisNode->getChild(j);
		if (nextNode)
			s << inorderDisplay(nextNode, level + 1, j);
		else {
			s << thisNode->displayNode();
			return s.str();
		}
		if (j < thisNode->getNumItems())
			s << thisNode->displayValue(j);
	}
	return s.str();
}

Node* TwoFour::find(int theValue)
{
	return findvalue(root, theValue);
}

Node* TwoFour::findvalue(Node* theNode, int theValue)
{
	// Should be able to do this w/o a loop, since we should know
		// index of correct child already
	Node* l = nullptr;
	// assumes node is not empty, not full, not a leaf
	int numItems = theNode->getNumItems();
	// System->out->println(numItems+"-------"+theNode->getItem(0)->dData);
	for (int j = 0; j < numItems; j++) // for each item in node
	{ // are we less?
		// System->out->println(theNode->getItem(j)->dData);
		if (theValue == theNode->getItem(j)->getData()) {
			l = theNode;
			break;
		}
		else if (theValue < theNode->getItem(j)->getData() && !theNode->isLeaf()) {
			l = findvalue(theNode->getChild(j), theValue); // return left
															// child
			break;
		}
		else if (theValue > theNode->getItem(j)->getData() && !theNode->isLeaf()) {
			l = findvalue(theNode->getChild(j + 1), theValue); // return
																// right
																// child

		}
	} // end for // we're greater, so
	return l;
}

Node* TwoFour::remove(Node* currnode, int theValue){

	if (size == 1) {
		root->makeEmpty();
		size--;
		return nullptr;
	}
	if (currnode == root) {
		if(root->getNumItems() != size)
			throw InvalidOperation("Operación invalida.");
	}
	Node* y = nullptr;
	if (currnode->isLeaf()) {
		if (currnode->getNumItems() > 1) {
			currnode->removeNodeValue(theValue);
			size--;
			return currnode;
		}else{
			y = removeLeaf_cases(currnode, theValue);
			size--;
			return y;
		}
	}else {
		Node* n = getNextChild(currnode, theValue);
		Node* c = getinordernode(n);
		NodeData* d = c->getItem(0);
		int k = d->getData();
		remove(c, d->getData());
		size--;
		Node* found = find(theValue);
		for (int i = 0; i < found->getNumItems(); i++) {
			if (found->getItem(i)->getData() == theValue) {
				found->getItem(i)->setData(k);
			}
		}
		return found;
	}
}

Node* TwoFour::removeLeaf_cases(Node* thisNode, int theValue)
{
	string sibling_side = "l";
	Node* p = thisNode->getParent();
	Node* sibling = thisNode->getSibling(theValue);
	if (sibling == nullptr) {
		sibling_side = "r";
		sibling = p->getChild(1);
	}

	if (sibling->getNumItems() == 1) {
		for (int i = 0; i <= p->getNumItems(); i++) {
			if (p->getChild(i) == sibling && sibling_side == "l") {

				//					System->out->println("Sibling is on left side & Data is "
				//							+ sibling->getItem(0)->dData);

				thisNode->setItem(thisNode->getNumItems() - 1, nullptr);
				thisNode->setNumItems(thisNode->getNumItems() - 1);
				NodeData* d = p->getItem(i);
				sibling->insertItem(d);
				p->disconnectChild(i + 1);
				for (int j = i; j < p->getNumItems(); j++) {
					if (j + 1 < p->getNumItems()) {
						p->setItem(j, p->getItem(j + 1));
						if (j + 2 <= p->getNumItems()) {
							p->connectChild(j + 1, p->disconnectChild(j + 2));
						}
					}
				}
				p->setItem(p->getNumItems() - 1, nullptr);
				p->setNumItems(p->getNumItems() - 1);

				// Check if parent is null
				if (p->getNumItems() == 0) {
					//						System->out
					//								->println("Parent became null; Now Tree is Re-Balancing");
					if (p != root)
						p = balancetree(p);

					else
						root = sibling;

				}

				return p;

			}
			else if (p->getChild(i) == sibling && sibling_side == "r") {

				//					System->out->println("Sibling is on right side & Data is "
				//							+ sibling->getItem(0)->dData);

				thisNode->setItem(thisNode->getNumItems() - 1, nullptr);
				thisNode->setNumItems(thisNode->getNumItems() - 1);
				NodeData* d = p->getItem(i - 1);
				sibling->insertItem(d);
				p->disconnectChild(0);
				p->connectChild(0, p->disconnectChild(1));

				for (int j = i; j < p->getNumItems(); j++) {
					p->setItem(j - 1, p->getItem(j));
					if (j + 1 <= p->getNumItems()) {
						p->connectChild(j, p->disconnectChild(j + 1));
					}
				}
				p->setItem(p->getNumItems() - 1, nullptr);
				p->setNumItems(p->getNumItems() - 1);

				// Check if parent is null
				if (p->getNumItems() == 0) {
					//						System->out
					//								->println("Parent became null; Now Tree is Re-Balancing");
					if (p != root) {
						p = balancetree(p);
					}
					else {
						root = sibling;
					}
				}
				return p;

			}
		}
	}
	else if (sibling->getNumItems() > 1) {
		int f = 0;
		if (sibling_side == "r") {
			f = 0;
		}
		else {
			f = sibling->getNumItems() - 1;
		}

		for (int i = 0; i <= p->getNumItems(); i++) {
			if (p->getChild(i) == sibling && sibling_side == "l") {
				thisNode->getItem(0)->setData(p->getItem(i)->getData());
				p->getItem(i)->setData(sibling->getItem(f)->getData());
				sibling->removeNodeValue(sibling->getItem(f)->getData());
				return p;
			}

			if (p->getChild(i) == sibling && sibling_side == "r") {
				thisNode->getItem(0)->setData(p->getItem(i - 1)->getData());
				p->getItem(i - 1)->setData(sibling->getItem(f)->getData());
				sibling->removeNodeValue(sibling->getItem(f)->getData());
				return p;
			}
		}
	}

	return nullptr;
}

Node* TwoFour::balancetree(Node* currnode)
{
	string sibling_side = "l";
	Node* p = currnode->getParent();
	Node* sibling = currnode->getSibling(-1);
	if (sibling == nullptr) {
		sibling_side = "r";
		sibling = p->getChild(1);
	}

	if (sibling->getNumItems() == 1) {
		for (int i = 0; i <= p->getNumItems(); i++) {
			if (p->getChild(i) == sibling && sibling_side == "l") {
				// merge parent and child and remove parent

//					System->out->println("Sibling is on left side & Data is "
//							+ sibling->getItem(0)->dData);

				NodeData* d = p->getItem(i);
				sibling->insertItem(d);
				// p->connectChild(i, newnode);
				sibling->connectChild(sibling->getNumItems(),
					currnode->disconnectChild(0));
				p->disconnectChild(i + 1);
				for (int j = i; j < p->getNumItems(); j++) {
					if (j + 1 < p->getNumItems()) {
						p->setItem(j, p->getItem(j + 1));
						if (j + 2 <= p->getNumItems()) {
							p->connectChild(j + 1, p->disconnectChild(j + 2));
						}
					}
				}
				p->setItem(p->getNumItems() - 1, nullptr);
				p->setNumItems(p->getNumItems() - 1);

				// Check if parent is null
				if (p->getNumItems() == 0) {
					//						System->out
					//								->println("Parent became null; Now Tree is Re-Balancing");
					if (p != root) {
						p = balancetree(p);
					}
					else {
						root = sibling;
					}
				}
				return p;
			}

			else if (p->getChild(i) == sibling && sibling_side == "r") {

				//					System->out->println("Sibling is on right side & Data is "
				//							+ sibling->getItem(0)->dData);

				NodeData* d = p->getItem(i - 1);
				sibling->insertFront(d);
				sibling->connectChild(0, currnode->disconnectChild(0));
				p->disconnectChild(0);
				p->connectChild(0, p->disconnectChild(1));

				for (int j = i; j < p->getNumItems(); j++) {
					p->setItem(j - 1, p->getItem(j));
					if (j + 1 <= p->getNumItems()) {
						p->connectChild(j, p->disconnectChild(j + 1));
					}
				}
				p->setItem(p->getNumItems() - 1, nullptr);
				p->setNumItems(p->getNumItems() - 1);

				// Check if parent is null
				if (p->getNumItems() == 0) {
					//						System->out
					//								->println("Parent became null; Now Tree is Re-Balancing");
					if (p != root) {
						p = balancetree(p);
					}
					else {
						root = sibling;
					}
				}
				return p;
			}

		}

	}
	else if (sibling->getNumItems() > 1) {
		int f = 0;
		if (sibling_side == "r") {
			f = 0;
		}
		else {
			f = sibling->getNumItems() - 1;
		}
		for (int i = 0; i <= p->getNumItems(); i++) {
			if (p->getChild(i) == sibling && sibling_side == "l") {

				//					System->out->println("Sibling is on left side & Data is "
				//							+ sibling->getItem(sibling->getNumItems() - 1)->dData);
				currnode->setNumItems(currnode->getNumItems() + 1);
				currnode->connectChild(1, currnode->disconnectChild(0));
				currnode->connectChild(0,
					sibling->disconnectChild(sibling->getNumItems()));
				currnode->setItem(0, p->getItem(i));
				//					currnode->getItem(0)->dData = p->getItem(i)->dData;
				p->setItem(i, sibling->getItem(f));
				//					p->getItem(i)->dData = sibling->getItem(f)->dData;
				sibling->setItem(sibling->getNumItems() - 1, nullptr);
				sibling->setNumItems(sibling->getNumItems() - 1);
				return p;
			}

			if (p->getChild(i) == sibling && sibling_side == "r") {

				//					System->out
				//							->println("Sibling is on right side & Data is ---- "
				//									+ sibling->getItem(0)->dData);
				currnode->setNumItems(currnode->getNumItems() + 1);
				currnode->setItem(0, p->getItem(i - 1));
				//					System->out->println("Current node value: "
				//							+ currnode->getItem(0)->dData);
				//					System->out->println("Sibling going to parent: "
				//							+ sibling->getItem(f)->dData);
				p->setItem(i - 1, sibling->getItem(f));
				//					System->out->println("Parent Changed to: "
				//							+ p->getItem(i - 1)->dData);

				currnode->connectChild(1, sibling->disconnectChild(f));
				//					System->out->println("Current node right child value"
				//							+ currnode->getChild(1)->getItem(0)->dData);

				for (int j = 0; j < sibling->getNumItems(); j++) {
					if (j + 1 < sibling->getNumItems()) {
						sibling->setItem(j, sibling->getItem(j + 1));
					}
					sibling->connectChild(j, sibling->disconnectChild(j + 1));
				}
				//					System->out->println("Sibling first value"
				//							+ sibling->getItem(0)->dData);
				sibling->setItem(sibling->getNumItems() - 1, nullptr);
				sibling->setNumItems(sibling->getNumItems() - 1);
				//System->out->println(currnode->getItem(0)->dData);
				return p;
			}
		}
	}
	return nullptr;
}

Node* TwoFour::getinordernode(Node* thisNode){
	Node* c = nullptr;
	if (thisNode->isLeaf())
		c = thisNode;
	else
		c = getinordernode(thisNode->getChild(0));
	return c;
}



