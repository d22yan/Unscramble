#ifndef _UNSCRAMBLE_H
#define _UNSCRAMBLE_H
#define NUMBER_OF_LETTERS 26

//todo refactor iteration through vector, possibly usage of foreach loop
const std::string DictionaryFileName = "dictionary2.txt";

class Unscramble {
	private:
		std::map<char, int> LetterFrequencyDictionary;
		std::map<MAPM, std::list<std::string>> PrimeWordDictionary;
		void ReadDictionary();
		std::vector<char> GetLetterFrequency();
		void InitLetterFrequencyDictionary();
	public:
		Unscramble();
		MAPM WordtoPrime(std::string);
		void InsertPrimeWord(std::string);
		void UnscrambleString(std::string);
};

Unscramble::Unscramble() {
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
			PrimeWordDictionary.insert(std::pair<MAPM,std::list<std::string>>(WordtoPrime(tolowercase),NewList));
		}
		else {
			PrimeWordDictionary.at(prime).insert(PrimeWordDictionary.at(prime).begin(),tolowercase);
		}
	}
}

void Unscramble::UnscrambleString(std::string ScrambledWord) {
	if(ScrambledWord.empty()) { return; }
	MAPM prime = WordtoPrime(ScrambledWord);
	if (PrimeWordDictionary.find(prime) != PrimeWordDictionary.end()) {
		std::list<std::string> asd = PrimeWordDictionary.at(prime);
		for (std::list<std::string>::const_iterator iterator = asd.begin(), end = asd.end(); iterator != end; ++iterator) {
			std::cout << *iterator << std::endl;
		}
	}
}

void Unscramble::ReadDictionary() {
	std::ifstream myReadFile;
	myReadFile.open(DictionaryFileName);
	if (myReadFile.is_open()) {
		char output[256];
		while(!myReadFile.eof()) {
			myReadFile >> output;
			InsertPrimeWord(output);
		}
	}
}



#endif 