/*********************************
* Class: MAGSHIMIM Final Project *
* Play function declaration          *
**********************************/

#ifndef VIEWH
#define VIEWH
#define CV_IGNORE_DEBUG_BUILD_GUARD

#include <opencv2/imgcodecs/imgcodecs_c.h>
#include <stdio.h>
#include <opencv2\core\core_c.h>
#include <opencv2\highgui\highgui_c.h>
#include "LinkedList.h"

#define GIF_REPEAT 5

/*
This function will play the given list representive of a GIF in a new window
input: the head of the list
output: none
*/
void play(FrameNode* list);

#endif