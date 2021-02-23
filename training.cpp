#include <iostream>
#include <string>
#include <deque>

#include "train.h"

Node::Node(DataClass* data, Node* right, Node* left) {
	this->data = data;
	this->right = right;
	this->left = left;
}

ostream& operator<<(ostream& out, const DataClass* data) {
	if (data != NULL) {
		out << "{ " << data->chara << ": " << data->Number << " }";
	}
	return out;
}


DataClass::DataClass(char chara, string Number) {
	this->chara = chara;
	this->Number = Number;
}

Node::~Node() {
	delete right;
	delete data;
	delete left;
}

friend ostream& operator<<(ostream& out, const Node* node) {
	if (node != NULL) {
		out << node->left;
		out << " " << node->data << " ";
		out << node->right;
	}
	return out;
}


int main() {

	deque <Node*> node_queue;
	
	Node* root = NULL;

	for (int i = 0; i < 12; i++) {
		Node* node = new Node(new DataClass(i, (char)(int)('a' + i)));
		node_queue.push_back(node);
	}

	while (!node_queue.empty()) {
		Node* left = node_queue.front();
		node_queue.pop_front; 
		Node* right = node_queue.front();
		node_queue.pop_front();
	}

	cout << root << endl;
	delete root;

	root = NULL;
	cout << root << endl;


}