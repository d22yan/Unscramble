// displaying the dictionary during read decreases performance
// error handling

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
#include <set>
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
#define MAXIMUM_DIGIT 64

const std::string CommandHelp =
	"Usage: Unscramble [File]\n"
	"Unscramble randomized letters into all possible words found in [FILE].\n"
	"Inputs:\n"
	"\t[a-zA-Z]+\treturn all possible words\n"
	"\t:q\t\tquit";

const std::string OptionCommandHelp = "-h";
const std::string UserAccept = "y";
const std::string UserDecline = "n";

const std::string ErrorInvalidLetterFrequencyVectorSize = "LetterFrequencyVector.size() != Alphabet_Count";

bool ReadDictionary = true;
std::string ExecutionPath;
std::string DictionaryFileName = "dictionary.txt";
std::string ResultOutputFileName = "output.txt";

typedef std::map<MAPM,std::set<std::string>> map_mapm_setstring;
typedef std::pair<MAPM,std::set<std::string>> pair_mapm_setstring;

#include "Utility.h"
#include "LetterFrequency.h"
#include "PrimedDictionary.h"
#include "Unscramble.h"

bool ConfirmExceeding15CharacterInput(std::string);
bool ProcessArguments(int, char**);
void Initiate();

void main(int argc, char** argv) {
	if (ProcessArguments(argc, argv)) {
		Initiate();
	}
}

bool ConfirmExceeding15CharacterInput(std::string word) {
	if ( word.size() <= 15 ) {
		return true;
	}
	std::string input;
	std::cout << "Depending on the user's machine, entering 15+ characters could take a while to complete the unscramble." << std::endl;
	std::cout << "Please enter 'y' to proceed: ";
	std::cin >> input;
	if ( input == UserAccept ) {
		return true;
	}
	return false;
}

bool ProcessArguments(int argc, char** argv) {
	std::string option;
	ExecutionPath = argv[0];
	for(int i = 1; i < argc; i++) {
		option = argv[i];
		if (option == OptionCommandHelp) {
			std::cout << CommandHelp << std::endl;
			return false;
		}
		else {
			DictionaryFileName = option;
		}
	}
	return true;
}

void Initiate() {
	Unscramble Unscrambler = Unscramble();
	std::cout << std::endl;
	std::string input;
	while ( input != ":q" ) {
		if ( !Utility::IsValidWord(input) ) {
			std::cout << "[input] -> [a-zA-Z]+" << std::endl;
			std::cout << std::endl;
		}
		else if ( ConfirmExceeding15CharacterInput(input) ) {
			Unscrambler.UnscrambleString(input);
			std::cout << std::endl;
		}
		std::cout << "input: ";
		std::cin >> input;
		std::cout << std::endl;
	}
}

#if defined(_MSC_VER) && _MSC_VER >= 1400 
#pragma warning(pop) 
#endif 