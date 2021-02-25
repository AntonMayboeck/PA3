#include <iostream>
#include <deque>
#include <string>
#include <queue>
#include <fstream>
#include <map>

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
bool Node::hasLeaf(Node *root) {
	return root->left == nullptr && root->right == nullptr;
}

Node::Node(){}

Node::~Node() {
	delete left;
	delete right;
}

Node* Node::createNewNode(char ch, int freq, Node* left, Node* right){
	Node* node = new Node();

	node->chara = ch;
	node->Number= freq;
	node->left = left;
	node->right = right;

	return node;
}

void Node::encode(Node *root, string str, unordered_map<char, string> &dict) {
	if (root == nullptr) {
		return;
	}
	if (hasLeaf(root)) {
		if(str != "\n"){
			dict[root->chara] = (str != "") ? str : "1";
		}
		
	}
	if(root->left != nullptr){
		encode(root->left, str + '1', dict);
	}
	if(root->right != nullptr){
		encode(root->right, str + '0', dict);
	}
}

void Node::decode(Node *node, int &index, string str, string fileName) {
	ofstream f;
	if (node == nullptr) {
		return;
	}
	f.open(fileName, ios::out);
	if (hasLeaf(node)) {
		f << node->chara;

	}
	f.close();
	index++;
	if (str[index] == '0') {
		decode(node->left, index, str, fileName);
	}
	else {
		decode(node->right, index, str, fileName);
	}
}

void Node::counter(unordered_map<char, int> eva, string hello) {
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

void Node::createHuffmann(string theText, string fileName, string encoder, char* command, unordered_map<char, string> dict) {
	int sum = 0;
	ofstream fout;
	string str = "";
	if (theText == "") {
		cout << "The File is empty!" << endl;
	}

	priority_queue<Node*, vector<Node*>, compare > node_queue;

	unordered_map<char, int> eva;
	//counter(eva, theText);
	for (char ch: theText) {
		eva[ch]++;
    }

	for (auto pair : eva) {
		node_queue.push(createNewNode(pair.first, pair.second));
	}

	while (!node_queue.empty()) {
		Node *left = node_queue.top();
		node_queue.pop();
		Node* right = node_queue.top();
		node_queue.pop();

		sum = left->Number + right->Number;
		//Node* node = new Node('\0', sum, left, right);
		if (!node_queue.empty()) {
			node_queue.push(createNewNode('\0', sum, left, right));
		}

	}
	Node* root = node_queue.top();
	fout.open(fileName, ios::out);
	if(*command == 'e'){
		encode(root, str, dict);
		for (char ch : theText) {
		encoder += dict[ch];
		}
		fout << encoder;
		fout.close();
	}
	else{
		int index = -1;
		while (index < (int)encoder.size() - 1) {
		decode(root, index, encoder, fileName);
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