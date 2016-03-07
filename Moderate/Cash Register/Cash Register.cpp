/* Cash Register.cpp
 *
 * The goal of this challenge is to design a cash register program. You will be given two float numbers. The first is the
 * purchase price (PP) of the item. The second is the cash (CH) given by the customer. Your reigster currently has the 
 * following bills/coins within it:
 *
 * Input sample:
 * 
 *		15.94;16.00
 *		17;16
 *		35;35
 *		45;50
 *
 * Output sample:
 *
 * NICKEL, PENNY
 * ERROR
 * ZERO
 * FIVE
 *
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
//#include <iomanip>

using namespace std;

/*	enum Currency {
		PENNY = .01;
		NICKEL = .05;
		DIME = .10;
		QUARTER = .25;
		HALF_DOLLAR = .50;
		ONE = 1.00;
		TWO = 2.00;
		FIVE = 5.00;
		TEN = 10.00;
		TWENTY = 20.00;
		FIFTY = 50.00;
		ONE_HUNDRED = 100.00;
	};
*/ // enums have to be used with integers.

const float PENNY = .01;
const float NICKEL = .05;
const float DIME = .10;
const float QUARTER = .25;
const float HALF_DOLLAR = .50;
const float ONE = 1.00;
const float TWO = 2.00;
const float FIVE = 5.00;
const float TEN = 10.00;
const float TWENTY = 20.00;
const float FIFTY = 50.00;
const float ONE_HUNDRED = 100.00;

void produceChange(float r, bool &f);

int main(int argc, char *argv[]) {
	ifstream ifilestream;
	string sPP, sCH;
	float PP, CH, remaining = 0.0;
	bool first = true;


	ifilestream.open(argv[1]);
	while(ifilestream.peek() != EOF) {
		getline(ifilestream, sPP, ';');
		getline(ifilestream, sCH);

		//convert to number form.
		istringstream isstream(sPP);
		isstream >> PP;
		isstream.clear();
		isstream.str(sCH);
		isstream >> CH;

		//If amount provided was less than cost
		if(CH < PP) {
			if(first) {
				first = false;
				cout << "ERROR";
			}
			else cout << endl << "ERROR";
		}

		//if amount provided was exact change.
		else if(CH == PP) {
			if(first) {
				first = false;
				cout << "ZERO";
			}
			else cout << endl << "ZERO";
		}
		else {
			remaining = CH - PP;
			produceChange(remaining, first);
		}
	}

	ifilestream.close();

	return 0;
}

void produceChange(float r, bool &f) {
	bool fn = true;
	if(!f) {
			cout << endl;
		}
	while(r - ONE_HUNDRED >= 0) {
		r -= ONE_HUNDRED;
		cout << "ONE HUNDRED";
		f = false;
	}
	if(abs(r-FIFTY) <= FIFTY/10000) r = FIFTY;
	if(r - FIFTY >= 0) {
		r -= FIFTY;
		if(fn) {
			fn = false;
			cout << "FIFTY";
			f = false;
		}
		else cout << ",FIFTY";
	}
	if(abs(r-TWENTY) <= TWENTY/10000) r = TWENTY;
	while(r - TWENTY >= 0) {
		r -= TWENTY;
		if(fn) {
			fn = false;
			cout << "TWENTY";
			f = false;
		}
		else cout << ",TWENTY";
	}
	if(abs(r-TEN) <= TEN/10000) r = TEN;
	if(r - TEN >= 0) {
		r -= TEN;
		if(fn) {
			fn = false;
			cout << "TEN";
			f = false;
		}
		else cout << ",TEN";
	}
	if(abs(r-FIVE) <= FIVE/10000) r = FIVE;
	if(r - FIVE >= 0) {
		r -= FIVE;
		if(fn) {
			fn = false;
			cout << "FIVE";
			f = false;
		}
		else cout << ",FIVE";
	}	
	if(abs(r-TWO) <= TWO/10000) r = TWO;
	while(r - TWO >= 0) {
		r -= TWO;
		if(fn) {
			fn = false;
			cout << "TWO";
			f = false;
		}
		else cout << ",TWO";
	}	
	if(abs(r-ONE) <= ONE/10000) r = ONE;
	if(r - ONE >= 0) {
		r -= ONE;
		if(fn) {
			fn = false;
			cout << "ONE";
			f = false;
		}
		else cout << ",ONE";
	}	
	if(abs(r-HALF_DOLLAR) <= HALF_DOLLAR/10000) r = HALF_DOLLAR;
	if(r - HALF_DOLLAR >= 0) {
		r -= HALF_DOLLAR;
		if(fn) {
			fn = false;
			cout << "HALF DOLLAR";
			f = false;
		}
		else cout << ",HALF DOLLAR";
	}	
	if(abs(r-QUARTER) <= QUARTER/10000) r = QUARTER;
	if(r - QUARTER >= 0) {
		r -= QUARTER;
		if(fn) {
			fn = false;
			cout << "QUARTER";
			f = false;
		}
		else cout << ",QUARTER";
	}	
	if(abs(r-DIME) <= DIME/10000) r = DIME;
	while(r - DIME >= 0) {
		r -= DIME;
		if(fn) {
			fn = false;
			cout << "DIME";
			f = false;
		}
		else cout << ",DIME";
	}	
	if(abs(r-NICKEL) <= NICKEL/10000) r = NICKEL;
	if(r - NICKEL >= 0) {
		r -= NICKEL;
		if(fn) {
			fn = false;
			cout << "NICKEL";
			f = false;
		}
		else cout << ",NICKEL";
	}	
	if(abs(r-PENNY) <= PENNY/10000) r = PENNY;
	while(r - PENNY >= 0) {
		r -= PENNY;
		if(fn) {
			fn = false;
			cout << "PENNY";
			f = false;
		}
	else cout << ",PENNY";
	}	
}