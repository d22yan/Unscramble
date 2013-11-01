#include <algorithm>
#include <fstream> 
#include <iostream>
#include <list>
#include <map>
#include <stdlib.h>
#include <string>
#include <vector>

#include <M_APM.H>
#include <boost\dynamic_bitset\dynamic_bitset.hpp>

#include "Utility.h"
#include "PrimeNumber.h"
#include "StringPermutation.h"
#include "Unscramble.h"
#include "StringCombination.h"

void main(int argc, char** argv) {
	std::cout << "ASD" << std::endl;
	//m_apm_cpp_precision(256);
	Unscramble test = Unscramble();
	test.UnscrambleString("seNSitizinghprey");
	std::cin.ignore();
}
