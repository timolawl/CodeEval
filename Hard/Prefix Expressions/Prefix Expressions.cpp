/* Prefix Expressions.cpp
 *
 * queue - push/pop/front/back/size/empty
 * stack - push/pop/top/size/empty
 */

#include <iostream>
#include <fstream>
#include <stack> //LIFO
#include <queue> //FIFO
#include <sstream>

using namespace std;

int main(int argc, char *argv[]) {
	ifstream ifilestream;
	string expression, snum;
	stack<char> operators;
	queue<int> numbers;
	int num, num2, result;
	char op;
	istringstream isstream;
	bool first = true;

	ifilestream.open(argv[1]);
	while(ifilestream.peek() != EOF) {
		getline(ifilestream, expression);

		snum.clear();

		while(!isdigit(expression.at(0))) {
			if(!isspace(expression.at(0))) {
				operators.push(expression.at(0));
			}
			expression.erase(0, 1);
		}
		for(int i = 0; i < expression.size(); i++) {
			if(isdigit(expression.at(i))) {
				snum += expression.at(i);
			}
			else if(!snum.empty()) {
				isstream.clear();
				isstream.str(snum);
				isstream >> num;
				numbers.push(num);
				snum.clear();
			}
		}
		if(!snum.empty()) {
			isstream.clear();
			isstream.str(snum);
			isstream >> num;
			numbers.push(num);
			snum.clear();
		}

		result = numbers.front();
		numbers.pop();

		while(!numbers.empty()) {
			num2 = numbers.front();
		//	cout << numbers.front() << endl;
			numbers.pop();

			op = operators.top();
			operators.pop();
			if(op == '*') {
				result *= num2;
			}
			else if(op == '+') {
				result += num2;
			}
			else if(op == '/') {
				result /= num2;
			}
		}

		if(first) {
			first = false;
			cout << result;
		}
		else cout << endl << result;

	}

	ifilestream.close();

	return 0;
}