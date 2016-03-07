/**************************************** FizzBuzz.cpp ******************************************
 * Overview - https://www.codeeval.com/open_challenges/1/. Provided with a text file via the
 *            command prompt with 3 space delimited numbers per line, the first number will 
 *			  be represented as A, the second as B, and the third number as N. The output
 *			  will be a series of space delimited numbers in numeric order up to N. For every
 *			  number divisible by the number A, replace that number with A. The program also
 *			  does this with numbers divisible by B. In the instance that the number is both
 *			  divisible by A and B, the number is instead replaced by "AB". Assuming multiple
 *			  lines of numbers, the output will also generate multiple lines of output for each
 *			  line of input.
 *
 * Functions -
 *		openFiles(): 
 *			  User inputs the names of the target input file and the nascent output file via 
 *			  command prompt. The files are thereafter opened and streams are set to receive 
 *   		  their contents or to input contents into the file.
 *
 *		get_and_storeABN(): 
 *			  Reads a line from the text file using getline() and reads the line into a string
 *			  stream where the function getNumber() takes over to parse out the individual numbers.
 *			  Ultimately, the function reads the line and stores the numbers into A, B, and N.
 *			  
 *		getNumber():
 *			  Reads the string and parses out the individual numbers using isdigits(). The 
 *			  nascent number is inputted into a string where once the function runs into a 
 *			  non-numeric value, streams the string into an integer variable.
 *		fizzbuzz():
 *			  This is the main function of this program. With the values of A, B, and N stored, 
 * 			  this function produces the pattern mentioned in the overview by first generating a
 *			  string.
 *
 *		processOutput():
 *			  This function streams the contents of the string from fizzbuzz() into the ofstream,
 *			  which places the contents of the string into the output file.
 *
 *		closeFiles():
 *			  This function closes the input and output files.
 */
 
#include <iostream> // standard stuff
#include <fstream> // for the file streams
#include <cctype> // for isdigit()
#include <string> // for the strings
#include <sstream> // for the string streams
//#include <stdlib.h> // for the exit, EXIT_FAILURE

using namespace std;

void openFiles(ifstream &ifile_stream, ofstream &ofile_stream);
void get_and_storeABN(ifstream &ifile_stream, int &A, int &B, int &N);
int getNumber(string &line);
void fizzbuzz(int F, int B, int S, string &o_string);
void processOutput(string &converted_string, ofstream &output);
void closeFiles(ifstream &input, ofstream &output);

int main() {
	//declarations here
	ifstream input_stream;
	ofstream output_stream;
	string output_string, output_filename;
	int A, B, N = 0;
	
	//functions here
	openFiles(input_stream, output_stream);
	
	while(input_stream.good()) {
		if(!output_string.empty())
			output_stream << endl;
		get_and_storeABN(input_stream, A, B, N);
		output_string.clear();
		fizzbuzz(A, B, N, output_string);
		processOutput(output_string, output_stream);
	}
	
	closeFiles(input_stream, output_stream);
	
	// system("pause"); // use this to check error messages.
	
	return 0;
}
	
void openFiles(ifstream &ifile_stream, ofstream &ofile_stream) {
	string ifname, ofname;
	cout << "Please enter the name of the input text file: ";
	getline(cin, ifname);
	if(ifname.find(".txt") == string::npos)
		ifname += ".txt";
	ifile_stream.open(ifname.c_str());
	
	cout << "Please enter the name of the output text file where you would like to store the results: ";
	getline(cin, ofname);
	if(ofname.find(".txt") == string::npos)
		ofname += ".txt";
	ofile_stream.open(ofname.c_str());
}

void get_and_storeABN(ifstream &ifile_stream, int &A, int &B, int &N) {
	string line;
	getline(ifile_stream, line);
	A = getNumber(line);
	B = getNumber(line);
	N = getNumber(line);
//	cout << A << " " << B << " " << N << endl;
}
	
int getNumber(string &line) {
	char ch;
	string string_digit = "";
	int number = 0;
	istringstream stream_for_line(line); //can you do this, or does one have to use stream(variable.s_str())?

	if(stream_for_line.good()) {
		while((ch = stream_for_line.get()) != EOF) {
			line.erase(0,1);
			if((!isdigit(ch)) && (string_digit != "")) { // cannot compare a string to NULL because that value is never taken on by a string.
				istringstream stream_for_int(string_digit); // can you do this? same as above.
				stream_for_int >> number;
				return number; // can you return a stream? YES by using .str(), but we want an integer not a string.
			} else if(isdigit(ch))
					   string_digit += ch;
		}
		istringstream stream_for_int2(string_digit); // initializing the stream with this string i think merely copies the string to the stream. further changes to the stream does nothing i believe.
		stream_for_int2 >> number;
		return number;
	}
	return number;
}
					
void fizzbuzz(int F, int B, int S, string &o_string) {
	if(!((F == 0) || (B == 0) || (S == 0))) { // if A, B, or N are zero, then an error message is returned.
		
		int d = 1;
		for(int n = 1; n < 1000; n++) {
			if((F % n == 0) && (B % n == 0))
				d = n;
		}
		
		for(int i = 0; i < S; i++) {
			if((i + 1) % (F * B / d) == 0)
				if(i == (S-1))
					o_string += "FB";
				else o_string += "FB ";
			else if((i + 1) % F == 0)
					if(i == (S-1))
						o_string += "F";
					else o_string += "F ";
				 else if((i + 1) % B == 0)
						if(i == (S-1))
							o_string += "B";
						else o_string += "B ";
					  else { 
						  ostringstream itoc;
						  if(i == (S-1))
							  itoc << (i+1);
						  else itoc << (i+1) << " ";
						  o_string += itoc.str(); // will this work without converting the int to a char? No.
					  }
		}
	} else { cerr << "Uh oh. One or more of A, B, or N are equal to zero!";
		     o_string = "Uh oh. One or more of A, B, or N are equal to zero!";
	}	
}

void processOutput(string &converted_string, ofstream &output) {
	output << converted_string;
}

void closeFiles(ifstream &input, ofstream &output) {
	input.close();
	output.close();
}
