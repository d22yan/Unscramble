#ifndef _UTILITY_H
#define _UTILITY_H

class Utility {
	public:
		static std::string CharToString(char);
		static std::string ToLowerCase(std::string);
		static std::string SortCharacters(std::string);
		static void IncrementBit(boost::dynamic_bitset<> &);
};

std::string Utility::CharToString(char character) {
	std::string OutputString;
	std::stringstream Converter;
	Converter << character;
	Converter >> OutputString;
	return OutputString;
}

std::string Utility::ToLowerCase(std::string input) {
	std::string LoweredCase = input;
	transform(LoweredCase.begin(), LoweredCase.end(), LoweredCase.begin(), ::tolower);
	return LoweredCase;
}

std::string Utility::SortCharacters(std::string input){
	std::string SortedCharacters = input;
	std::sort(input.begin(), input.end());
	return SortedCharacters;
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