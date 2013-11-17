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
	if ( ConvertToPrimedDictionary ) {
		PrimedDictionary::ConvertToPrimedDictionary();
	}
	if ( ReadDictionary) {
		PrimedDictionary::ReadDictionary();
	}
	if ( ReadPrimedDictionary ) {
		PrimedDictionary::ReadPrimedDictionary();
	}
}

void Unscramble::UnscrambleString(std::string ScrambledWord) {
	if(ScrambledWord.empty()) { return; }
	MAPM Prime;
	std::set<std::string> AllCombinationSet = Utility::GenerateCombination(ScrambledWord);
	map_mapm_setstring Result;
	for (std::set<std::string>::iterator iterator = AllCombinationSet.begin(), end = AllCombinationSet.end(); iterator != end; ++iterator) {
		Prime = PrimedDictionary::WordToPrime(*iterator);
		char PrimeString[MAXIMUM_DIGIT];
		Prime.toIntegerString(PrimeString);
		if (Result.find(Prime) == Result.end() && PrimeToWordInstance->PrimeDictionary.find(Prime) != PrimeToWordInstance->PrimeDictionary.end()) {
			std::set<std::string> MatchedPrimeSet = PrimeToWordInstance->PrimeDictionary.at(Prime);
			Result.insert(pair_mapm_setstring(Prime,MatchedPrimeSet));
		}
	}
	Utility::DisplayDictionary(Result);
}

#endif 