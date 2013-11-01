#ifndef _PRIME_NUMBER_H
#define _pRIME_NUMBER_H
class PrimeNumber { 
	public: 
		static std::vector<int> GeneratePrimes (int);
};

std::vector<int> PrimeNumber::GeneratePrimes(int size) {
	std::vector<int> prime(0,0);
	int counter = 3;
	bool flag = false;
	prime.push_back(2);
	size--;
	while( size ) {
		flag = false;
		for( int i = 0 ; i < prime.size() ; i++ ) {
			if ( !(counter%(prime.at(i))) ) {
				flag = true;
				break;
			}
		}
		if ( !flag ) {
			prime.push_back(counter);
			size--;
		}
		counter+=2;
	}
	return prime;
}

#endif