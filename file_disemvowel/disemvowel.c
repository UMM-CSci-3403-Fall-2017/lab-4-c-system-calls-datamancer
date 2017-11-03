#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#define BUF_SIZE 1024

bool is_vowel(char c) {
	
	char vowel[5] = {'A', 'E', 'I', 'O', 'U'};
	int i = 0;
	while(toupper(c) != vowel[i] && i < 5) {
		if (i == 5) {
			return false;
		}
		else {
			i++;
		}
	}

	return true;


}

int copy_non_vowels(int num_chars, char* in_buf, char* out_buf) {
	
	int non_vowels = 0;
	for(int i = 0; i < BUF_SIZE; i++) {
		if(is_vowel(in_buf[i] == false)) {
			out_buf[non_vowels] = in_buf[i];
			non_vowels = non_vowels + 1;
		}
	}

	return non_vowels;
}

void disemvowel(FILE* inputFile, FILE* outputFile) {

	int dis_size = BUF_SIZE;
	int dis_out = 0;
	char* char_input = (char*) calloc(dis_size,sizeof(char));
	fread(char_input, sizeof(char), dis_size, inputFile);
	for(int i = 0; i < dis_size; i++) {
		if (is_vowel(char_input[i])){
		}
		else {
		dis_out = dis_out + 1;
		}
	}
	char* char_out = (char*) calloc(dis_out, sizeof(char));
	copy_non_vowels(dis_out, char_input, char_out);
	
	free(char_input);
	free(char_out);
}


void main (int argc, char *argv[]) {
	FILE *inputFile;
	FILE *outputFile;
	
	if( argc == 1) {
	diemvowel(inputFile, outputFile);
	} else if (argc == 2) { inputFile = fopen(argv[1], "r");}
	else if ( argc == 3) {inputFile = fopen(argv[1], "r");
			      outputFile = fopen(argv[2], "w");}
	else {
	print("incorret file inout");
	}
		

	disemvowel(inputFile, outputFile);
	return 0;


}
