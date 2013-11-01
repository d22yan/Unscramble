#ifndef _STRING_COMBINATION_H
#define _STRING_COMBINATION_H

class StringCombination {
	public:
		static std::list<std::string> ListCombination(std::string);
};

std::list<std::string> StringCombination::ListCombination(std::string word) {
	std::list<std::string> list;
	std::string sortedstring;
	int StringLength = word.length();
	std::vector<char> WordVector;
	for( int i = 0; i < StringLength; i++) {
		WordVector.push_back(word[i]);
	}
	//todo compile time const expression

	boost::dynamic_bitset<> x(3);
	return list;
}

#endif