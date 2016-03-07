/* testing.cpp
 *
 *
 * Produces the same result as the intial portion of String Rotation.cpp
 */

#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>

using namespace std;

const char DELIMS[3] = ",;";

int main(int argc, char *argv[]) {
	ifstream ifilestream;
//	string * str = new string;
	char * token;
//	char * cstr = new char [str->length()+1];		// how does placing this on the outside make sense? str.length() isn't even defined yet?
	string str;
	char cstr[str.length() + 1];
	vector<string> words;

	ifilestream.open(argv[1]);
	while(ifilestream.peek() != EOF) {
		getline(ifilestream, str);

		words.clear();

		strcpy(cstr, str.c_str());			// char * strcpy(char*, const char*); just because it has a return type doesn't mean you have to set it to anything. (besides, return 0; at the end determines
											// that it just returns 0.)
												// char * strtok(char*, const char*); if this is the case, why can it even accept nonpointers? it's not because it's not a pointer...they are. the first element
												// without brackets is essentially a pointer to the first character. think back on arrays. wow.
												// then what about the delim as const char *? a string literal is a const char[ (size includes the '\0')]. the pointer to it would be const char *. but it's not
												// pointing to it. it's right there...? or is it that the pointer simply points to the first element?
		token = strtok(cstr, DELIMS);				// can't just put str->c_str() where cstr is. Doesn't work that way. (this is because strtok actually changes its imput by inserting a null where token would be.)
		while(token != NULL) {					// so if there are two delimiting characters in a row, it can't properly parse into correct tokens.. so it still assumes a fair amount of proper formatting.
			words.push_back(token);
	//		cout << token << '\n';
			token = strtok(NULL, "");			// so the ending "" could be anything?
		}

		cout << *(DELIMS) << " " << *(DELIMS+1) << endl;

		for(int i = 0; i < words.size(); i++) {
			cout << words.at(i) << "            ";
		}


		cout << endl;

		

	}
//	delete str;
//	delete[] cstr;								// how does this make sense? shouldn't these things be on the inside?

	ifilestream.close();

	return 0;
}