#include "NodeData.h"
NodeData::NodeData(int data) {
	this->data = data;
}
int NodeData::getData() { return data; }
void NodeData::setData(int data) {
	this->data = data;
}
string NodeData::toString() {
	stringstream s;
	s << data << " ";
	return s.str();
}
