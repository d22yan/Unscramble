#ifndef _UNSCRAMBLE_H
#define _UNSCRAMBLE_H

class Unscramble {
	private:
		PrimeToWord* PrimeToWordInstance;
		void ReadDictionary();
	public:
		Unscramble();
		void UnscrambleString(std::string);
};

Unscramble::Unscramble() {
	m_apm_cpp_precision(MAXIMUM_DIGIT);
	PrimeToWordInstance = PrimeToWord::GetInstance();
	//ReadDictionary();
	//PrimeWordList::PrimedDictionaryConverter("dictionary2.txt");
	PrimeWordList::ReadPrimedDictionary();
}

void Unscramble::UnscrambleString(std::string ScrambledWord) {
	if(ScrambledWord.empty()) { return; }
	MAPM Prime;
	std::list<std::string> AllCombinationList = StringCombination::GenerateCombination(ScrambledWord);
	map_mapm_liststring Result;
	for (std::list<std::string>::iterator iterator = AllCombinationList.begin(), end = AllCombinationList.end(); iterator != end; ++iterator) {
		Prime = PrimeToWord::WordToPrime(*iterator);
		char PrimeString[MAXIMUM_DIGIT];
		Prime.toIntegerString(PrimeString);
		if (Result.find(Prime) == Result.end() && PrimeToWordInstance->PrimeDictionary.find(Prime) != PrimeToWordInstance->PrimeDictionary.end()) {
			std::list<std::string> MatchedPrimeList = PrimeToWordInstance->PrimeDictionary.at(Prime);
			Result.insert(pair_mapm_liststring(Prime,MatchedPrimeList));
		}
	}
	DisplayResult(Result);
	DisplayResult(PrimeToWordInstance->PrimeDictionary);
}

void Unscramble::ReadDictionary() {
	std::ifstream myReadFile;
	myReadFile.open(PrimedDictionaryFileName);
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