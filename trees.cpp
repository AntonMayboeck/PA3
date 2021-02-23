#include <iostream>
#include <deque>
#include <string>
#include <queue>
#include <fstream>

#include "trees.h"
using namespace std;


struct compare
{
	bool operator()(Node *left, Node* right){
		return left->Number > right->Number;
	}
};


Node::Node(char character = NULL, int num = NULL, Node* left, Node* right) {
	this->left = left;
	this->right = right;
	this->chara = character;
	this->Number = num;
}
Node::hasLeaf(Node *root) {
	return root->left == nullptr && root->right == nullptr;
}


Node::~Node() {
	delete data;
	delete left;
	delete right;
}

Node::encode(Node *root, string str, map<chara, count> &dict) {

	if (root == nullptr) {
		return;
	}

	if (hasLeaf(root)) {
		if (str == "") {
			dict[root->chara] = '1';
		}
		else {
			dict[root->chara] = str;
		}
		
	}

	if (root->left != nullptr) {
		encode(root->left, str + '0', dict)
	}
	if (root->right != nullptr) {
		encode(root->right, str + '0', dict)
	}

}

Node::decode(Node *node, int &index, string str) {
	if (root == nullptr) {
		return;
	}

	if (hasLeaf(root)) {
		cout << node->chara << endl;

	}
	index++;

	if (str[index] == '0') {
		decode(root->left, index, str);
	}
	else {
		decode(root->right, index, str);
	}
}

Node::counter(map<char, int> eva, string hello) {
	for (int i = 0; i < hello.size(); i++) {
		//map<char, int>::iterator it = eva.find(hello[i]);
		if (hello[i] == '\n') {
			continue;
		}
		else if (eva.count(hello[i])) {
			eva[hello[i]]++;
		}
		else {
			eva[hello[i]] = 1;
		}
	}
}

Node::createHuffmann(string theText) {

	if (theText == "") {
		cout << "The File is empty!" << endl;
	}

	priority_queue<Node*, vector<Node*>, compare > queue;


	map<char, int> eva;
	counter(eva, theText);


	while (!node_queue.empty()) {
		left = node_queue.front();
		node_queue.pop_front();
		right = node_queue.front();
		node_queue.pop_front();
		node = new Node(NULL, left, right);
		if (!node_queue.empty()) {
			node_queue.push_back(node);
		}
	}

}