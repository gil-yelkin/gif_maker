#include "fileHandling.h"

void saveProject(FrameNode* head, char* path)
{
	FILE* projectFile = fopen(path, "w");
	char buffer[MAX_INT_LEN] = { 0 };
	char* duration = NULL;

	while (head)
	{
		//writing the path
		fwrite(head->frame->path, strlen(head->frame->path), 1, projectFile);
		fputc(',', projectFile);

		//writing the duration
		duration = _itoa(head->frame->duration, buffer, 10);
		fwrite(duration, 1, strlen(duration), projectFile);
		fputc(',', projectFile);

		//writing the name
		fwrite(head->frame->name, 1, strlen(head->frame->name), projectFile);
		fputc('\n', projectFile);

		//moving to the next node
		head = head->next;
	}
	fclose(projectFile);
}

FrameNode* loadProject(char* path)
{
	FILE* projectFile = fopen(path, "r");
	FrameNode* head = NULL;
	FrameNode* curr = NULL;
	char line[LINE_LEN] = { 0 }; //max length of a line (+2 for the commas)
	char ch = 0;
	int lineIndex = 0;

	//checking if the file exists
	if (!projectFile)
	{
		puts("Error!- cant open file, creating a new project");
		return NULL;
	}

	//checking if the file is empty
	if ((ch = fgetc(projectFile)) == EOF)
	{
		puts("The wanted file is empty, creating new project.");
		return NULL;
	}

	fseek(projectFile, 0, SEEK_SET); // moving the file pointer back to the start of the file
	//making the head manually
	while (ch != '\n')
	{
		ch = fgetc(projectFile);
		line[lineIndex] = ch;
		lineIndex++;
	}

	line[lineIndex] = 0; // adding terminating character
	lineIndex = 0;
	head = parseLine(line);
	curr = head;

	//making the rest of the list
	while (ch != EOF)
	{
		ch = fgetc(projectFile);
		if (ch == '\n')
		{
			line[lineIndex] = 0; // adding terminating character
			lineIndex = 0; // resetting lineIndex

			//making a new node
			curr->next = parseLine(line);
			curr = curr->next;
		}
		else if(ch != EOF)
		{
			line[lineIndex] = ch;
			lineIndex++;
		}
	}

	//closing the file
	fclose(projectFile);
	puts("Project loaded successfuly!");
	return head;
}

FrameNode* parseLine(char* line)
{
	int lineIndex = 0;
	int paramIndex = 0;
	char duration[MAX_INT_LEN + 1] = { 0 }; //+1 for the terminating character
	FrameNode* newNode = makeNewNode();

	//getting the path
	while (line[lineIndex] != ',')
	{
		newNode->frame->path[paramIndex] = line[lineIndex];
		lineIndex++;
		paramIndex++;
	}
	newNode->frame->path[paramIndex] = 0; //adding terminating character

	//resetting vars
	lineIndex++;
	paramIndex = 0;

	//getting the duration
	while (line[lineIndex] != ',')
	{
		duration[paramIndex] = line[lineIndex];
		lineIndex++;
		paramIndex++;
	}
	newNode->frame->duration = atoi(duration);

	//resetting vars
	lineIndex++;
	paramIndex = 0;

	//getting the name
	while (!(line[lineIndex] == '\n' || line[lineIndex] == EOF || line[lineIndex] == 0))
	{
		newNode->frame->name[paramIndex] = line[lineIndex];
		lineIndex++;
		paramIndex++;
	}
	newNode->frame->name[paramIndex] = 0; //adding terminating character

	return newNode;
}
