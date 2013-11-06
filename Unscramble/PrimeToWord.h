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
		void InsertPrimeWord(std::string);
		static MAPM WordToPrime(std::string);
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

MAPM PrimeToWord::WordToPrime(std::string word) {
	CommonAlphabet *CommonAlphabetInstance = CommonAlphabet::GetInstance();
	MAPM prime = 1;
	std::string tolowercase = Utility::ToLowerCase(word);
	std::vector<char> characters(tolowercase.begin(), tolowercase.end());
	for(std::vector<char>::iterator iterator = characters.begin(), end = characters.end(); iterator != end; ++iterator) {
		prime *= CommonAlphabetInstance->PrimeCommonAlphabetDictionary.at(*iterator);
	}
	return prime;
}

void PrimeToWord::InsertPrimeWord(std::string word) {
	bool valid = true;
	int WordLength = word.length();
	for (std::string::iterator iterator = word.begin(), end = word.end(); iterator != end; ++iterator) {
		if (!isalpha(*iterator)) {
			valid = false;
		}
	}
	if (valid) {
		std::string tolowercase = Utility::ToLowerCase(word);
		MAPM prime = WordToPrime(tolowercase);
		if (PrimeWordDictionary.find(prime) == PrimeWordDictionary.end()) {
			std::list<std::string> NewList;
			NewList.insert(NewList.begin(),tolowercase);
			PrimeWordDictionary.insert(pair_mapm_liststring(WordToPrime(tolowercase),NewList));
		}
		else {
			PrimeWordDictionary.at(prime).insert(PrimeWordDictionary.at(prime).begin(),tolowercase);
		}
	}
}

#endif