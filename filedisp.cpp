#include <iostream>
#include <string.h>
#include <string>
#include "version.h"

// Tuan Quoc Nguyen - tqn170130 - abc

using namespace std;

int main(int argc, char* argv[]) {
    displayVersion();
    // if invalid argument
    if (argc != 2) {
        cout << "Invalid argument.\n";
    }
    // if option -d
    if (strcmp(argv[1],"-d") == 0) {
        string input = "";
        getline(cin, input);
        while (input != "") {
            // if found
            if (input.find("directories") != -1) {
                cout << input << endl;
            	return 0;
	    }
	    // else continue the loop to find
            else {
                getline(cin, input);
                continue;
            }
        }
	cout << "Word not found.\n";
	return 1;
    }
    // if option -f
    else if (strcmp(argv[1],"-f") == 0) {
        string input = "";
        getline(cin, input);
        while (input != "") {
            // if found
            if (input.find("files") != -1) {
                cout << input << endl;
            	return 0;
	    }
	    // else continue the loop to find
            else {
                getline(cin, input);
                continue;
            }
        }
	cout << "Word not found.\n";
	return 1;
    }
    // if option -b
    else if (strcmp(argv[1],"-b") == 0) {
        string input = "";
        getline(cin, input);
        while (input != "") {
            // if found
            if (input.find("bytes") != -1) {
                cout << input << endl;
            	return 0;
	    }
	    // else continue the loop to find
            else {
                getline(cin, input);
                continue;
            }
        }
	cout << "Word not found.\n";
	return 1;
    }
    // if invalid option
    else {
        cout << "Invalid argument.\n";
    }
}
