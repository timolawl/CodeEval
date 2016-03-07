/* method - strtok.cpp
 *
 *
 * Take in characters from testfile of String Rotation.
 */

#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
	ifstream ifilestream;
	char * token;
	string str;
	char cstr[str.length() + 1];
	vector<string> words;

	ifilestream.open(argv[1]);
	while(ifilestream.peek() != EOF) {
		getline(ifilestream, str);
		words.clear();
		strcpy(cstr, str.c_str());														
		token = strtok(cstr, ",");				
		while(token != NULL) {					
			words.push_back(token);
			token = strtok(NULL, "");	
		}
		for(int i = 0; i < words.size(); i++) {
			cout << words.at(i) << " ";
		}
	}
	ifilestream.close();
	return 0;
}