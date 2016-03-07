/* Sum of Primes.cpp
 *
 *
 *
 *
 */

#include <iostream>

using namespace std;

const int MAX_PRIMES = 1000;

bool isPrime(int num);

int main() {
	
	int primes = 0;
	int number = 2;
	long int sum_primes = 0;

	while(primes < MAX_PRIMES) {
		
			if(isPrime(number)) {
				sum_primes += number;
				primes++;
			}
		number++;
	}

	cout << sum_primes;

	return 0;
}

bool isPrime(int num) {
	for(int i = 2; i < num; i++) {
		if(num % i == 0)
			return false;
	}
	return true;
}
