// handle insertion of the same word into the primedictionary
// slow construction of the dictionary, possibly avoid the usage of iostream
// refactor read file http://stackoverflow.com/questions/7868936/c-read-file-line-by-line
// generate prime word list
// check input feed contains correct format and requirements (PrimeWordList requires check on input if it is word)

#include <algorithm>
#include <fstream> 
#include <iostream>
#include <list>
#include <map>
#include <sstream>
#include <stdlib.h>
#include <string>
#include <vector>

#include <boost\algorithm\string\split.hpp>
#include <boost\dynamic_bitset\dynamic_bitset.hpp>
#include <M_APM.H> // http://www.tc.umn.edu/~ringx004/mapm-main.html

#define ALPHABET_COUNT 26
#define MAXIMUM_DIGIT 256
const std::string DictionaryFileName = "dictionary2.txt";
typedef std::map<MAPM,std::list<std::string>> map_mapm_liststring;
typedef std::pair<MAPM,std::list<std::string>> pair_mapm_liststring;

#include "Utility.h"
#include "PrimeNumber.h"
#include "CommonAlphabet.h"
#include "StringCombination.h"
#include "PrimeToWord.h"
#include "PrimeWordList.h"
#include "Unscramble.h"

void main(int argc, char** argv) {
	Unscramble test = Unscramble();
	test.UnscrambleString("Acalyptratae");
	std::cin.ignore();
}
