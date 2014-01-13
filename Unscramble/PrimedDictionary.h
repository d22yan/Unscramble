#ifndef __PRIMEDDICTIONARY_H_INCLUDED__
#define __PRIMEDDICTIONARY_H_INCLUDED__

#ifndef __MAXIMUMDIGIT__
#define __MAXIMUMDIGIT__ 256
#endif

#include "LetterFrequency.h"
#include "Utility.h"

std::string DefaultDictionaryFileName = "dictionary.txt";
std::string ExecutionPath;

class PrimedDictionary {
	private:
		PrimedDictionary() {};
		~PrimedDictionary();
		static bool instanceFlag;
		static PrimedDictionary* single;
	public:
		std::map<MAPM,std::set<std::string>> PrimeDictionary;
		static PrimedDictionary* GetInstance();
		static void ReadDictionary();
		void InsertWord(std::string);
		void InsertPrimeAndWord(MAPM,std::string);
		static MAPM WordToPrime(std::string);
};

bool PrimedDictionary::instanceFlag = false;
PrimedDictionary* PrimedDictionary::single = NULL;

PrimedDictionary::~PrimedDictionary() {
	delete single;
	instanceFlag = false;
}

PrimedDictionary* PrimedDictionary::GetInstance() {
	if(!instanceFlag) {
		single = new PrimedDictionary();
		instanceFlag = true;
		return single;
	}
	return single;
}

void PrimedDictionary::ReadDictionary() {
	std::ifstream IStreamFile;
	IStreamFile.open(DefaultDictionaryFileName);
	if (IStreamFile.is_open()) {
		std::string Line;
		while(!IStreamFile.eof()) {
			IStreamFile >> Line;
			if(Utility::IsValidWord(Line)) {
				std::string Word = Utility::ToLowerCase(Line);
				single->InsertWord(Word);
				std::cout << Word << std::endl;
			}
		}
	}
	else {
		std::cout << "Unable to find \"" << DefaultDictionaryFileName << "\" in path: " << ExecutionPath << std::endl;
		std::exit(0);
	}
	IStreamFile.close();
}

MAPM PrimedDictionary::WordToPrime(std::string word) {
	LetterFrequency *LetterFrequencyInstance = LetterFrequency::GetInstance();
	MAPM Prime = 1;
	std::string tolowercase = Utility::ToLowerCase(word);
	std::vector<char> characters(tolowercase.begin(), tolowercase.end());
	for(std::vector<char>::iterator iterator = characters.begin(), end = characters.end(); iterator != end; ++iterator) {
		Prime *= LetterFrequencyInstance->LetterPrimeDictionary.at(*iterator);
	}
	return Prime;
}

void PrimedDictionary::InsertWord(std::string word) {
	MAPM PrimeNumber = WordToPrime(word);
	InsertPrimeAndWord(PrimeNumber, word);
}

void PrimedDictionary::InsertPrimeAndWord(MAPM Prime, std::string word) {
	if (PrimeDictionary.find(Prime) == PrimeDictionary.end()) {
		std::set<std::string> NewSet;
		NewSet.insert(word);
		PrimeDictionary.insert(std::pair<MAPM,std::set<std::string>>(WordToPrime(word),NewSet));
	}
	else {
		PrimeDictionary.at(Prime).insert(word);
	}
}

#endif