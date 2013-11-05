#ifndef _UNSCRAMBLE_H
#define _UNSCRAMBLE_H

class Unscramble {
	private:
		map_mapm_liststring PrimeWordDictionary;
		void ReadDictionary();
	public:
		Unscramble();
		void DisplayResult(map_mapm_liststring);
		void InsertPrimeWord(std::string);
		void UnscrambleString(std::string);
		MAPM WordToPrime(std::string);
};

Unscramble::Unscramble() {
	m_apm_cpp_precision(256);
	ReadDictionary();
}

void Unscramble::DisplayResult(map_mapm_liststring Result) {
	for (map_mapm_liststring::iterator iterator = Result.begin(), end = Result.end(); iterator != end; ++iterator) {
		std::list<std::string> WordList = iterator->second;
		for (std::list<std::string>::iterator iterator = WordList.begin(), end = WordList.end(); iterator != end; ++iterator) {
			std::cout << *iterator << std::endl;
		}
	}
}

MAPM Unscramble::WordToPrime(std::string word) {
	CommonAlphabet *CommonAlphabetInstance = CommonAlphabet::GetInstance();
	MAPM prime = 1;
	std::string tolowercase = Utility::ToLowerCase(word);
	std::vector<char> characters(tolowercase.begin(), tolowercase.end());
	for(std::vector<char>::iterator iterator = characters.begin(), end = characters.end(); iterator != end; ++iterator) {
		prime *= CommonAlphabetInstance->PrimeCommonAlphabetDictionary.at(*iterator);
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

void Unscramble::UnscrambleString(std::string ScrambledWord) {
	if(ScrambledWord.empty()) { return; }
	MAPM prime;
	std::list<std::string> AllCombinationList = StringCombination::GenerateCombination(ScrambledWord);
	map_mapm_liststring Result;
	for (std::list<std::string>::iterator iterator = AllCombinationList.begin(), end = AllCombinationList.end(); iterator != end; ++iterator) {
		prime = WordToPrime(*iterator);
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