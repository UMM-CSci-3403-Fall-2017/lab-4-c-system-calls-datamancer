#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdbool.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>

//initialize variable for the number of idirectories and teh number of regular files
static int num_dir;
static int num_regular;

//is_dir checks a directory of a file to determine if it is a directory or not. 
bool is_dir(const char* path) {

	struct stat dir;
	if(stat(path, &dir) ==0) {
			if(S_ISDIR(dir.st_mode)){
			return true;	
			} else { 
				return false;
			}
			} else {
			       	return false;
			}
		}

void process_path(const char*);

void process_directory(const char* path) {
	//setting of dirrectory variables
	DIR* Top_dir;
	Top_dir = opendir(path);
	struct dirent* dir;
	chdir(path);
	//loop though while dir is not null
	//commpares the first letter of each directory name
	//if it is a . or .. then continue else run process path of d_name directory 
	while((dir=(readdir(Top_dir)))!= NULL ) {

		if((strcmp(dir->d_name, ".") ==0) || (strcmp(dir->d_name, "..") == 0)) {
		continue;
		}
		process_path(dir->d_name);
	}
	//increment num_dirs, cd two levels up and close top_dir
	++num_dir;
	chdir("..");
	closedir(Top_dir);
}

void process_file(const char* path) {
	++num_regular;

}

void process_path(const char* path) {
	if(is_dir(path)){
		//if the path is a driectory run process direcotry to get the num directories 
		process_directory(path);
	} else {
		//else continue wuth process_file
		process_file(path);
	}
}

int main (int argc, char *argv[]){
	//command line argument handling
	if(argc!=2) {
		printf("Usage: %s <path>\n", argv[0]);
		printf("       where <path> is the file or root of the tree you want to summarize.\n");
	return 1;	
	}

	//reset the variables

	num_dir = 0;
	num_regular = 0;
	process_path(argv[1]);
	//print out the results 
	printf("There were %d directories.\n", num_dir);
	printf("There were %d regular files.\n", num_regular);
	return 0;
}
