/* Prime Palindrome.cpp
 *
 *
 *
 */

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

bool isPalindrome(string number);
string toString(int num);
bool isPrime(int num);

int main () {
	int answer = 0;
	for(int i = 1000; i >= 0; i--) {
		if(isPalindrome(toString(i)))
			if(isPrime(i)) {
				answer = i;
				break;
			}
	}
	cout << answer;
	return 0;
}


bool isPalindrome(string number) {
	int i = 0;
	int j = number.size() - 1;

	while(number[i] == number[j]) {
		if(number.size() % 2 != 0)
			if(&number[i] == &number[(number.size()/2) + 1])
				return true;
		else { if(&number[j] == &number[number.size()/2]) return true; }
		i++, j--;
	}
	return false;
}

string toString(int num) {
	string str = "";
	ostringstream ostream;
	ostream << num;
	str = ostream.str();
	return str;
}

bool isPrime(int num) {
	for(int i = 2; i < num; i++) {
		if(num % i == 0)
			return false;
	}
	return true;
}
