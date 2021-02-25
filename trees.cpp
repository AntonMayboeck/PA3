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

	encode(root->left, str + '0', dict);
	encode(root->right, str + '1', dict);

}

void Node::decode(Node *node, int &index, string str) {
	if (node == nullptr) {
		return;
	}

	if (hasLeaf(node)) {
		cout << node->chara;

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

	//counter(eva, theText);
	unordered_map<char, int> freq;
	for (char ch: theText) {
		if (freq[ch] == '\n') {
			continue;
		}
		else {
			freq[ch]++;
		}
    }
	
	for (const auto& p : freq) {
		cout << p.first << ": " << p.second << endl;
	}

	cout << "I'm here 3" << endl;
	for (auto pair : freq) {
		node_queue.push(createNewNode(pair.first, pair.second, nullptr, nullptr));
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
	// while (!node_queue.empty()) {
	// 	cout << node_queue.top() << endl;
	// 	node_queue.pop();
	// }
	cout << "I'm here 5" << endl;
	//cout << node_queue << endl;
	
	Node* root = node_queue.top();
	cout << "going into encoder" << endl;
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
	int index = -1;
	while (index < (int)encoder.size() - 1) {
		decode(root, index, encoder);
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