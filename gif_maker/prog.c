/*********************************
* Class: MAGSHIMIM C2	         *
* GIL YELKIN                     *
* GitHub: 'gil_yelkin'           *
* LinkedIn: 'Gil Yelkin'         *
**********************************/

#pragma warning (disable : 6031)
#define _CRT_SECURE_NO_WARNINGS 1
#define CV_IGNORE_DEBUG_BUILD_GUARD
#include "view.h"
#include "linkedList.h"
#include "fileHandling.h"
#include "userInput.h"
#include "userOutput.h"

int main(void)
{
	FrameNode* head = NULL;
	FrameNode* newFrame = NULL;
	char name[NAME_LEN] = { 0 };
	char path[PATH_LEN] = { 0 };
	int choice = 0;

	// choosing wheather to load an existing project or creat a new one
	choice = getNumber("Welcome to Magshimim Movie Maker! What would you like to do?\n [0] Create a new project\n [1] Load an existing project", "Invalid choice, please try again.", 0, 1);

	if (choice)
	{
		head = loadProject(getString(path, "Enter the path of the project (including project name):", PATH_LEN));
	}
	else
	{
		puts("Working on a new project.");
	}

	do
	{
		printOptions(); //printing the options

		switch (choice = getNumber("", "Invalid choice, please try again.", 0, 8))
		{
			case 0:
				puts("Bye!");
				getchar();
				break;

			case 1:
				puts("*** Creating new frame ***");
				if (getFrameParams(head, newFrame = makeNewNode()))
				{
					head = addFrame(head, newFrame);
				}
				break;

			case 2:
				head = removeFrame(head, getString(name, "Enter the name of the frame you wish to erase", NAME_LEN));
				break;

			case 3:
				head = changFrameLocation(head, getNumber("Enter the new index in the movie you wish to place the frame", "", 0, INT_MAX), getString(name, "Enter the name of the frame", NAME_LEN));
				break;

			case 4:
				changeDuration(head, getString(name, "enter the name of the frame", NAME_LEN));
				break;

			case 5:
				changeAllDurations(head, getNumber("Enter the duration for all frames:", "Invalid duration, please try again.", 0, INT_MAX));
				break;

			case 6:
				listFrames(head);
				break;

			case 7:
				play(head);
				break;

			case 8:
				saveProject(head, getString(path, "Where to save the project?, enter a full path and file name", PATH_LEN));
				break;
		}
	} while (choice != 0);

	//freeing memory
	deleteList(head);

	//NULL'ing head
	head = NULL;

	return 0;
}
