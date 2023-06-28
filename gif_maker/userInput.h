#ifndef INPUTH
#define INPUTH

#include "userOutput.h"
#include "linkedList.h"
#include "logic.h"

#define _CRT_SECURE_NO_WARNINGS

/*
This function fills the parameters of the given frame
input: the head of the list, the frame to fill
output: none
*/
int getFrameParams(FrameNode* head, FrameNode* newFrame);

/*
This function gets a number from the user
input: the string to print
output: the number
*/
int getNumber(char* str1, char* str2, int lowerBound, int upperBound);

/*
This function gets the path from the user
input: the variable to put the input in, the string to print
output: none
*/
char* getString(char* str, char* strToPrint, int len);

/*
This function gets the name of a frame from the user
input: the head of the list (to check that there are no multipules of names), a pointer to a string
output: none
*/
void getNameForFrame(FrameNode* head, char* name);

/*
This function gets a string from the user and deletes the unnecessary \n at the end
input: the string to put the input in
output: none
*/
void myFgets(char* str, int len);

#endif 
