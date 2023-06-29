#include "userInput.h"

int getFrameParams(FrameNode* head, FrameNode* newFrame)
{
	//getting path
	char pathCopy[PATH_LEN] = { 0 }; //This is needed because fopen_s (in checkFileExistence) deletes the path after use

	//copying the path
	strcpy_s(pathCopy, PATH_LEN, getString(newFrame->frame->path, "Please insert frame path:", PATH_LEN));

	//checking if the file exists
	if (!checkFileExistence(pathCopy))
	{
		puts("Can't find file! Frame will not be added");
		deleteList(newFrame);
		return 0;
	}

	//getting duration
	newFrame->frame->duration = getNumber("Please insert frame duration(in milliseconds):", "Invalid duration, please try again.", 0, INT_MAX);

	//getting name
	getNameForFrame(head, newFrame->frame->name);

	return 1;
}

void myFgets(char* str, int len)
{
	fgets(str, len, stdin);
	str[strcspn(str, "\n")] = 0;
}

void getNameForFrame(FrameNode* head, char* name)
{
	printf("Please choose a name for that frame:\n");
	myFgets(name, NAME_LEN);
	while (findFrame(head, name, 0))
	{
		printf("The name is already taken, please enter another name:\n");
		myFgets(name, NAME_LEN);
	}
}

char* getString(char* str, char* strToPrint, int len)
{
	puts(strToPrint);
	myFgets(str, len);
	return str;
}

int getNumber(char* str1, char* str2, int lowerBound, int upperBound)
{
	char numberStr[MAX_INT_LEN + 1] = { 0 }; //+1 for the terminating character
	int number = 0;
	int doesWantToPrintTheSame = str2[0] == 0; // if the second string is empty

	puts(str1);
	myFgets(numberStr, MAX_INT_LEN + 1);
	while (!isNumber(numberStr) && atoi(numberStr) >= lowerBound && atoi(numberStr) <= upperBound)
	{
		doesWantToPrintTheSame? puts(str1) : puts(str2);
		myFgets(numberStr, MAX_INT_LEN + 1);
	}
	return atoi(numberStr);
}