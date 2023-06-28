#include "userOutput.h"

void printOptions()
{
	puts("\nWhat would you like to do?"); 
	puts(" [0] Exit");
	puts(" [1] Add new Frame");
	puts(" [2] Remove a Frame");
	puts(" [3] Change frame index");
	puts(" [4] Change frame duration");
	puts(" [5] Change duration of all frames");
	puts(" [6] List frames");
	puts(" [7] Play movie!");
	puts(" [8] Save project");
}

void listFrames(FrameNode* head)
{
	puts("\t\t\tName\t\tDuration\tPath");
	while (head)
	{
		printf("\t\t\t%s\t\t%d ms\t\t%s\n", head->frame->name, head->frame->duration, head->frame->path);
		head = head->next;
	}
	puts("\n\n");
}