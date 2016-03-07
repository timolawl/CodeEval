/* Valid parenthesis.cpp
 *
 *
 *
 */

#include <iostream>
#include <fstream>

using namespace std;

void verify_parenthesis(string &t, bool &f);

int main(int argc, char *argv[]) {
	ifstream ifilestream;
	string test;
	bool first = true;

	ifilestream.open(argv[1]);
	while(ifilestream.peek() != EOF) {
		getline(ifilestream, test);
		//find the last  {, [, or (. (Find the one with the position furthest right) if nothing left, it is valid.
		//find if the corresponding other side is right next to it. if not, say it's not valid
		//if it is, then delete both elements and repeat the process above.
		//find the first ] } ).
		verify_parenthesis(test, first);

	}

	ifilestream.close();

	return 0;
}

void verify_parenthesis(string &t, bool &f) {
	int apos, bpos, cpos, lowest;
	char marker;

	if(t.empty()) {
		if(f) {
			f = false;
			cout << "True";
		}
		else cout << endl << "True";
		return;
	}
	else {
		apos = 1000;
		bpos = 1000;
		cpos = 1000;
		if(t.find("]") != string::npos) {
			apos = t.find("]");
		}
		if(t.find("}") != string::npos) {
			bpos = t.find("}");
		}
		if(t.find(")") != string::npos) {
			cpos = t.find(")");
		}

		// get lowest position and keep track of the element
		if(apos <= bpos) {
			lowest = apos;
			marker = '[';
		}
		else {
			lowest = bpos;
			marker = '{';
		}
		if(cpos < lowest) {
			lowest = cpos;
			marker = '(';
		}

		//check adjacent elemnt 
		if(lowest != 0 && t.at(lowest - 1) != marker) {
			if(f) {
				f = false;
				cout << "False";
			}
			else cout << endl << "False";
			return;
		}
		else {
			if(lowest == 0) {
				t.erase(lowest);
			}
			else t.erase(lowest - 1, 2);
		}
		verify_parenthesis(t, f);
	}
}