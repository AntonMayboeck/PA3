#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <algorithm>

#include "trees.cpp"

using namespace std;
// A Tree node

// Function to allocate a new tree node
// Huffman coding algorithm implementation in C++
int main(int argc, char*argv[]) {
    ifstream os;
    ofstream fout;
	int count = 0;
	map<char, string> dict;
	string encoder;
    string decoder;
	
	char* command = argv[1];
	string openFile = argv[2];
	string fileName = argv[3];
	

	os.open(openFile, ios::in);
	string str((istreambuf_iterator<char>(os)),
		(istreambuf_iterator<char>()));
	os.close();
	str.erase(std::remove(str.begin(), str.end(), '\n'), str.end());
	
	cout << "createHuffmann" << endl;
	buildHuffmanTree(str, dict, encoder, decoder);
    fout.open(fileName, ios::out);
    for(auto pair : dict){
        fout << pair.first << " " << pair.second << "\n";
    }

	cout << "going out of createHuffmann" << endl;

    return 0;
}