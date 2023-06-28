#ifndef OUTPUTH
#define OUTPUTH

#include "linkedList.h"
#include "userInput.h"
#include "view.h"

/*
This function lists all the frames to the user (name, path and duration)
input: the head of the list
output: none
*/
void listFrames(FrameNode* head);

/*
This function prints the options to the user
input: none
output: none
*/
void printOptions();

#endif
