#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <algorithm>

#include "trees.h"
#include "trees.cpp"

using namespace std;

int main(int argc, char*argv[]) {
	Node node;
	ifstream os;
	int count = 0;
	unordered_map<char, string> dict;
	char* command = argv[1];
	string openFile = argv[2];
	string fileName = argv[3];
	string encode;

	os.open(openFile, ios::in);
	string str((istreambuf_iterator<char>(os)),
		(istreambuf_iterator<char>()));
	os.close();
	str.erase(std::remove(str.begin(), str.end(), '\n'), str.end());
	
	cout << "createHuffmann" << endl;
	node.createHuffmann(str, fileName, encode, command, dict);
	cout << "going out of createHuffmann" << endl;
	//call counter HERE!
	/*std::ifstream stream(fileName);
	for (auto& kv : dict) {
		stream << kv.first << " " << kv.second << '\n';
		// Add '\n' character  ^^^^
	}
	stream << encode;
	stream.close();*/


	//cout << hello;
	//cout << count;
	//for (const auto& p : eva) {
	//	cout << p.first << ": " << p.second << endl; // "Karl", "George"
	//}


}