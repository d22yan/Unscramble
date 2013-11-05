#ifndef _COMMON_ALPHABET_H
#define _COMMON_ALPHABET_H

class CommonAlphabet {
	public:
		static std::vector<char> GenerateLetterFrequency();
		static std::map<char, int> GeneratePrimeToLetterDictionary();
};

std::map<char, int> CommonAlphabet::GeneratePrimeToLetterDictionary() {
	std::map<char, int> PrimeToLetterDictionary;
	std::vector<int> primenumbers = PrimeNumber::GeneratePrimes(NUMBER_OF_LETTERS);
	std::vector<char> letterfrequency = GenerateLetterFrequency();
	for (int i = 0; i < NUMBER_OF_LETTERS; i++) {
		PrimeToLetterDictionary.insert(std::pair<char,int>(letterfrequency.at(i),primenumbers.at(i)));
	}
	return PrimeToLetterDictionary;
}

std::vector<char> CommonAlphabet::GenerateLetterFrequency() {
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

#endif