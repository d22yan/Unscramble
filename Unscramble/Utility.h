#ifndef _UTILITY_H
#define _UTILITY_H

class Utility {
	public:
		static bool IsValidWord(std::string);
		static std::string CharToString(char);
		static std::string SortCharacters(std::string);
		static std::string ToLowerCase(std::string);
		static std::vector<int> GeneratePrimes(int);
		static void DisplayDictionary(map_mapm_liststring);
		static void IncrementBit(boost::dynamic_bitset<> &);
};

std::string Utility::CharToString(char character) {
	std::string OutputString;
	std::stringstream Converter;
	Converter << character;
	Converter >> OutputString;
	return OutputString;
}

bool Utility::IsValidWord(std::string word) {
	if ( word.empty() ) { return false; }
	for (std::string::iterator iterator = word.begin(), end = word.end(); iterator != end; ++iterator) {
		if ( !isalpha(*iterator) ) {
			return false;
		}
	}
	return true;
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

void Utility::DisplayDictionary(map_mapm_liststring dictionary) {
	for (map_mapm_liststring::iterator iterator = dictionary.begin(), end = dictionary.end(); iterator != end; ++iterator) {
		std::list<std::string> WordList = iterator->second;
		for (std::list<std::string>::iterator iterator = WordList.begin(), end = WordList.end(); iterator != end; ++iterator) {
			std::cout << *iterator << std::endl;
		}
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