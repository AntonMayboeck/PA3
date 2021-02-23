#include <iostream>
#include <string.h>

#include "trees.h"

using namespace std

Node::Node(Dataclass *data,	Node *left, Node *right) {
	this->data = data;
	this->right = right;
	this->left = left;
}


DataClass::DataClass(char character, string BinaryNumber) {
	this->character = character;
	this->BinaryNumber = BinaryNumber;
}


Node::~Node() {
	if (dc != NULL) {
		delete dc;
		dc = NULL;
	}
	if (right != NULL) {
		delete right;
		right = NULL;
	}
	if (left != NULL) {
		delete left;
		left = NULL;
	}
}



void Node::encode() {
	
}

void Node::hasLeaf() {
	
}