/* Beautiful Strings.cpp
 *
 * Facebook Hacker Cup 2013 Hackathon Problem!
 *
 *
 *	BEAUTIFUL STRINGS (20 points)
 *
 *	When John was a little kid he didn't have much to do.  There was no internet, no
 *	Facebook, and no programs to hack on.  So he did the only thing he could... he
 *	evaluated the beauty of strings in a quest to discover the most beautiful string
 *	in the world.
 *
 *	Given a string S, little Johnny defined the beauty of the string as the sum of
 *	the beauty of the letters in it.
 *
 *	The beauty of each letter is an integer between 1 and 26, inclusive, and no two
 *	letters have the same beauty.  Johnny doesn't care about whether letters are
 *	uppercase or lowercase, so that doesn't affect the beauty of a letter.
 *	(Uppercase 'F' is exactly as beautiful as lowercase 'f', for example.)
 *
 *	You're a student writing a report on the youth of this famous hacker.  You found
 *	the string that Johnny considered most beautiful.  What is the maximum possible
 *	beauty of this string?
 *
 *
 *  EXAMPLE INPUT

	    ABbCcc
	    Good luck in the Facebook Hacker Cup this year!
	    Ignore punctuation, please :)
	    Sometimes test cases are hard to make up.
	    So I just go consult Professor Dalves


	EXAMPLE OUTPUT

	    Case #1: 152
	    Case #2: 754
	    Case #3: 491
	    Case #4: 729
	    Case #5: 646
 *
 *
 * TIL: <map>
 *			- element access:
 *					mapvar[k]; 
 *					for v, use iterator.
 *			- manipulation:
 *					mapvar[k] = v;
 *					mapvar.insert(pair<type,type>(k,v));
 *			
 */

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <cctype>

using namespace std;

int main(int argc, char *argv[]) {
	ifstream ifilestream;
	string str;
	map<char, int> freq; 
	map<int, int> value;
	int highest_num, beauty;
	char highest;
	bool firstn = true;

	ifilestream.open(argv[1]);
	while(ifilestream.peek() != EOF) {
		freq.clear();
		value.clear();
	//	f = 0;
		getline(ifilestream, str);
		// use a map to store the frequency of letters
		for(int i = 0; i < str.size(); i++) {
						//frequency.insert(pair<char, int>(str.at(i), f++));	// will this work? Not really, you aren't inserting a specific value, but increments.
			// test for existence of the key-value map first - actually no need for this because the map should auto map to zero right?
			if(isalpha(str.at(i))) // making sure that we're only collecting letters.
				//if(freq[str.at(i)] == freq.end()) {	// doesn't make a difference if this is used.
				//	freq[str.at(i)] = 1;
				//}
				freq[tolower(str.at(i))]++;	// remember this is the char into an int representation.

		}
		// from this point on, you need to get the highest frequency letter and give it the highest value
		// probably get another map for the value ie. map<char, int> freq/value map.
		// find the highest frequency, see what is returned for num -> assignment
		// once you find the higest frequency you need to remove the value so that it isn't found again. if tied, any is fine.
		while(freq.size() != 0) {
			map<char, int>::iterator it;
			highest_num = 0;
			for(it = freq.begin(); it != freq.end(); it++) {
				if(highest_num < it->second) {
					highest_num = it->second;			//**can't forget about this.
					highest = it->first;
				}
			} 
			value[highest] = 26 - value.size() + 1;				//**how is there stuff in here during this declaration? declaring sets aside memory apparently.
			freq.erase(highest);								// erase after because it will change the size.
		}
		beauty = 0;
		for(int j = 0; j < str.size(); j++) {
			if(isalpha(str.at(j)))
				beauty += value[tolower(str.at(j))];
		}
		if(firstn) {
			cout << beauty;
			firstn = false;
		} else cout << endl << beauty;
	}

	ifilestream.close();

	return 0;
}

