#ifndef _UNSCRAMBLE_H
#define _UNSCRAMBLE_H

class Unscramble {
	private:
		PrimedDictionary* PrimedDictionaryInstance;
	public:
		Unscramble();
		void UnscrambleString(std::string);
};

Unscramble::Unscramble() {
	m_apm_cpp_precision(MAXIMUM_DIGIT);
	PrimedDictionaryInstance = PrimedDictionary::GetInstance();
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
	if(!Utility::IsValidWord(ScrambledWord)) { return; }
	MAPM Prime;
	std::set<MAPM> SearchedPrimeSet;
	std::set<std::string> ResultSet;
	std::set<std::string> AllCombinationSet = Utility::GenerateCombination(ScrambledWord);
	for (std::set<std::string>::iterator iterator = AllCombinationSet.begin(), end = AllCombinationSet.end(); iterator != end; ++iterator) {
		Prime = PrimedDictionary::WordToPrime(*iterator);
		char PrimeString[MAXIMUM_DIGIT];
		Prime.toIntegerString(PrimeString);
		if (SearchedPrimeSet.find(Prime) == SearchedPrimeSet.end() && PrimedDictionaryInstance->PrimeDictionary.find(Prime) != PrimedDictionaryInstance->PrimeDictionary.end()) {
			std::set<std::string> MatchedPrimeSet = PrimedDictionaryInstance->PrimeDictionary.at(Prime);
			ResultSet.insert(MatchedPrimeSet.begin(), MatchedPrimeSet.end());
			SearchedPrimeSet.insert(Prime);
		}
	}
	Utility::WriteSetToFile("output.txt", ResultSet); 
	Utility::DisplaySet(ResultSet);
}

#endif 