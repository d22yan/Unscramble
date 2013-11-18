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
	std::set<std::string> AllCombinationSet = Utility::GenerateCombination(ScrambledWord);
	map_mapm_setstring ResultDictionary;
	std::set<std::string> ResultSet;
	for (std::set<std::string>::iterator iterator = AllCombinationSet.begin(), end = AllCombinationSet.end(); iterator != end; ++iterator) {
		Prime = PrimedDictionary::WordToPrime(*iterator);
		char PrimeString[MAXIMUM_DIGIT];
		Prime.toIntegerString(PrimeString);
		if (ResultDictionary.find(Prime) == ResultDictionary.end() && PrimedDictionaryInstance->PrimeDictionary.find(Prime) != PrimedDictionaryInstance->PrimeDictionary.end()) {
			std::set<std::string> MatchedPrimeSet = PrimedDictionaryInstance->PrimeDictionary.at(Prime);
			ResultSet.insert(MatchedPrimeSet.begin(), MatchedPrimeSet.end());
			ResultDictionary.insert(pair_mapm_setstring(Prime,MatchedPrimeSet));
		}
	}
	//Utility::WriteSetToFile("output.txt", ResultSet); LNK2019 issue...
	Utility::DisplayDictionary(ResultDictionary);
}

#endif 