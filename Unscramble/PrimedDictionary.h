#ifndef _PRIMED_DICTIONARY_H
#define _PRIMED_DICTIONARY_H

class PrimedDictionary {
	private:
		PrimedDictionary() {};
		~PrimedDictionary();
		static bool instanceFlag;
		static PrimedDictionary* single;
	public:
		map_mapm_liststring PrimeDictionary;
		static PrimedDictionary* GetInstance();
		static void ConvertToPrimedDictionary();
		static void ReadDictionary();
		static void ReadPrimedDictionary();
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

void PrimedDictionary::ConvertToPrimedDictionary() {
	std::ifstream IStreamFile(DictionaryFileName);
	if(IStreamFile.is_open()) {
		std::string NewDictionaryFileName = PrimedDictionarySuffix + DictionaryFileName;
		std::ofstream OStreamFile(NewDictionaryFileName);
		if (OStreamFile.is_open()) {
			std::string Word;
			int counter = 0;
			while(!IStreamFile.eof()) {
				IStreamFile >> Word;
				if ( Utility::IsValidWord(Word) ) {
					MAPM Prime = single->WordToPrime(Word);
					char PrimeString[MAXIMUM_DIGIT];
					Prime.toIntegerString(PrimeString);
					std::string NewLine(PrimeString);
					NewLine.append(PrimedDictionaryDelimiter + Word);
					OStreamFile << NewLine << std::endl;
					std::cout << counter++ << " " << NewLine << std::endl;
				}
			}
		}
		OStreamFile.close();
	}
	IStreamFile.close();
}

void PrimedDictionary::ReadDictionary() {
	std::ifstream IStreamFile;
	IStreamFile.open(DictionaryFileName);
	if (IStreamFile.is_open()) {
		std::string Line;
		while(!IStreamFile.eof()) {
			IStreamFile >> Line;
			if ( Utility::IsValidWord(Line) ) {
				std::string Word = Utility::ToLowerCase(Line);
				single->InsertWord(Word);
				std::cout << Word << std::endl;
			}
		}
	}
	IStreamFile.close();
}

void PrimedDictionary::ReadPrimedDictionary() {
	std::ifstream IStreamFile;
	IStreamFile.open(PrimedDictionaryFileName);
	if (IStreamFile.is_open()) {
		std::string Line;
		int counter = 0;
		while(!IStreamFile.eof()) {
			std::getline(IStreamFile, Line);
			std::vector<std::string> SplitLine;
			boost::split(SplitLine, Line, boost::is_any_of(" "));
			if (SplitLine.size() == 2) {
				if ( Utility::IsValidWord(SplitLine.at(1)) ) {
					std::string PrimeString = SplitLine.at(0);
					std::string Word = Utility::ToLowerCase(SplitLine.at(1));
					const char* PrimeChars = PrimeString.c_str();
					MAPM Prime = PrimeChars;
					std::cout << counter++ << std::setw(20) << PrimeChars << std::setw(20) << Word << std::endl;
					single->InsertPrimeAndWord(Prime, Word);
				}
			}
		}
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
	char PrimeString[MAXIMUM_DIGIT];
	Prime.toIntegerString(PrimeString);
	if (PrimeDictionary.find(Prime) == PrimeDictionary.end()) {
		std::list<std::string> NewList;
		NewList.insert(NewList.begin(),word);
		PrimeDictionary.insert(pair_mapm_liststring(WordToPrime(word),NewList));
	}
	else {
		PrimeDictionary.at(Prime).insert(PrimeDictionary.at(Prime).begin(),word);
	}
}

#endif