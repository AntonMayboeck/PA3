#include <iostream>
#include <deque>
#include <string>
#include <queue>
#include <fstream>

#include "trees.h"
using namespace std;


Node::Node(DataClass* data, Node* left, Node* right) {
	this->data = data;
	this->left = left;
	this->right = right;
}


DataClass::DataClass(char character, string BinaryNumber) {
	this->chara = character;
	this->Number = BinaryNumber;
}

Node::~Node() {
	delete data;
	delete left;
	delete right;
}

// Node::encode() {
// }

Node::counter(map<char, int> eva, string hello) {

	ifstream os;
	int count = 0;

	os.open("test.txt");
	string hello((istreambuf_iterator<char>(os)),
		(istreambuf_iterator<char>()));

	map<char, int> eva;
	//call counter HERE!

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