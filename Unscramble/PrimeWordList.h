#ifndef _PRIME_WORDLIST_H
#define _PRIME_WORDLIST_H

class PrimeWordList {
	public:
		static void ReadPrimeDictionary();
};

void PrimeWordList::ReadPrimeDictionary() {
	std::ifstream StreamFile;
	StreamFile.open(DictionaryFileName);
	if (StreamFile.is_open()) {
		std::string Line;
		while(!StreamFile.eof()) {
			StreamFile >> Line;
			std::vector<std::string> SplitLine;
			boost::split(SplitLine, Line, ::isspace);
			if (SplitLine.size() == 2) {
				MAPM PrimeNumber = "123456"; // Convert String to MAPM
				std::string Word = SplitLine[1];
				PrimeToWord::GetInstance()->InsertPrime(PrimeNumber, Word);
			}
		}
	}
	StreamFile.close();
}

#endif