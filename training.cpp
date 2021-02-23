#include <iostream>
#include <string>
#include <deque>

#include "train.h"

using namespace std;

DataClass::DataClass(int number, char letter) {
	this->number = number;
	this->letter = letter;
}

ostream& operator<<(ostream& out, const DataClass* dc) {
	if (dc != NULL) {
		out << "{" << dc->number << ":" << dc->letter << "}";
	}
}
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

Node::Node(DataClass* data, Node* left, Node* right) {
	this->data = data;
	this->left = left;
	this->right = right;
}

Node::~Node() {
	delete data;
	delete left;
	delete right;
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

ostream& operator<<(ostream& out, const Node* node) {

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
	Node* node = NULL;

	for (int i = 0; i < 12; i++) {
		node = new Node(new DataClass(i, (char)(int)('a' + i)));
		node_queue.push_back(node);
	}

	cout << node << endl;


	while (!node_queue.empty()) {
		Node* left = node_queue.front();
		node_queue.pop_front();
		Node* right = node_queue.front();
		node_queue.pop_front();
		node = new Node(NULL, left, right);
		if (!node_queue.empty()) {
			node_queue.push_back(node);
		}
	}

	root = node;

	cout << root << endl;
	delete root;

	root = NULL;
	cout << root << endl;


}