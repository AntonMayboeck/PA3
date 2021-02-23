#include <iostream>
#include <string.h>
#include <unordered_map>
using namespace std;

class Node {
public:
	Node(char chara, int Number, Node* left = NULL, Node* right = NULL);
	virtual ~Node();
	void encode(Node*, string, unordered_map<char, int>);
	void decode(Node*, int, string);
	bool hasLeaf(Node*);
	void counter(unordered_map<char, int>, string);
	void createHuffmann(string, string, char);
	//void writeInFile(string fileName, template<typename T>);
	int Number;
	char chara;
	Node* left;
	Node* right;

private:


};