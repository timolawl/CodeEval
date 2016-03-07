/* URL Comparison.cpp
 *
 * TIL: string::replace(position, number of characters, replace-with)
 *		string::find(item of interest, starting position.)
 *
 *
 */

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main(int argc, char *argv[]) {
	ifstream ifilestream;
	string url1, url2, shex, shex_char;
	int hex_num, position;
	char hex_char;
	bool first = true, condition;
	istringstream isstream;

	ifilestream.open(argv[1]);
	while(ifilestream.peek() != EOF) {
		condition = false;
		getline(ifilestream, url1, ';');
		getline(ifilestream, url2);

		//replace all hex into dec ascii char form, and remove all port values.
		//unsigned found = url1.find(":80");
		while(url1.find(":80") != string::npos) {
			url1.erase(url1.find(":80"), 3);
		}

		while(url1.find(":") != string::npos) {
			url1.erase(url1.find(":"), 1);
		}
		//found = url2.find(":80");

		while(url2.find(":80") != string::npos) {
			url2.erase(url2.find(":80"), 3);		
		}
		
		while(url2.find(":") != string::npos) {
			url2.erase(url2.find(":"), 1);		
		}

		shex.clear();
		position = 0;
		while(url1.find("%", position) != string::npos && position < url1.size()) {
			unsigned found = url1.find("%");
			//shex += url1.at(found);
			shex += url1.at(found+1);
			shex += toupper(url1.at(found+2));
			if(shex.at(0) >= '0' && shex.at(0) <= '7' && shex.at(1) >= 48) {
				isstream.clear();
				isstream.str(shex);
				isstream >> hex >> hex_num;
				hex_char = hex_num;
				shex_char = hex_char;
				url1.replace(found, 3, shex_char);	
			}
			else position = found + 3;
		}
		shex.clear();
		//found = url2.find("%");
		position = 0;
		while(url2.find("%", position) != string::npos && position < url2.size()) {
			unsigned found = url2.find("%");
			//shex += url2.at(found);
			shex += url2.at(found+1);
			shex += toupper(url2.at(found+2));
			if(shex.at(0) >= '0' && shex.at(0) <= '7' && shex.at(1) >= 48) {
				isstream.clear();
				isstream.str(shex);
				isstream >> hex >> hex_num;
				hex_char = hex_num;
				shex_char = hex_char;
				url2.replace(found, 3, shex_char); // hex_char has to be a string not a character
			}
			else position = found + 3;
		}
		//cout << "-----" << url1 << " " << url2 << endl;
		//now compare strings.
		//compare string sizes
		if(url1.size() != url2.size()) {
			if(first) {
				first = false;
				cout << "False";
				condition = true;
			}
			else {
				cout << endl << "False";
				condition = true;
			}
		}

		//compare individual characters
		else {
			for(int i = 0; i < url1.size(); i++) {
				if(tolower(url1.at(i)) != tolower(url2.at(i))) {
					if(first) {
						first = false;
						cout << "False";
						condition = true;
					}
					else {
						cout << endl << "False";
						condition = true;
					}
					break;
				}
			}
		}
		if(!condition) {
			if(first) {
				first = false;
				cout << "True";
			}
			else cout << endl << "True";
		}

	}

	ifilestream.close();

	return 0;

}