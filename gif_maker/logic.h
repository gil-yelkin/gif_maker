#ifndef LOGICH
#define LOGICH

#include <stdlib.h>
#include <stdio.h>

#define MAX_INT_LEN 10
#define ASCII_OF_ZERO 48
#define ASCII_OF_NINE ASCII_OF_ZERO + 9


/*
This function will check if the given string represents a number
input: a string
output: is the string a number'
*/
int isNumber(char* numberStr);

/*
This function checks if a file exists or not
input: the path to the file
output: does the file exist
*/
int checkFileExistence(char* path);

#endif // !LOGICH
