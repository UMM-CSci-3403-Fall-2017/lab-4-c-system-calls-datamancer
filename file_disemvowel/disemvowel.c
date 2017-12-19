#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#define BUF_SIZE 1024

bool is_vowel(char c) {
	//checks char c agaisnt every possible vowel, both upper case and lower case.
	return c == 'a' || c == 'A' || c == 'e' || c == 'E' || c == 'i' || c == 'I' || c == 'o' || c == 'O' || c == 'u' || c == 'U';


}

int copy_non_vowels(int num_chars, char* in_buf, char* out_buf) {
	// finding the position of all consonants within the in_buf stream. 
	// loops through the character string, and for every postion that is not a vowel gets copied to the outbuf stream.
	
	int position = 0;
	for (int i = 0; i < num_chars; i++) {		
		if(!is_vowel(in_buf[i])){
			out_buf[position]=in_buf[i];
			position++;
		}
	}
	return position;
}

void disemvowel(FILE* inputFile, FILE* outputFile) {
	//set up integers for the character positions bot vowel and consonants
	//create the in buffer to be the size of BUF_SIZE;
	//read the characters from the input file and feed them into the in_buffe

	int chars;
	int other_chars;
	char in_buffer[BUF_SIZE];
	chars = fread(in_buffer, sizeof(char), BUF_SIZE, inputFile);
	char out_buffer[chars];
	other_chars = copy_non_vowels(chars, in_buffer, out_buffer);
	fwrite(out_buffer, sizeof(char), other_chars, outputFile);
}


int main (int argc, char *argv[]) {
	FILE *input;
	FILE *output;
//case handling for arguments.
	switch(argc) {
		case 1:
			//set up the base case of input output to stdin/out
			input=stdin;
			output=stdout;
			break;

		case 2:
			if((input = fopen(argv[1], "r" )) == NULL) {
				puts("input incorrect");
				exit(0);
			} else {
			//do nothing
			}

			break;
		case 3:
			if((input=fopen(argv[2], "r")) == NULL) {
				puts("input incorrect");
				exit(0);
			} else {
			//do nothing
			}
			if ((output= fopen(argv[2], "w")) == NULL) {
				puts("output incorrect");
				exit(0);
			} else {
			//do nothing
			}

			break; 

		default:
			puts("too many args");
			exit(0);
	}
	disemvowel(input,output);
	fclose(input);
	fclose(output);

	return 0;


	

}
