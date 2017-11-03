#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <ftw.h>
#include <string.h>



static int num_dirs, num_regular;

static int callback(const char *fpath, const struct stat *sb, int typeflag) { 
    // Define stuff here 
   	
}

#define MAX_FTW_DEPTH 16

int main(int argc, char** argv) { 
    // Check arguments and set things up

    ftw(argv[1], callback, MAX_FTW_DEPTH);

    // Print out the results 
}static int callback(const char *fpath, const struct stat *sb, int typeflag)
