#ifndef _PRIME_WORDLIST_H
#define _PRIME_WORDLIST_H

class PrimeWordList {
	public:
		static void ConvertToPrimeDictionary(std::string);
		static void ReadPrimeDictionary();
};

void PrimeWordList::ConvertToPrimeDictionary(std::string input) {
	std::string	DictioanryFileName = input;
	std::fstream IOStreamFile(input);
	if(IOStreamFile.is_open()) {
		std::string Line;
		while(!IOStreamFile.eof()) {
			IOStreamFile >> Line;
		}
	}
	IOStreamFile.close();
}

void PrimeWordList::ReadPrimeDictionary() {
	std::ifstream ReadStreamFile;
	ReadStreamFile.open(DictionaryFileName);
	if (ReadStreamFile.is_open()) {
		std::string Line;
		while(!ReadStreamFile.eof()) {
			ReadStreamFile >> Line;
			std::vector<std::string> SplitLine;
			boost::split(SplitLine, Line, ::isspace);
			if (SplitLine.size() == 2) {
				std::string PrimeString = SplitLine[0];
				std::string Word = SplitLine[1];
				const char* PrimeChars = PrimeString.c_str();
				MAPM PrimeNumber = PrimeChars;
				PrimeToWord::GetInstance()->InsertPrime(PrimeNumber, Word);
			}
		}
	}
	ReadStreamFile.close();
}

#endif