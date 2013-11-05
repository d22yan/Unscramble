#ifndef _UNSCRAMBLE_H
#define _UNSCRAMBLE_H

class Unscramble {
	private:
		std::map<char, int> CommonAlphabetDictionary;
		map_mapm_liststring PrimeWordDictionary;
		void ReadDictionary();
		void InitCommonAlphabetDictionary();
	public:
		Unscramble();
		void DisplayResult(map_mapm_liststring);
		void InsertPrimeWord(std::string);
		void UnscrambleString(std::string);
		MAPM WordtoPrime(std::string);
};

Unscramble::Unscramble() {
	m_apm_cpp_precision(256);
	InitCommonAlphabetDictionary();
	ReadDictionary();
}

void Unscramble::InitCommonAlphabetDictionary() {
	std::map<char, int> NewAlphabetDictionary = CommonAlphabet::GeneratePrimeToLetterDictionary();
	for ( std::map<char,int>::iterator iterator = NewAlphabetDictionary.begin(), end = NewAlphabetDictionary.end(); iterator != end; ++iterator) {
		CommonAlphabetDictionary.insert(std::pair<char,int>(iterator->first, iterator->second));
	}
}

void Unscramble::DisplayResult(map_mapm_liststring Result) {
	for (map_mapm_liststring::iterator iterator = Result.begin(), end = Result.end(); iterator != end; ++iterator) {
		std::list<std::string> WordList = iterator->second;
		for (std::list<std::string>::iterator iterator = WordList.begin(), end = WordList.end(); iterator != end; ++iterator) {
			std::cout << *iterator << std::endl;
		}
	}
}

MAPM Unscramble::WordtoPrime(std::string word) {
	MAPM prime = 1;
	std::string tolowercase = Utility::ToLowerCase(word);
	std::vector<char> characters(tolowercase.begin(), tolowercase.end());
	for(std::vector<char>::iterator iterator = characters.begin(), end = characters.end(); iterator != end; ++iterator) {
		prime *= CommonAlphabetDictionary.at(*iterator);
	}
	return prime;
}

void Unscramble::InsertPrimeWord(std::string word) {
	bool valid = true;
	int WordLength = word.length();
	for (std::string::iterator iterator = word.begin(), end = word.end(); iterator != end; ++iterator) {
		if (!isalpha(*iterator)) {
			valid = false;
		}
	}
	if (valid) {
		std::string tolowercase = Utility::ToLowerCase(word);
		MAPM prime = WordtoPrime(tolowercase);
		if (PrimeWordDictionary.find(prime) == PrimeWordDictionary.end()) {
			std::list<std::string> NewList;
			NewList.insert(NewList.begin(),tolowercase);
			PrimeWordDictionary.insert(pair_mapm_liststring(WordtoPrime(tolowercase),NewList));
		}
		else {
			PrimeWordDictionary.at(prime).insert(PrimeWordDictionary.at(prime).begin(),tolowercase);
		}
	}
}

void Unscramble::UnscrambleString(std::string ScrambledWord) {
	if(ScrambledWord.empty()) { return; }
	MAPM prime;
	std::list<std::string> AllCombinationList = StringCombination::GenerateCombination(ScrambledWord);
	map_mapm_liststring Result;
	for (std::list<std::string>::iterator iterator = AllCombinationList.begin(), end = AllCombinationList.end(); iterator != end; ++iterator) {
		prime = WordtoPrime(*iterator);
		if (Result.find(prime) == Result.end() && PrimeWordDictionary.find(prime) != PrimeWordDictionary.end()) {
			std::list<std::string> MatchedPrimeList = PrimeWordDictionary.at(prime);
			Result.insert(pair_mapm_liststring(prime,MatchedPrimeList));
		}
	}
	DisplayResult(Result);
}

void Unscramble::ReadDictionary() {
	std::ifstream myReadFile;
	myReadFile.open(DictionaryFileName);
	if (myReadFile.is_open()) {
		char output[256];
		while(!myReadFile.eof()) {
			myReadFile >> output;
			InsertPrimeWord(output);
		}
	}
	myReadFile.close();
}



#endif 