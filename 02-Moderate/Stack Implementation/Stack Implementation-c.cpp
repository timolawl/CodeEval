/* Stack Implementation.cpp - using classes.
 *
 * Can this be implemented with arrays instead of vectors, using classes? 
 *
 * Can you do new + malloc? and everytime you need a new element, just malloc a new item? I think that's probably the way.
 *
 * TIL: .get() works to retrieve stream data. Use .peek() to check for conditions, and .ignore() to remove the stop points.
 *		erasing vector elements requires iterator notation.
 */

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <cctype>


using namespace std;

class stack {
public:
	stack();
	~stack();
//	void push(int[]);	// accept an array as input, but no one does it this way, it's passed by address. sure, but how do you do this as a declaration?
//	int[] pop();		// return an array...or maybe i can return the pointer to the address of the array?

	void push(int);
	int pop();
	int size() const;
	void clear();
private:
	int n;
	vector<int> integers;
};

stack::stack() {
	// empty since vector has its own destructors
}

stack::~stack() {
	//empty again since vector has its own destructors
}

void stack::push(int number) {
	n = number;
	integers.push_back(n); // copy over the content of numbers to integers.
}

int stack::pop() {
	int temp = 0;

	temp = integers.at(integers.size() - 1);
	if(integers.size() > 1) {
		integers.erase(integers.end() - 2, integers.end());	// apparently you have to use iterator notation to erase elements
	}
	else if(integers.size() == 1) {
		integers.erase(integers.begin(), integers.end());
	}
//	else if(integers.size() == 1) {integers.clear(); return;}
//	else if(integers.empty()) {return;}

	return temp;
}

int stack::size() const {
	return integers.size();
}

void stack::clear() {
	integers.clear();
}

int main(int argc, char *argv[]) {
	ifstream ifilestream;
	string snum, snums;
	stack s;
	char character, dump;
	int num = 0;
	vector<int> input;
	bool first = true, firstn;

	ifilestream.open(argv[1]);
	while(ifilestream.peek() != EOF) {
		input.clear();
		snum.clear();
		s.clear();
		firstn = true;
		while(ifilestream.peek() != '\n' && ifilestream.peek() != EOF) {

			//get a number one at a time, until newline is reached.
			if(!isspace(character = ifilestream.get())) {
				snum += character;
			} 
			else {
				istringstream isstream(snum);
				isstream >> num;
				s.push(num);	// add the numbers into the vector of ints.
				snum.clear();
			}
		}

		//dump the newline char and put in the last number into the stack.
		if(ifilestream.peek() == '\n' || ifilestream.peek() == EOF) {
			if(ifilestream.peek() == '\n') {
				//ifilestream.get();	// where does the character go if you simply just .get() it?
				ifilestream.ignore(1);	// ignore one character, or until the default delim of EOF is reached.
			}
			if(!snum.empty()) {
				istringstream isstream(snum);
				isstream >> num;
				s.push(num);
				snum.clear();
			}
		}

		//if the stack has at least two elements
		if(s.size() > 1) {
			while(s.size() >= 1) {
				//if first sentence
				if(first) {
					//if first number
					if(firstn) {
						cout << s.pop();
						firstn = false;
					}
					else cout << " " << s.pop();
					first = false;
				}
				//not first sentence
				else {
					if(firstn) {
						cout << endl << s.pop();
						firstn = false;
					}
					else cout << " " << s.pop();
				}
			}
		}
		//if stack only has one element.
		else if(s.size() == 1) {
			if(first) {
				cout << s.pop();
				first = false;
			}
			else cout << endl << s.pop();
		}
	}

	ifilestream.close();

	return 0;
}