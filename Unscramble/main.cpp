//todo slow construction of the dictionary, possibly avoid the usage of iostream

#include <algorithm>
#include <fstream> 
#include <iostream>
#include <list>
#include <map>
#include <sstream>
#include <stdlib.h>
#include <string>
#include <vector>

#include <boost\dynamic_bitset\dynamic_bitset.hpp>
#include <M_APM.H> // http://www.tc.umn.edu/~ringx004/mapm-main.html

#define NUMBER_OF_LETTERS 26
const std::string DictionaryFileName = "dictionary2.txt";
typedef std::map<MAPM,std::list<std::string>> map_mapm_liststring;
typedef std::pair<MAPM,std::list<std::string>> pair_mapm_liststring;

#include "Utility.h"
#include "PrimeNumber.h"
#include "StringCombination.h"
#include "Unscramble.h"

void main(int argc, char** argv) {
	Unscramble test = Unscramble();
	test.UnscrambleString("venommanners");
	std::cin.ignore();
}
