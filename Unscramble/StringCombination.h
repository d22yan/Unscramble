#ifndef _STRING_COMBINATION_H
#define _STRING_COMBINATION_H

class StringCombination {
	public:
		static void ListCombination(std::string);
};

void StringCombination::ListCombination(std::string word) {
	int StringLength = word.length();
	std::list<std::string> list;
	std::string SortedString= Utility::SortCharacters(word);
	std::vector<char> WordVector;
	for( int i = 0; i < StringLength; i++) {
		WordVector.push_back(SortedString[i]);
	}
	boost::dynamic_bitset<> Combination(StringLength);
	MAPM Counter;
	MAPM MaxCombination = pow(StringLength,2);
	for ( Counter = 0; Counter < MaxCombination; Counter++ ) {
		
	}
}

#endif