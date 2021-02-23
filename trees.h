#include <iostream>
#include <string.h>
#include <map>
using namespace std;

class Node {
public:
	Node(char chara, int Number, Node* left = NULL, Node* right = NULL);
	virtual ~Node();
	void encode(Node* node, string str, map<char, int> &dict);
	void decode(Node* node, int& index, string str);
	void hasLeaf(Node *root);
	void counter(map<char, int> eva, string hello);


private:
	char chara;
	int Number;
	Node *left;
	Node* right;

};