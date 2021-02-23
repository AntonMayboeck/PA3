#include <iostream>
#include <string.h>

using namespace std;

class DataClass {
public:
	DataClass(char chara, string Number);

	friend ostream& operator<<(ostream& out, const DataClass* Data);


private:
	char chara;
	string Number;
}

class Node {
public:
	Node(Dataclass* data, Node* left, Node* right);
	virtual ~Node();

	friend ostream& operator<<(ostream& out, const Node* Node);

private:
	DataClass* data;
	Node* right;
	Node* left;
}