// handle insertion of the same word into the primedictionary
// check input feed contains correct format and requirements (PrimeWordList requires check on input if it is word)
// delimiter
// create DisplayColumn method
// refactor letter frequency feed, read from file instead of hardcoding
// throwing exception, incorrect size of commonalphabetvector

#include <algorithm>
#include <fstream> 
#include <iostream>
#include <iomanip> // setw()
#include <list>
#include <map>
#include <sstream>
#include <stdlib.h>
#include <string>
#include <vector>

#include <boost\algorithm\string.hpp>
#include <boost\algorithm\string\split.hpp>
#include <boost\dynamic_bitset\dynamic_bitset.hpp>
#include <M_APM.H> // http://www.tc.umn.edu/~ringx004/mapm-main.html

#define ALPHABET_COUNT 26
#define MAXIMUM_DIGIT 256
const std::string PrimedDictionaryDelimiter = " ";
const std::string PrimedDictionarySuffix = "primed";
const std::string PrimedDictionaryFileName = "primeddictionary2.txt";
typedef std::map<MAPM,std::list<std::string>> map_mapm_liststring;
typedef std::pair<MAPM,std::list<std::string>> pair_mapm_liststring;

#include "Utility.h"
#include "PrimeNumber.h"
#include "CommonAlphabet.h"
#include "StringCombination.h"
#include "PrimedDictionary.h"
#include "Unscramble.h"

void main(int argc, char** argv) {
	Unscramble test = Unscramble();
	test.UnscrambleString("Aaronitice");
	std::cin.ignore();
}
