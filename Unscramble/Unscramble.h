#ifndef __UNSCRAMBLE_H_INCLUDED__
#define __UNSCRAMBLE_H_INCLUDED__

#ifndef __MAXIMUMDIGIT__
#define __MAXIMUMDIGIT__ 256
#endif

#include "PrimedDictionary.h"
#include "Utility.h"

bool ReadDictionary = true;
std::string ResultOutputFileName = "output.txt";

class Unscramble {
	private:
		PrimedDictionary* PrimedDictionaryInstance;
	public:
		Unscramble();
		void UnscrambleString(std::string);
};

Unscramble::Unscramble() {
	m_apm_cpp_precision(__MAXIMUMDIGIT__);
	PrimedDictionaryInstance = PrimedDictionary::GetInstance();
	if (ReadDictionary) {
		PrimedDictionary::ReadDictionary();
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
		char PrimeString[__MAXIMUMDIGIT__];
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