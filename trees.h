#include <iostream>
#include <string.h>
#include <map>

using namespace std;

class DataClass {
public:
	DataClass(char chara, string Numer);
private:
	char chara;
	string Number;
};

class Node {
public:
	Node(DataClass* data = NULL, Node* left = NULL, Node* right = NULL);
	virtual ~Node();
	void encode();
	void decode();
	void hasLeaf();
	void counter(map eva, string hello);


private:
	DataClass* data;
	Node* left;
	Node* right;

};