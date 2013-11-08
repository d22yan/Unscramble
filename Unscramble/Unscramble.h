#ifndef _UNSCRAMBLE_H
#define _UNSCRAMBLE_H

class Unscramble {
	private:
		PrimeToWord* PrimeToWordInstance;
		void ReadDictionary();
	public:
		Unscramble();
		void DisplayResult(map_mapm_liststring);
		void UnscrambleString(std::string);
};

Unscramble::Unscramble() {
	m_apm_cpp_precision(MAXIMUM_DIGIT);
	PrimeToWordInstance = PrimeToWord::GetInstance();
	//ReadDictionary();
	PrimeWordList::ConvertToPrimeDictionary("dictionary2.txt");
}

void Unscramble::DisplayResult(map_mapm_liststring Result) {
	for (map_mapm_liststring::iterator iterator = Result.begin(), end = Result.end(); iterator != end; ++iterator) {
		std::list<std::string> WordList = iterator->second;
		for (std::list<std::string>::iterator iterator = WordList.begin(), end = WordList.end(); iterator != end; ++iterator) {
			std::cout << *iterator << std::endl;
		}
	}
}

void Unscramble::UnscrambleString(std::string ScrambledWord) {
	if(ScrambledWord.empty()) { return; }
	MAPM prime;
	std::list<std::string> AllCombinationList = StringCombination::GenerateCombination(ScrambledWord);
	map_mapm_liststring Result;
	for (std::list<std::string>::iterator iterator = AllCombinationList.begin(), end = AllCombinationList.end(); iterator != end; ++iterator) {
		prime = PrimeToWord::WordToPrime(*iterator);
		if (Result.find(prime) == Result.end() && PrimeToWordInstance->PrimeDictionary.find(prime) != PrimeToWordInstance->PrimeDictionary.end()) {
			std::list<std::string> MatchedPrimeList = PrimeToWordInstance->PrimeDictionary.at(prime);
			Result.insert(pair_mapm_liststring(prime,MatchedPrimeList));
		}
	}
	DisplayResult(Result);
}

void Unscramble::ReadDictionary() {
	std::ifstream myReadFile;
	myReadFile.open(DictionaryFileName);
	if (myReadFile.is_open()) {
		std::string output;
		while(!myReadFile.eof()) {
			myReadFile >> output;
			PrimeToWordInstance->InsertWord(output);
		}
	}
	myReadFile.close();
}



#endif 