#ifndef _UTILITY_H
#define _UTILITY_H

class Utility {
	private:
		static void DisplayPermutation_Permutate(int, std::vector<char>, std::vector<char>, int);
	public:
		static bool IsValidWord(std::string);
		static std::string CharToString(char);
		static std::string SortCharacters(std::string);
		static std::string ToLowerCase(std::string);
		static std::string BinaryMaskString(boost::dynamic_bitset<>, std::vector<char>);
		static std::list<std::string> GenerateCombination(std::string);
		static std::vector<int> GeneratePrimes(int);
		static void DisplayDictionary(map_mapm_liststring);
		static void DisplayPermutation(char*);
		static void IncrementBit(boost::dynamic_bitset<> &);
};

void Utility::DisplayPermutation_Permutate(int size ,std::vector<char> input, std::vector<char> output, int level) {
	if (level == size) {
		for ( int i = 0; i < size; i++) {
			std::cout << output.at(i);
		}
		std::cout << std::endl;
	}
	else {
		for( int i = 0; i < size; i++) { 
			if ( input.at(i) != NULL ) {
				char tmp = input.at(i);
				input.at(i) = NULL;
				for( int j = 0; j < size; j++) {
					if ( output.at(j) == NULL ) {
						std::vector<char> new_output = output;
						new_output.at(j) = tmp;
						DisplayPermutation_Permutate(size, input,new_output,level+1);
					}
				}
				break;
			}
		}
	}
}

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

std::string Utility::BinaryMaskString(boost::dynamic_bitset<> binary, std::vector<char> wordvector) {
	std::string result; 
	for ( int i = 0; i < binary.size(); i++ ) {
		if (binary[i] == 1) {
			result.append(Utility::CharToString(wordvector.at(i)));
		}
	}
	return result;
}

std::list<std::string> Utility::GenerateCombination(std::string word) {
	int StringLength = word.length();
	std::list<std::string> CombinationList;
	std::string SortedString= Utility::SortCharacters(word);
	std::vector<char> WordVector;
	for( int i = 0; i < StringLength; i++) {
		WordVector.push_back(SortedString[i]);
	}
	boost::dynamic_bitset<> Combination(StringLength);
	MAPM Counter;
	MAPM MaxCombination = pow(2,StringLength);
	for ( Counter = 1; Counter < MaxCombination; Counter++ ) {
		Utility::IncrementBit(Combination);
		CombinationList.insert(CombinationList.begin(),BinaryMaskString(Combination,WordVector));
	}
	return CombinationList;
}

void Utility::DisplayPermutation(char* input) {
	int input_size = strlen(input);
	std::vector<char> input_vector;
	std::vector<char> output_vector (input_size,NULL);
	for( int i = 0; i < input_size; i++) {
		input_vector.push_back(*input);
		input++;
	}
	DisplayPermutation_Permutate(input_size, input_vector, output_vector, 0);
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