#ifndef _UNSCRAMBLE_H
#define _UNSCRAMBLE_H

class Unscramble {
	private:
		PrimedDictionary* PrimeToWordInstance;
	public:
		Unscramble();
		void UnscrambleString(std::string);
};

Unscramble::Unscramble() {
	m_apm_cpp_precision(MAXIMUM_DIGIT);
	PrimeToWordInstance = PrimedDictionary::GetInstance();
	if ( CONVERT_TO_PRIMED_DICTIONARY ) {
		PrimedDictionary::ConvertToPrimedDictionary();
	}
	if ( READ_PRIMED_DICTIONARY ) {
		PrimedDictionary::ReadPrimedDictionary();
	}
}

void Unscramble::UnscrambleString(std::string ScrambledWord) {
	if(ScrambledWord.empty()) { return; }
	MAPM Prime;
	std::list<std::string> AllCombinationList = Utility::GenerateCombination(ScrambledWord);
	map_mapm_liststring Result;
	for (std::list<std::string>::iterator iterator = AllCombinationList.begin(), end = AllCombinationList.end(); iterator != end; ++iterator) {
		Prime = PrimedDictionary::WordToPrime(*iterator);
		char PrimeString[MAXIMUM_DIGIT];
		Prime.toIntegerString(PrimeString);
		if (Result.find(Prime) == Result.end() && PrimeToWordInstance->PrimeDictionary.find(Prime) != PrimeToWordInstance->PrimeDictionary.end()) {
			std::list<std::string> MatchedPrimeList = PrimeToWordInstance->PrimeDictionary.at(Prime);
			Result.insert(pair_mapm_liststring(Prime,MatchedPrimeList));
		}
	}
	Utility::DisplayDictionary(Result);
}

#endif 