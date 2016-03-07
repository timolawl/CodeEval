/* Simple Calculator.cpp
 *
 *
 *
 */

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>
#include <cctype>
#include <iomanip>

using namespace std;

string evaluate_parentheses(string expr);
string operate(string expr);

int main(int argc, char *argv[]) {
	ifstream ifs;
	ifs.open(argv[1]);
	
	string expression, s_answer;
	double answer;
	bool first = true;

	
	while(ifs.peek() != EOF) {
		getline(ifs, expression);
		//it has to be a recursive function to do order of evaluation.
		expression = evaluate_parentheses(expression);
		s_answer = operate(expression);

		istringstream iss(s_answer);
		iss >> answer;

	//	cout << fixed;
		
		if(first) {
			first = false;
			cout << answer;
		}
		else cout << endl << answer;
		
	}

	ifs.close();
	
	return 0;
}

string evaluate_parentheses(string expr) {
	int left_parenthesis_position, right_parenthesis_position;
	string inside_expression, answer, entire_expression;
	//search the string for '('. if found, seek the last ')'	// can't do this because if there are two parentheses sets, then this messes up.
	//must find right-most '(' and then pair it with the first ')' found after.
	// once this is evaluated and resubstituted back into the original equation do the same thing.
	// once there are no more parenthesis..evaluate the expression.
	
	//recursively call this function again with the inside of this section.
	left_parenthesis_position = expr.find_last_of('(');
	right_parenthesis_position = expr.find_first_of(')', left_parenthesis_position);


	if(left_parenthesis_position != string::npos && right_parenthesis_position != string::npos) {
		inside_expression = evaluate_parentheses(expr.substr(left_parenthesis_position + 1, right_parenthesis_position - left_parenthesis_position - 1));	
		expr.replace(expr.begin() + left_parenthesis_position, expr.begin() + right_parenthesis_position + 1, inside_expression);
		expr = evaluate_parentheses(expr);	
	//	cout << expr << endl;
	}
	else {
		answer = operate(expr);
		return answer;
	}

	return expr;
}

string operate(string expr) {

	int exponent_counter;
	double answer, number;
	string s_number, s_answer;
	char op;
	vector<double> numbers;
	vector<char> ops;
	string extracted_expression;

	extracted_expression = expr;

	bool level1_considered, level2_considered, level3_considered;

	s_number.clear();
	s_answer.clear();
	numbers.clear();
	ops.clear();

	//place numbers and operators into vector arrays.
	for(int i = 0; i < extracted_expression.size(); i++) {

		//if first item is a minus sign or a digit, add to number.
		if((i == 0 && extracted_expression.at(i) == '-') || isdigit(extracted_expression.at(i)) || extracted_expression.at(i) == '.') {
			s_number += extracted_expression.at(i);
		}
		//if space, ignore
		else if(isspace(extracted_expression.at(i))) {
			if(!s_number.empty()) {
				istringstream iss(s_number);
				iss >> number;
				numbers.push_back(number);
				s_number.clear();
			}
		}
		//if an operator, add to operator section
		else if(extracted_expression.at(i) != '-' || (extracted_expression.at(i) == '-' && !isdigit(extracted_expression.at(i + 1)))) {
			ops.push_back(extracted_expression.at(i));

			if(!s_number.empty()) {
				istringstream iss(s_number);
				iss >> number;
				numbers.push_back(number);
				s_number.clear();
			}
		}
		//it's a unary minus
		else {
			s_number += extracted_expression.at(i);
		}
	}
	if(!s_number.empty()) {
		istringstream iss(s_number);
			iss >> number;
			numbers.push_back(number);
			s_number.clear();
	}


	level1_considered = false;
	level2_considered = false;
	level3_considered = false;

	//apply operations:
	while(!ops.empty()) {
	//	cout << endl << ops.size() << " " << numbers.size() << endl;
/*
		for(int i = 0; i < ops.size(); i++) {
			cout << numbers.at(i) << " " << ops.at(i) << " ";
		}
			cout << numbers.at(numbers.size() - 1) << endl;
*/
		for(int i = 0; i < ops.size(); i++) {
			if(level1_considered && i != 0) {
					i--;
					level1_considered = false;
				}

			if(ops.at(i) == '^') {
				level1_considered = true;
				exponent_counter = numbers.at(i + 1);
				if(exponent_counter > 0) {
					answer = 1;
					while(exponent_counter > 0) {
						answer *= numbers.at(i);
						exponent_counter--;
					}
					numbers.at(i) = answer;
					numbers.erase(numbers.begin() + i + 1);
				}
				else {
					exponent_counter *= -1;

					while(exponent_counter > 0) {
						answer = 1;
						answer *= numbers.at(i);
						exponent_counter--;
					}
					numbers.at(i) = 1 / answer;
					numbers.erase(numbers.begin() + i + 1);
				}
				ops.erase(ops.begin() + i);
			}
		}
		// * and /
		for(int i = 0; i < ops.size(); i++) {
			if(level2_considered && i != 0) {
					i--;
					level2_considered = false;
				}

			if(ops.at(i) == '*') {
				//cout << numbers.at(i) << " " << numbers.at(i + 1) << endl;
				level2_considered = true;
				//answer = numbers.at(i) * numbers.at(i + 1);
				//cout << answer << endl;

		//		numbers.at(i) *= 100000;
		//		cout << numbers.at(i) << endl;
		//		numbers.at(i + 1) *= 100000;
		//		cout << numbers.at(i + 1) << endl;
				numbers.at(i) *= numbers.at(i + 1);
		//		cout << numbers.at(i) << endl;
		//		numbers.at(i) /= 10000000000;
			//	cout << numbers.at(i);
				numbers.erase(numbers.begin() + i + 1);
				ops.erase(ops.begin() + i);

			}	
			else if(ops.at(i) == '/') {
				level2_considered = true;
				numbers.at(i) /= numbers.at(i + 1);
				numbers.erase(numbers.begin() + i + 1);
				ops.erase(ops.begin() + i);
			}

		}
		for(int i = 0; i < ops.size(); i++) {
			if(level3_considered && i != 0) {
					i--;
					level3_considered = false;
				}

			if(ops.at(i) == '+') {
				level3_considered = true;
				numbers.at(i) += numbers.at(i + 1);
				numbers.erase(numbers.begin() + i + 1);
				ops.erase(ops.begin() + i);
			}
			else if(ops.at(i) == '-') {
				level3_considered = true;
				numbers.at(i) -= numbers.at(i + 1);
				numbers.erase(numbers.begin() + i + 1);
				ops.erase(ops.begin() + i);
			}
		}
	}

//	cout << numbers.at(0) << endl;

	answer = floorf(numbers.at(0) * 100000 + 0.5) / 100000;

//	cout << answer << endl;

	ostringstream oss;
	oss << answer;
	s_answer = oss.str();

	return s_answer;
}