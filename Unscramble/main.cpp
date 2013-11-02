#include <algorithm>
#include <fstream> 
#include <iostream>
#include <list>
#include <map>
#include <sstream>
#include <stdlib.h>
#include <string>
#include <vector>

// todo remove string permutation
// http://www.tc.umn.edu/~ringx004/mapm-main.html
#include <M_APM.H>
#include <boost\dynamic_bitset\dynamic_bitset.hpp>

typedef std::map<MAPM,std::list<std::string>> map_mapm_liststring;
typedef std::pair<MAPM,std::list<std::string>> pair_mapm_liststring;

#include "Utility.h"
#include "PrimeNumber.h"
#include "StringCombination.h"
#include "StringPermutation.h"
#include "Unscramble.h"

void main(int argc, char** argv) {
	Unscramble test = Unscramble();
	test.UnscrambleString("venommanners");
	std::cin.ignore();
}
