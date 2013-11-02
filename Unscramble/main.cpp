#include <algorithm>
#include <fstream> 
#include <iostream>
#include <list>
#include <map>
#include <sstream>
#include <stdlib.h>
#include <string>
#include <vector>

// http://www.tc.umn.edu/~ringx004/mapm-main.html
#include <M_APM.H>
#include <boost\dynamic_bitset\dynamic_bitset.hpp>

#include "Utility.h"
#include "PrimeNumber.h"
#include "StringPermutation.h"
#include "Unscramble.h"
#include "StringCombination.h"

void main(int argc, char** argv) {
	Unscramble test = Unscramble();
	test.UnscrambleString("seNSitizinghprey");
	std::list<std::string> CombinationList = StringCombination::GenerateCombination("ewqasd");
	for (std::list<std::string>::const_iterator iterator = CombinationList.begin(), end = CombinationList.end(); iterator != end; ++iterator) {
		std::cout << *iterator << std::endl;
	}
	std::cin.ignore();
}
