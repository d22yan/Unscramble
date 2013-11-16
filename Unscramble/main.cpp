// handle insertion of the same word into the primedictionary
// create DisplayColumn method
// std::string char = Line[0], possible out of range bound exception
// display in lexicographically order

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
// Referencing mapm.lib: Project > Properties > Configuration Options > Linker > Input > Additional Dependencies
#include <M_APM.H> // http://www.tc.umn.edu/~ringx004/mapm-main.html

#define ALPHABET_COUNT 26
#define IOMANIP_SETW 30
#define MAXIMUM_DIGIT 256

const std::string OptionConvertToPrimedDictionary = "-c";
const std::string OptionReadDictionary = "-d";
const std::string OptionReadPrimedDictionary = "-p";

const std::string PrimedDictionaryDelimiter = " ";
const std::string PrimedDictionarySuffix = "Primed";
const std::string LetterFrequencyListFileName = "LetterFrequencyList.txt";
const std::string InvalidLetterFrequencyVectorSizeMessage = "LetterFrequencyVector.size() != Alphabet_Count";

bool ConvertToPrimedDictionary = false;
bool ReadDictionary = false;
bool ReadPrimedDictionary = false;
std::string DictionaryFileName = "Dictionary.txt";
std::string PrimedDictionaryFileName = PrimedDictionarySuffix + DictionaryFileName;

typedef std::map<MAPM,std::list<std::string>> map_mapm_liststring;
typedef std::pair<MAPM,std::list<std::string>> pair_mapm_liststring;

#include "Utility.h"
#include "LetterFrequency.h"
#include "PrimedDictionary.h"
#include "Unscramble.h"

bool ProcessArguments(int, char**);
void SetDictionaryFileName(std::string);

void main(int argc, char** argv) {
	if (ProcessArguments(argc, argv)) {
		Unscramble test = Unscramble();
		test.UnscrambleString("acetose");
	}
}

bool ProcessArguments(int argc, char** argv) {
	if ( argc < 2 ) {
		return false;
	}
	std::string option;
	for(int i = 1; i < argc; i++) {
		option = argv[i];
		if (option == OptionConvertToPrimedDictionary) {
			ConvertToPrimedDictionary = true;
		}
		else if (option == OptionReadDictionary) {
			ReadDictionary = true;
		}
		else if (option == OptionReadPrimedDictionary) {
			ReadPrimedDictionary = true;
		}
		else {
			SetDictionaryFileName(option);
		}
	}
	return true;
}

void SetDictionaryFileName(std::string filename) {
	DictionaryFileName = filename;
	PrimedDictionaryFileName = PrimedDictionarySuffix + DictionaryFileName;
}

#if defined(_MSC_VER) && _MSC_VER >= 1400 
#pragma warning(pop) 
#endif 