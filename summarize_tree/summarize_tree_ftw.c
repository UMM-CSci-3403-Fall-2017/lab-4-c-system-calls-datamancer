#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <ftw.h>
#include <sys/stat.h>
#include <string.h>



static int num_dir;
static int num_regular;

static int callback(const char *fpath, const struct stat *sb, int typeflag) {
	//counts number of dirs and regular files based upon flat type 
	//if flag = FTW_F then it is a regular file, else it is a directory
	if(typeflag == FTW_F) {
		num_regular++;	
	} else if ( typeflag == FTW_D) {
		if(strcmp(fpath, ".") != 0 || strcmp(fpath, "..") !=0) {
				num_dir++;
				}
	}

	return 0;
}
    
#define MAX_FTW_DEPTH 16
int main(int argc, char* argv[]) {
	//reset the ariables
	num_dir=0, num_regular = 0;
	ftw(argv[1], callback, MAX_FTW_DEPTH);
	//print the count of files/directories
	printf("There were %d directories. \n", num_dir);
	printf("There were %d regular files. \n", num_regular);


    }
