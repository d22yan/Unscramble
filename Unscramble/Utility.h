#ifndef _UTILITY_H
#define _UTILITY_H

class Utility {
	public:
		static bool IsValidWord(std::string);
		static std::string BinaryMaskString(boost::dynamic_bitset<>, std::vector<char>);
		static std::string CharToString(char);
		static std::string SortCharacters(std::string);
		static std::string ToLowerCase(std::string);
		static std::set<std::string> GenerateCombination(std::string);
		static std::set<std::string> GeneratePermutation(std::string);
		static std::vector<int> GeneratePrimes(int);
		static void DisplayDictionary(map_mapm_setstring);
		static void DisplayList(std::list<std::string>);
		static void DisplaySet(std::set<std::string>);
		static void IncrementBit(boost::dynamic_bitset<> &);
};

bool Utility::IsValidWord(std::string word) {
	if ( word.empty() ) { return false; }
	for (std::string::iterator iterator = word.begin(), end = word.end(); iterator != end; ++iterator) {
		if ( !isalpha(*iterator) ) {
			return false;
		}
	}
	return true;
}

std::string Utility::BinaryMaskString(boost::dynamic_bitset<> binary, std::vector<char> wordvector) {
	std::string result; 
	for ( int i = 0; i < binary.size(); i++ ) {
		if (binary[i] == 1) {
			result.append(Utility::CharToString(wordvector.at(i)));
		}
	}
	return result;
}

std::string Utility::CharToString(char character) {
	std::string OutputString;
	std::stringstream Converter;
	Converter << character;
	Converter >> OutputString;
	return OutputString;
}

std::string Utility::SortCharacters(std::string input) {
	std::string SortedCharacters = input;
	std::sort(input.begin(), input.end());
	return SortedCharacters;
}

std::string Utility::ToLowerCase(std::string input) {
	std::string LoweredCase = input;
	transform(LoweredCase.begin(), LoweredCase.end(), LoweredCase.begin(), ::tolower);
	return LoweredCase;
}

std::vector<int> Utility::GeneratePrimes(int size) {
	std::vector<int> prime(0,0);
	int counter = 3;
	bool flag = false;
	prime.push_back(2);
	size--;
	while( size ) {
		flag = false;
		for( int i = 0 ; i < prime.size() ; i++ ) {
			if ( !(counter%(prime.at(i))) ) {
				flag = true;
				break;
			}
		}
		if ( !flag ) {
			prime.push_back(counter);
			size--;
		}
		counter+=2;
	}
	return prime;
}

std::set<std::string> Utility::GenerateCombination(std::string word) {
	std::set<std::string> CombinationSet;
	int StringLength = word.length();
	std::string SortedString = Utility::SortCharacters(word);
	std::vector<char> CharacterVector;
	for( int i = 0; i < StringLength; i++) {
		CharacterVector.push_back(SortedString[i]);
	}
	boost::dynamic_bitset<> Combination(StringLength);
	MAPM Counter;
	MAPM MaxCombination = pow(2,StringLength);
	for ( Counter = 1; Counter < MaxCombination; Counter++ ) {
		Utility::IncrementBit(Combination);
		CombinationSet.insert(BinaryMaskString(Combination,CharacterVector));
	}
	return CombinationSet;
}

std::set<std::string> Utility::GeneratePermutation(std::string word) {
	std::set<std::string> PermutationSet;
	int StringLength = word.length();
	std::string SortedString = Utility::SortCharacters(word);
	PermutationSet.insert(SortedString);
	while (std::next_permutation(SortedString.begin(),SortedString.end())) {
		PermutationSet.insert(SortedString);
	}
	return PermutationSet;
}

void Utility::DisplayDictionary(map_mapm_setstring dictionary) {
	for (map_mapm_setstring::iterator iterator = dictionary.begin(), end = dictionary.end(); iterator != end; ++iterator) {
		std::set<std::string> WordList = iterator->second;
		for (std::set<std::string>::iterator iterator = WordList.begin(), end = WordList.end(); iterator != end; ++iterator) {
			std::cout << *iterator << std::endl;
		}
	}
}

void Utility::DisplayList(std::list<std::string> list) {
	for (std::list<std::string>::iterator iterator = list.begin(), end = list.end(); iterator != end; ++iterator) {
		std::cout << *iterator << std::endl;
	}
}

void Utility::DisplaySet(std::set<std::string> set) {
	for ( std::set<std::string>::iterator iterator = set.begin(), end = set.end(); iterator != end; ++iterator) {
		std::cout << *iterator << std::endl;
	}
}

void Utility::IncrementBit(boost::dynamic_bitset<> &input){
	for ( int i = 0; i < input.size(); i++ ) {
		if ( input[i] == 0 ) {
			input[i] = 1;
			break;
		}
		input[i] = 0;
	}
}

#endif