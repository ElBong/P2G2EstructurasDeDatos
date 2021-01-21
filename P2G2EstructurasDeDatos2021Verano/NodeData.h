#pragma once
#include "Libraries.h"
class NodeData {
private:
	int data;
public:
	NodeData(int data);
	int getData();
	void setData(int darta);
	string toString();
};
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