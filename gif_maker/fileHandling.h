#ifndef FILEHANDELINGH
#define FILEHANDELINGH
#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include "linkedList.h"

#define MAX_INT_LEN 10
#define LINE_LEN PATH_LEN + MAX_INT_LEN + NAME_LEN + 2

/*
This function saves the project 
input: the head of the list
output: none
*/
void saveProject(FrameNode* head, char* path);

/*
This function loads an existing project
input: the path to the project
output: the head of the list
*/
FrameNode* loadProject(char* path);

/*
This function parses a text line into path, duration and name for a frame
input: a pointer to a frame node, a string
output: none
*/
FrameNode* parseLine(char* line);

#endif
