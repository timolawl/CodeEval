/* Rightmost Char.cpp
 *
 *
 *
 */
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {
	ifstream ifilestream;
	string fstr;
	char t;
	bool first = true;


	ifilestream.open(argv[1]);
	while(ifilestream.peek() != EOF) {
		getline(ifilestream, fstr);
		t = fstr.at(fstr.size()-1);
		for(int i = fstr.size() - 3; i >= 0; i--) {
			if(fstr.at(i) == t) {
				if(first) {
					cout << i;
					first = false;
					break;
				} else {
					cout << endl << i;
					break;
				}
			} else if(i == 0) {
						if(first) {
							cout << "-1";
							first = false;
						} else cout << endl << "-1"; 
			}
		}
	}
	ifilestream.close();
	
	return 0;
}