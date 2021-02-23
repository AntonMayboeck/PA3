#include <iostream>
#include <string>
#include <fstream>
#include <map>

using namespace std;

int main() {
	ifstream os;
	int count = 0;

	os.open("test.txt");
	string hello((istreambuf_iterator<char>(os)),
		(istreambuf_iterator<char>()));
	
	map<char, int> eva;

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
	//cout << hello;
	//cout << count;
	for (const auto& p : eva) {
		cout << p.first << ": " << p.second << endl; // "Karl", "George"
		
	}
}