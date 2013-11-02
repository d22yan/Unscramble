#ifndef _STRING_COMBINATION_H
#define _STRING_COMBINATION_H

class StringCombination {
	public:
		static std::string BinaryToString(boost::dynamic_bitset<>, std::vector<char>);
		static std::list<std::string> GenerateCombination(std::string);
};

std::string StringCombination::BinaryToString(boost::dynamic_bitset<> binary, std::vector<char> wordvector) {
	std::string result = ""; // TODO refactor string initialization of empty string
	for ( int i = 0; i < binary.size(); i++ ) {
		if (binary[i] == 1) {
			result.append(Utility::CharToString(wordvector.at(i)));
		}
	}
	return result;
}

std::list<std::string> StringCombination::GenerateCombination(std::string word) {
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
		CombinationList.insert(CombinationList.begin(),BinaryToString(Combination,WordVector));
	}
	return CombinationList;
}

#endif