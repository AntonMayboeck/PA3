#include <iostream>
#include <string>
#include <fstream>
#include <map>

#include "trees.h"

using namespace std;

int main() {
	ifstream os;
	int count = 0;

	os.open("test.txt");
	string hello((istreambuf_iterator<char>(os)),
		(istreambuf_iterator<char>()));

	//call counter HERE!

	//cout << hello;
	//cout << count;
	//for (const auto& p : eva) {
	//	cout << p.first << ": " << p.second << endl; // "Karl", "George"
	//}


}