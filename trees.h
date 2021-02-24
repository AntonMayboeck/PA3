#include <iostream>
#include <string.h>
#include <unordered_map>
#include <queue>

#pragma once
using namespace std;

class Node {
public:
	Node(char chara, int Number, Node* left = NULL, Node* right = NULL);
	Node();
	virtual ~Node();
	Node* createNewNode(char ch, int freq, Node* left = NULL, Node* right = NULL);
	void encode(Node*, string, unordered_map<char, string> &);
	void decode(Node*, int&, string);
	bool hasLeaf(Node*);
	void counter(unordered_map<char, int>, string);
	void createHuffmann(string, string, string, char*, unordered_map<char, string>);
	friend ostream& operator << (ostream& os, const priority_queue<Node*, vector<Node*>, compare> m)
	{
		os << m.top << endl;
		return os;
	}
	//void writeInFile(string fileName, template<typename T>);
	int Number;
	char chara;
	Node* left;
	Node* right;

private:


};