// handle insertion of the same word into the primedictionary
// check input feed contains correct format and requirements (PrimeWordList requires check on input if it is word)
// create DisplayColumn method
// std::string char = Line[0], refactor possible out of range bound exception
// throwing exception, incorrect size of commonalphabetvector

// http://stackoverflow.com/questions/1301277/c-boost-whats-the-cause-of-this-warning
#if defined(_MSC_VER) && _MSC_VER >= 1400 
#pragma warning(push) 
#pragma warning(disable:4996) 
#endif 

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

// http://stackoverflow.com/questions/2629421/how-to-use-boost-in-visual-studio-2010
#include <boost\algorithm\string.hpp>
#include <boost\algorithm\string\split.hpp>
#include <boost\dynamic_bitset\dynamic_bitset.hpp>
#include <M_APM.H> // http://www.tc.umn.edu/~ringx004/mapm-main.html

#define ALPHABET_COUNT 26
#define MAXIMUM_DIGIT 256
const std::string PrimedDictionaryDelimiter = " ";
const std::string PrimedDictionarySuffix = "primed";
const std::string PrimedDictionaryFileName = "primeddictionary2.txt";
const std::string LetterFrequencyListFileName = "LetterFrequencyList.txt";
const std::string InvalidLetterFrequencyVectorSizeMessage = "LetterFrequencyVector.size() != Alphabet_Count";
typedef std::map<MAPM,std::list<std::string>> map_mapm_liststring;
typedef std::pair<MAPM,std::list<std::string>> pair_mapm_liststring;

#include "Utility.h"
#include "PrimeNumber.h"
#include "LetterFrequency.h"
#include "StringCombination.h"
#include "PrimedDictionary.h"
#include "Unscramble.h"

void main(int argc, char** argv) {
	Unscramble test = Unscramble();
	test.UnscrambleString("Aaronitice");
	std::cin.ignore();
}

#if defined(_MSC_VER) && _MSC_VER >= 1400 
#pragma warning(pop) 
#endif 