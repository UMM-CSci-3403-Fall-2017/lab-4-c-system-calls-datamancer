#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <ftw.h>
#include <string.h>



static int num_dirs, num_regular;

static int callback(const char *fpath, const struct stat *sb, int typeflag) { 
    // Define stuff here 
   if (typeflag == FTW_F) {
	num_regular++;
	return 0;
	} else {
	     num_dirs++;
     	     return 0;
	}
return 0;   
}

#define MAX_FTW_DEPTH 16

int main(int argc, char** argv) { 
    // Check arguments and set things up

	if(argc != 2) {
		printf ("current usage: %s <path>\n", argv[0]);
		printf ("       <path> is file/root");
		return 1;
	}
    ftw(argv[1], callback, MAX_FTW_DEPTH);

    // Print out the results 
    //
    printf("%d directories.\n", num_dirs);
    printf("%d regular files.\n", num_regular);
}
