#ifndef _UNSCRAMBLE_H
#define _UNSCRAMBLE_H
#define NUMBER_OF_LETTERS 26

//todo slow construction of the dictionary, possibly avoid the usage of iostream
//todo const_iterator or iterator?
//todo refactor iteration through vector, possibly usage of foreach loop
const std::string DictionaryFileName = "dictionary2.txt";

class Unscramble {
	private:
		std::map<char, int> LetterFrequencyDictionary;
		map_mapm_liststring PrimeWordDictionary;
		void ReadDictionary();
		std::vector<char> GetLetterFrequency();
		void InitLetterFrequencyDictionary();
	public:
		Unscramble();
		void DisplayResult(map_mapm_liststring);
		void InsertPrimeWord(std::string);
		void UnscrambleString(std::string);
		MAPM WordtoPrime(std::string);
};

Unscramble::Unscramble() {
	m_apm_cpp_precision(256);
	InitLetterFrequencyDictionary();
	ReadDictionary();
}

std::vector<char> Unscramble::GetLetterFrequency() {
	std::vector<char> myvector;
	myvector.push_back('e');
	myvector.push_back('t');
	myvector.push_back('a');
	myvector.push_back('o');
	myvector.push_back('i');
	myvector.push_back('n');
	myvector.push_back('s');
	myvector.push_back('h');
	myvector.push_back('r');
	myvector.push_back('d');
	myvector.push_back('l');
	myvector.push_back('c');
	myvector.push_back('u');
	myvector.push_back('m');
	myvector.push_back('w');
	myvector.push_back('f');
	myvector.push_back('g');
	myvector.push_back('y');
	myvector.push_back('p');
	myvector.push_back('b');
	myvector.push_back('v');
	myvector.push_back('k');
	myvector.push_back('j');
	myvector.push_back('x');
	myvector.push_back('q');
	myvector.push_back('z');
	return myvector;
}

void Unscramble::InitLetterFrequencyDictionary(){
	std::vector<int> primenumbers = PrimeNumber::GeneratePrimes(NUMBER_OF_LETTERS);
	std::vector<char> letterfrequency = GetLetterFrequency();
	for (int i = 0; i < NUMBER_OF_LETTERS; i++) {
		LetterFrequencyDictionary.insert(std::pair<char,int>(letterfrequency.at(i),primenumbers.at(i)));
	}
}

void Unscramble::DisplayResult(map_mapm_liststring Result) {
	for (map_mapm_liststring::const_iterator iterator = Result.begin(), end = Result.end(); iterator != end; ++iterator) {
		std::list<std::string> WordList = iterator->second;
		for (std::list<std::string>::iterator iterator = WordList.begin(), end = WordList.end(); iterator != end; ++iterator) {
			std::cout << *iterator << std::endl;
		}
	}
}

MAPM Unscramble::WordtoPrime(std::string word) {
	MAPM prime = 1;
	std::string tolowercase = Utility::ToLowerCase(word);
	std::vector<char> characters(tolowercase.begin(), tolowercase.end());
	for(int i = 0; i < characters.size(); i++) {
		prime *= LetterFrequencyDictionary.at(characters.at(i));
	}
	return prime;
}

void Unscramble::InsertPrimeWord(std::string word) {
	bool valid = true;
	int WordLength = word.length();
	for(int i = 0; i < WordLength; i++) {
		if (!isalpha(word[i])) {
			valid = false;
		}
	}
	if (valid) {
		std::string tolowercase = Utility::ToLowerCase(word);
		MAPM prime = WordtoPrime(tolowercase);
		if (PrimeWordDictionary.find(prime) == PrimeWordDictionary.end()) {
			std::list<std::string> NewList;
			NewList.insert(NewList.begin(),tolowercase);
			PrimeWordDictionary.insert(pair_mapm_liststring(WordtoPrime(tolowercase),NewList));
		}
		else {
			PrimeWordDictionary.at(prime).insert(PrimeWordDictionary.at(prime).begin(),tolowercase);
		}
	}
}

void Unscramble::UnscrambleString(std::string ScrambledWord) {
	if(ScrambledWord.empty()) { return; }
	MAPM prime;
	std::list<std::string> AllCombinationList = StringCombination::GenerateCombination(ScrambledWord);
	map_mapm_liststring Result;
	for (std::list<std::string>::const_iterator iterator = AllCombinationList.begin(), end = AllCombinationList.end(); iterator != end; ++iterator) {
		prime = WordtoPrime(*iterator);
		if (Result.find(prime) == Result.end() && PrimeWordDictionary.find(prime) != PrimeWordDictionary.end()) {
			std::list<std::string> MatchedPrimeList = PrimeWordDictionary.at(prime);
			Result.insert(pair_mapm_liststring(prime,MatchedPrimeList));
		}
	}
	DisplayResult(Result);
}

void Unscramble::ReadDictionary() {
	std::ifstream myReadFile;
	myReadFile.open(DictionaryFileName);
	if (myReadFile.is_open()) {
		int counter = 0;
		char output[256];
		while(!myReadFile.eof()) {
			myReadFile >> output;
			InsertPrimeWord(output);
			std::cout << counter++ << " " << output << std::endl;
		}
	}
}



#endif 