#ifndef LINKEDLISTH
#define LINKEDLISTH

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "logic.h"

#define _CRT_SECURE_NO_WARNINGS 1
#define FALSE 0
#define TRUE !FALSE
#define PATH_LEN 100
#define NAME_LEN 50

// Frame struct
typedef struct Frame
{
	char name[NAME_LEN];
	unsigned int	duration;
	char path[PATH_LEN];
} Frame;


// Link (node) struct
typedef struct FrameNode
{
	Frame* frame;
	struct FrameNode* next;
} FrameNode;

/*
This function adds a frame to the list
input: a path to a picture
output: the new head of the list
*/
FrameNode* addFrame(FrameNode* head, FrameNode* newFrame);

/*
This function frees all dynamically-assigned memory in the list
input: the head of the list
output: none
*/
void deleteList(FrameNode* head);

/*
This function checks whether or not a given name already exists in the list
input: the head of the list, the name to search for
output: is the name in the list
*/
FrameNode* findFrame(FrameNode* head, char* name, int wantToPrint);

/*
This function creates a new node with default values
input: none
output: a pointer to a new node
*/
FrameNode* makeNewNode();

/*
This function changes the duration of all of the frames
input: the head of the list, the new duration
output: none
*/
void changeAllDurations(FrameNode* head, int duration);

/*
This function changes the duration of a frame
input: the head of the list, the name of the frame
output: none
*/
void changeDuration(FrameNode* head, char* name);

/*
This function removes a frame from the list
input: the head of the list, the name of the frame to remove
output: the new head of the list
*/
FrameNode* removeFrame(FrameNode* head, char* name);

/*
This function changes the location (index) of a frame in the list
input: the head of the list, the name of the frame to move, the position to put it in
output: the new head of the list
*/
FrameNode* changFrameLocation(FrameNode* head, int newLocation, char* name);

/*
This fucntion copies the values of the fields of src into dst
input: two Nodes
output: none
*/
void copyFrame(FrameNode* src, FrameNode* dst);

/*
This function calculates the number of frames in the list
input: the head of the list
output: the number of frames in the list
*/
int listLength(FrameNode* head);

#endif
