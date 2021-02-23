#include <iostream>
#include <string.h>

using namespace std;

class DataClass {
public:
	DataClass(char character, string BinaryNumer);
private:
	char charachter;
	string BinaryNumber;
};

class Node {
public:
	Node(DataClass* data = NULL, Node* left = NULL, Node* right = NULL);
	virtual ~Node();
	void encode();
	void decode();
	void hasLeaf();


private:
	DataClass dc;
	Node *left;
	Node* right;

};