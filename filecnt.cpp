#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <sys/stat.h>
#include "version.h"

// Tuan Quoc Nguyen - tqn170130 - abc

using namespace std;

// initialize counts
int directoryCount = 0;
int fileCount = 0;
int byteCount = 0;

// function
int listdir(const char *name) {
    DIR *dir;
    struct dirent *entry;
    struct stat fileSize;
	// if unable to open
    if (!(dir = opendir(name))) {
	return 1;
    }
    	// if unable to access
    if (access(name, X_OK) != 0) {
    	return 1;
    }
    	// while can still read
    while ((entry = readdir(dir)) != NULL) {
   	// if directory
	if (entry->d_type == DT_DIR) {
    	    char path[1024];
	    char* pathPointer = path;
	    // remove the . and ..
	    if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {continue;}
	    // update path
	    snprintf(path, sizeof(path), "%s/%s", name, entry->d_name);
	    // check access
	    if (access(path, X_OK) != 0) {continue;} 
            // increase directory count
	    directoryCount++;
	    // recursive run
	    listdir(path);
	}
	// if link
	else if (entry->d_type == DT_LNK) {continue;}
	// if file
	else {
	    char path[1024];
	    char* pathPointer = path;
	    // remove the . and ..
	    if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {continue;}
	    // update path
	    snprintf(path, sizeof(path), "%s/%s", name, entry->d_name);
	    // check access
	    if (access(path, R_OK) != 0) {continue;}
	    // increase file count
	    fileCount++;
	    // increase byte count
	    stat(pathPointer, &fileSize);
	    byteCount += fileSize.st_size;
	}
    }
    closedir(dir);    
}

int main(int argc, char* argv[]) {
    // if invalid argument
    if (argc != 2) {
    	cout << "Invalid input. Please try again.";
    }
    string givenDirectory = argv[1];
    int runTry = listdir(argv[1]);
    // if run failed
    if (runTry == 1) {
    	cout << "Run failed.";
    }
    // print out
    cout << "The total number of directories in directory " << givenDirectory << " is: " << directoryCount << ".\n";
    cout << "The total number of files in directory " << givenDirectory << " is: " << fileCount << ".\n";
    cout << "The total number of bytes occupied by all files in directory " << givenDirectory << " is: " << byteCount << ".\n";
}
		    
