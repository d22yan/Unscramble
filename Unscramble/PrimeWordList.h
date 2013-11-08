#ifndef _PRIME_WORDLIST_H
#define _PRIME_WORDLIST_H

class PrimeWordList {
	public:
		static std::string ConvertToPrimeDictionary(std::string);
		static void ReadPrimeDictionary();
};

std::string PrimeWordList::ConvertToPrimeDictionary(std::string input) {
	std::string	DictioanryFileName = input;
	std::string NewDictionaryFileName = "primed" + input;
	std::ifstream IStreamFile(input);
	std::ofstream OStreamFile(NewDictionaryFileName);
	if(IStreamFile.is_open() && OStreamFile.is_open()) {
		std::string Line;
		while(!IStreamFile.eof()) {
			IStreamFile >> Line;
			MAPM Prime = PrimeToWord::WordToPrime(Line);
			char PrimeString[MAXIMUM_DIGIT];
			Prime.toIntegerString(PrimeString);
			std::string NewLine(PrimeString);
			NewLine.append(" " + Line);
			OStreamFile << NewLine << std::endl;
		}
	}
	IStreamFile.close();
	OStreamFile.close();
	return NewDictionaryFileName;
}

void PrimeWordList::ReadPrimeDictionary() {
	std::ifstream IStreamFile;
	IStreamFile.open(DictionaryFileName);
	if (IStreamFile.is_open()) {
		std::string Line;
		while(!IStreamFile.eof()) {
			IStreamFile >> Line;
			std::vector<std::string> SplitLine;
			boost::split(SplitLine, Line, ::isspace);
			if (SplitLine.size() == 2) {
				std::string PrimeString = SplitLine[0];
				std::string Word = SplitLine[1];
				const char* PrimeChars = PrimeString.c_str();
				MAPM Prime = PrimeChars;
				PrimeToWord::GetInstance()->InsertPrime(Prime, Word);
			}
		}
	}
	IStreamFile.close();
}

#endif