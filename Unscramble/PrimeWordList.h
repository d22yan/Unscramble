#ifndef _PRIME_WORDLIST_H
#define _PRIME_WORDLIST_H

class PrimeWordList {
	public:
		static std::string PrimedDictionaryConverter(std::string);
		static void ReadPrimedDictionary();
};

std::string PrimeWordList::PrimedDictionaryConverter(std::string input) {
	std::string	DictioanryFileName = input;
	std::string NewDictionaryFileName = PrimedDictionarySuffix + input;
	std::ifstream IStreamFile(input);
	std::ofstream OStreamFile(NewDictionaryFileName);
	if(IStreamFile.is_open() && OStreamFile.is_open()) {
		std::string Word;
		int counter = 0;
		while(!IStreamFile.eof()) {
			IStreamFile >> Word;
			MAPM Prime = PrimeToWord::WordToPrime(Word);
			char PrimeString[MAXIMUM_DIGIT];
			Prime.toIntegerString(PrimeString);
			std::string NewLine(PrimeString);
			NewLine.append(PrimedDictionaryDelimiter + Word);
			OStreamFile << NewLine << std::endl;
			std::cout << counter++ << " " << NewLine << std::endl;
		}
	}
	IStreamFile.close();
	OStreamFile.close();
	return NewDictionaryFileName;
}

void PrimeWordList::ReadPrimedDictionary() {
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
				std::string PrimeString = SplitLine.at(0);
				std::string Word = Utility::ToLowerCase(SplitLine.at(1));
				const char* PrimeChars = PrimeString.c_str();
				MAPM Prime = PrimeChars;
				std::cout << counter++ << std::setw(20) << PrimeChars << std::setw(20) << Word << std::endl;
				PrimeToWord::GetInstance()->InsertPrime(Prime, Word);
			}
		}
	}
	IStreamFile.close();
}

#endif