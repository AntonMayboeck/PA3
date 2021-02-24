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

void Node::decode(Node *node, int &index, string str) {
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
	string str = "";
	cout << "I'm here 1" << endl;


	if (theText == "") {
		cout << "The File is empty!" << endl;
	}

	priority_queue<Node*, vector<Node*>, compare > node_queue;
	cout << "I'm here 2" << endl;

	unordered_map<char, int> eva;
	counter(eva, theText);

	cout << "I'm here 3" << endl;
	for (auto pair : eva) {
		
		node_queue.push(createNewNode(pair.first, pair.second));
	}
	cout << "I'm here 4" << endl;
	while (!node_queue.empty()) {
		cout << "I'm here 44" << endl;
		Node *left = node_queue.top();
		node_queue.pop();
		cout << "I'm here 444" << endl;
		Node* right = node_queue.top();
		node_queue.pop();
		cout << "I'm here 4444" << endl;


		sum = left->Number + right->Number;
		//Node* node = new Node('\0', sum, left, right);
		if (!node_queue.empty()) {
			node_queue.push(createNewNode('\0', sum, left, right));
		}
		cout << "I'm here 44444" << endl;

	}
	while (!node_queue.empty()) {
		cout << node_queue.top << endl;
		node_queue.pop();
	}
	cout << "I'm here 5" << endl;
	//cout << node_queue << endl;
	
	Node* root = node_queue.top();
	cout << "goinf into encoder" << endl;
	//if (*command == 'e') {
	encode(root, str, dict);
		//writeInFile(fileName, dict);
	for (char ch : theText) {
	encoder += dict[ch];
	}
		//writeInFile()
	cout << encoder;
	//}
	/*if (*command == 'd') {

		int index = -1;
		while (index < (int)encoder.size() - 1) {
			decode(root, index, encoder);
		}
	}*/
	cout << "going out of encode" << endl;
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