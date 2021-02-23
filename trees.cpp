#include <iostream>
#include <deque>
#include <string>
#include <queue>
#include <fstream>
#include <unordered_map>

#include "trees.h"
using namespace std;


struct compare
{
	bool operator()(Node *left, Node* right){
		return left->Number > right->Number;
	}
};


Node::Node(char character, int num, Node* left, Node* right) {
	this->left = left;
	this->right = right;
	this->chara = character;
	this->Number = num;
}
bool hasLeaf(Node *root) {
	return root->left == nullptr && root->right == nullptr;
}


Node::~Node() {
	delete left;
	delete right;
}

void encode(Node *root, string str, unordered_map<char, string> &dict) {

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
		encode(root->left, str + '0', dict);
	}
	if (root->right != nullptr) {
		encode(root->right, str + '0', dict);
	}

}

void decode(Node *node, int &index, string str) {
	if (node == nullptr) {
		return;
	}

	if (hasLeaf(node)) {
		cout << node->chara << endl;

	}
	index++;

	if (str[index] == '0') {
		decode(node->left, index, str);
	}
	else {
		decode(node->right, index, str);
	}
}

void counter(unordered_map<char, int> eva, string hello) {
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

void createHuffmann(string theText, string fileName, string encode, char command) {
	int sum = 0;
	string str = "";


	if (theText == "") {
		cout << "The File is empty!" << endl;
	}

	priority_queue<Node*, vector<Node*>, compare > node_queue;


	unordered_map<char, int> eva;
	counter(eva, theText);


	for (auto pair : eva) {
		
		node_queue.push(new Node(pair.first, pair.second));
	}

	while (!node_queue.empty()) {
		
		Node *left = node_queue.top();
		node_queue.pop();
		Node* right = node_queue.top();
		node_queue.pop();
		

		sum = left->Number + right->Number;
		Node* node = new Node('\0', sum, left, right);
		
		if (!node_queue.empty()) {
			node_queue.push(node);
		}

	}

	Node* root = node_queue.top();

	if (command == 'e') {
		ifstream stream(fileName);
		unordered_map<char, string> dict;
		encode(root, str, dict);
		//writeInFile(fileName, dict);
		for (char ch : theText) {
			encode += dict[ch];
		}
		for (auto pair : dict) {
			stream << pair.first << " " << pair.second << '\n';
		}
		//writeInFile()
	}
	if (command == 'd') {

		int index = -1;
		while (index < (int)encode.size() - 1) {
			decode(root, index, encode);
		}
	}
}

/*template <typename T>
void writeInFile(string fileName, T ) {
	ifstream stream(fileName);
	if (decltype(T) == map) {
		for (auto& T : stored) {
			stream << T.first << " " << T.second << '\n';
		}
	}
	if (decltype(string)) {
		stream << T;
	}
	stream.close();
}*/