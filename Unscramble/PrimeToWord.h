#ifndef _PRIME_TO_WORD_H
#define _PRIME_TO_WORD_H

class PrimeToWord {
	private:
		PrimeToWord() {};
		~PrimeToWord();
		static bool instanceFlag;
		static PrimeToWord* single;
	public:
		map_mapm_liststring PrimeWordDictionary;
		static PrimeToWord* GetInstance();
};

bool PrimeToWord::instanceFlag = false;
PrimeToWord* PrimeToWord::single = NULL;

PrimeToWord::~PrimeToWord() {
	delete single;
	instanceFlag = false;
}

PrimeToWord* PrimeToWord::GetInstance() {
	if(!instanceFlag) {
		single = new PrimeToWord();
		instanceFlag = false;
		return single;
	}
	return single;
}

#endif