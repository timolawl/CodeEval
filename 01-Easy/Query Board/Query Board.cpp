/* Query Board.cpp
 *
 *	There is a board (matrix). Every cell of the board contains one integer, which is 0 initially.

	The next operations can be applied to the Query Board:
	SetRow i x: it means that all values in the cells on row "i" have been changed to value "x" after this operation.
	SetCol j x: it means that all values in the cells on column "j" have been changed to value "x" after this operation.
	QueryRow i: it means that you should output the sum of values on row "i".
	QueryCol j: it means that you should output the sum of values on column "j".

	The board's dimensions are 256x256
	"i" and "j" are integers from 0 to 255
	"x" is an integer from 0 to 31
 *
 *	Input Sample:
 *		SetCol 32 20
		SetRow 15 7
		SetRow 16 31
		QueryCol 32
		SetCol 2 14
		QueryRow 10
		SetCol 14 0
		QueryRow 15
		SetRow 10 1
		QueryCol 2
 *
 * TIL: Leave using the heap for when you make classes. Remember, [] returns the address of, so you can use it for calling by reference.
 *		When you search a string using .find(), always set it equal or not equal to string::npos. Else by itself it will give you a wonky result.
 *
 *
 *
 *
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cctype>

using namespace std;

const int MAX_SIZE = 256;

void SetColFcn(int j, int x, int board[][MAX_SIZE]);
void SetRowFcn(int i, int x, int board[][MAX_SIZE]);
void QueryColFcn(int j, int board[][MAX_SIZE], bool &first);
void QueryRowFcn(int i, int board[][MAX_SIZE], bool &first);

int main(int argc, char *argv[]) {

	//declarations
	ifstream ifilestream;
	int board[MAX_SIZE][MAX_SIZE];		
	string function, src, sx;
	int x, rc;
	bool first = true;

	//open file and read command line arguments.
	ifilestream.open(argv[1]);

	//reset board to zeros.
	for(int i = 0; i < MAX_SIZE; i++) {
		for(int j = 0; j < MAX_SIZE; j++) {
			board[i][j] = 0;
		}
	}

	//while the stream still contains content
	while(ifilestream.peek() != EOF) {
		src.clear();
		sx.clear();
		rc = 0, x = 0;
	//	pt = board;	// how do you do pointers for a 2d array?
					// maybe *pt[] to access the second row? but even then does it change it in a 2d array?

		//receive the line of data - function, rowcol, x
		getline(ifilestream, function, ' ');
		if(function.find("Query") != string::npos) {
			getline(ifilestream, src);
		}
		else {
			getline(ifilestream, src, ' ');
			getline(ifilestream, sx);
		}

		//convert the strings for rowcol and x to int.
		istringstream isstream;
		isstream.str(src);
		isstream >> rc;
		if(!sx.empty()) {
			isstream.clear();
			isstream.str(sx);
			isstream >> x;
		}

		//calling the appropriate functions.
		if(function == "SetCol") {
			SetColFcn(rc, x, board);
		} 
		else if(function == "SetRow") {
			SetRowFcn(rc, x, board);
		}
		else if(function == "QueryCol") {
			QueryColFcn(rc, board, first);
		}
		else if(function == "QueryRow") {
			QueryRowFcn(rc, board, first);
		}
	}

	//delete[][] board;				// delete the board and frees the memory.

	ifilestream.close();

	return 0;
}

void SetColFcn(int j, int x, int board[][MAX_SIZE]) {
	for(int a = 0; a < MAX_SIZE; a++) {
		board[a][j] = x;
	}
}

void SetRowFcn(int i, int x, int board[][MAX_SIZE]) {
	for(int a = 0; a < MAX_SIZE; a++) {
		board[i][a] = x;
	}
}

void QueryColFcn(int j, int board[][MAX_SIZE], bool &first) {
	int sum = 0;

	for(int a = 0; a < MAX_SIZE; a++) {
		sum += board[a][j];
	//	cout << board[a][j] << endl;
	}
	if(first) {
		cout << sum;
		first = false;
	} else cout << endl << sum;
}

void QueryRowFcn(int i, int board[][MAX_SIZE], bool &first) {
	int sum = 0;

	for(int a = 0; a < MAX_SIZE; a++) {
		sum += board[i][a];
	}
	if(first) {
		cout << sum;
		first = false;
	} else cout << endl << sum;
}