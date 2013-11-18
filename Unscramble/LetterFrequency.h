#ifndef _COMMON_ALPHABET_H
#define _COMMON_ALPHABET_H

class LetterFrequency {
	private:
		LetterFrequency();
		~LetterFrequency();
		static bool instanceFlag;
		static LetterFrequency* single;
		static void GenerateLetterPrimeDictionary();
		static std::vector<char> ReadLetterFrequencyList();
	public:
		std::map<char, int> LetterPrimeDictionary;
		static LetterFrequency *GetInstance();
		static std::vector<char> GenerateLetterFrequency();
};

bool LetterFrequency::instanceFlag = false;
LetterFrequency* LetterFrequency::single = NULL;

LetterFrequency::LetterFrequency() {
	ReadLetterFrequencyList();
}

LetterFrequency::~LetterFrequency() {
	delete single;
	instanceFlag = false;
}

LetterFrequency* LetterFrequency::GetInstance() {
    if(!instanceFlag) {
        single = new LetterFrequency();
        instanceFlag = true;
		GenerateLetterPrimeDictionary();
        return single;
    }
    return single;
}

void LetterFrequency::GenerateLetterPrimeDictionary() {
	LetterFrequency *CommonAlphabetInstance = LetterFrequency::GetInstance();
	std::vector<int> PrimeNumbersVector = Utility::GeneratePrimes(ALPHABET_COUNT);
	std::vector<char> LetterFrequencyVector = GenerateLetterFrequency();
	assert(LetterFrequencyVector.size() == ALPHABET_COUNT, ErrorInvalidLetterFrequencyVectorSize);
	for (int i = 0; i < ALPHABET_COUNT; i++) {
		CommonAlphabetInstance->LetterPrimeDictionary.insert(std::pair<char,int>(LetterFrequencyVector.at(i),PrimeNumbersVector.at(i)));
	}
}

std::vector<char> LetterFrequency::GenerateLetterFrequency() {
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

std::vector<char> LetterFrequency::ReadLetterFrequencyList() {
	std::vector<char> LetterFrequencyVector;
	std::ifstream IStreamFile(LetterFrequencyListFileName);
	if(IStreamFile.is_open()) {
		std::string Line;
		while (!IStreamFile.eof()) {
			IStreamFile >> Line;
			char Letter = Line[0];
			if (isalpha(Letter)) {
				LetterFrequencyVector.push_back(Letter);
			}
		}
	}
	IStreamFile.close();
	return LetterFrequencyVector;
}

#endif