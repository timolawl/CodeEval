/* Swap Case.cpp
 *
 *
 *
 */

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

int main(int argc, char *argv[]) {
	ifstream ifilestream;
	ifilestream.open(argv[1]);
	string original, case_inversed;
	bool first = true;



	while(ifilestream) {
		case_inversed.clear();
		getline(ifilestream, original);

		for(int i = 0; i < original.size(); i++) {
			if(isupper(original.at(i)))
				case_inversed += tolower(original.at(i));
			else if(islower(original.at(i)))
				case_inversed += toupper(original.at(i));
			else case_inversed += original.at(i);
		}

		if(first) {
			cout << case_inversed;
			first = false;
		}
		else cout << endl << case_inversed;
	}

	ifilestream.close();

	return 0;

}