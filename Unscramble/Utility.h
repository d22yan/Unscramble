#ifndef _UTILITY_H
#define _UTILITY_H
class Utility {
	public:
		static std::string ToLowerCase(std::string);
		static std::string SortCharacters(std::string);
};

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

#endif