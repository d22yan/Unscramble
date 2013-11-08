#ifndef _PRIME_TO_WORD_H
#define _PRIME_TO_WORD_H

class PrimeToWord {
	private:
		PrimeToWord() {};
		~PrimeToWord();
		static bool instanceFlag;
		static PrimeToWord* single;
	public:
		map_mapm_liststring PrimeDictionary;
		static PrimeToWord* GetInstance();
		void InsertWord(std::string);
		void InsertPrime(MAPM,std::string);
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
	MAPM Prime = 1;
	std::string tolowercase = Utility::ToLowerCase(word);
	std::vector<char> characters(tolowercase.begin(), tolowercase.end());
	for(std::vector<char>::iterator iterator = characters.begin(), end = characters.end(); iterator != end; ++iterator) {
		Prime *= CommonAlphabetInstance->PrimeCommonAlphabetDictionary.at(*iterator);
	}
	return Prime;
}

void PrimeToWord::InsertWord(std::string word) {
	bool valid = true;
	int WordLength = word.length();
	for (std::string::iterator iterator = word.begin(), end = word.end(); iterator != end; ++iterator) {
		if (!isalpha(*iterator)) {
			valid = false;
		}
	}
	if (valid) {
		std::string LowerCased = Utility::ToLowerCase(word);
		MAPM PrimeNumber= WordToPrime(LowerCased);
		InsertPrime(PrimeNumber, LowerCased);
	}
}

void PrimeToWord::InsertPrime(MAPM PrimeNumber, std::string word) {
	if (PrimeDictionary.find(PrimeNumber) == PrimeDictionary.end()) {
		std::list<std::string> NewList;
		NewList.insert(NewList.begin(),word);
		PrimeDictionary.insert(pair_mapm_liststring(WordToPrime(word),NewList));
	}
	else {
		PrimeDictionary.at(PrimeNumber).insert(PrimeDictionary.at(PrimeNumber).begin(),word);
	}
}

#endif