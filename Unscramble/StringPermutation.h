#ifndef _STRING_PERMUTATION_H
#define _STRING_PERMUTATION_H

class StringPermutation {
	private:
		static void RecursiveFunction(int, std::vector<char>, std::vector<char>, int);
	public:
		static void DisplayPermutation(char*);
};

void StringPermutation::DisplayPermutation(char* input) {
	int input_size = strlen(input);
	std::vector<char> input_vector;
	std::vector<char> output_vector (input_size,NULL);
	for( int i = 0; i < input_size; i++) {
		input_vector.push_back(*input);
		input++;
	}
	RecursiveFunction(input_size, input_vector, output_vector, 0);
}

void StringPermutation::RecursiveFunction(int size ,std::vector<char> input, std::vector<char> output, int level) {
	if (level == size) {
		for ( int i = 0; i < size; i++) {
			std::cout << output.at(i);
		}
		std::cout << std::endl;
	}
	else {
		for( int i = 0; i < size; i++) { 
			if ( input.at(i) != NULL ) {
				char tmp = input.at(i);
				input.at(i) = NULL;
				for( int j = 0; j < size; j++) {
					if ( output.at(j) == NULL ) {
						std::vector<char> new_output = output;
						new_output.at(j) = tmp;
						RecursiveFunction(size, input,new_output,level+1);
					}
				}
				break;
			}
		}
	}
}

#endif