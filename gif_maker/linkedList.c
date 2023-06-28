#include "linkedList.h"
#include "userInput.h"

FrameNode* addFrame(FrameNode* head, FrameNode* newFrame)
{
	FrameNode* curr = head;
	char pathCopy[PATH_LEN] = { 0 };

	//returning the path to newFrame
	strncpy_s(newFrame->frame->path, PATH_LEN, pathCopy, PATH_LEN);

	//handeling edge case where the head is NULL
	if (!curr)
	{
		return newFrame;
	}

	//finding the last node in the list
	while (curr->next)
	{
		curr = curr->next;
	}

	//appending the new node to the end of the list
	curr->next = newFrame;

	return head;
}

void deleteList(FrameNode* head)
{
	FrameNode* next = NULL;

	while (head)
	{
		next = head->next;
		free(head->frame);
		free(head);
		head = next;
	}
}

FrameNode* findFrame(FrameNode* head, char* name, int wantToPrint)
{
	while (head)
	{
		if (!strcmp(head->frame->name, name))
		{
			return head;
		}
		head = head->next;
	}

	if (wantToPrint)
	{
		puts("The frame does not exist");
	}
	return NULL;
}

FrameNode* makeNewNode()
{
	FrameNode* newFrame = (FrameNode*)malloc(sizeof(FrameNode));

	if (!newFrame)
	{
		puts("[FATAL ERROR] Memory allocatioon error!");
		return NULL;
	}
	else
	{
		newFrame->next = NULL;
	}
	newFrame->frame = (Frame*)malloc(sizeof(Frame));
	if (!(newFrame->frame))
	{
		puts("[FATAL ERROR] Memory allocatioon error!");
		return NULL;
	}
	else
	{
		newFrame->frame->duration = 150;
		newFrame->frame->name[0] = 0;
		newFrame->frame->path[0] = 0;
		return newFrame;
	}
}

FrameNode* removeFrame(FrameNode* head, char* name)
{
	FrameNode* curr = head;
	FrameNode* prev = NULL;

	//making sure that the name is in the list
	if (!findFrame(head, name, 1))
	{
		return head;
	}

	//in case that head is NULL
	else if(!head)
	{
		return NULL;
	}

	//handeling case where the frame to remove is the head
	if (!strcmp(head->frame->name, name))
	{
		curr = head->next;
		head->next = NULL;
		deleteList(head);
		return curr;
	}

	while (1) //we already know that the node is in the list so there is no need for a breaking condition
	{
		prev = curr;
		curr = curr->next;
		if (!strcmp(curr->frame->name, name))
		{
			if (!prev)
			{
				prev = curr->next;
			}
			else
			{
				prev->next = curr->next;
			}
			curr->next = NULL;
			deleteList(curr);
			return head;
		}
	}
}

void changeAllDurations(FrameNode* head, int duration)
{
	while (head)
	{
		head->frame->duration = duration;
		head = head->next;
	}
}

FrameNode* changFrameLocation(FrameNode* head, int newLocation, char* name)
{
	FrameNode* curr = NULL;
	FrameNode* toMove = findFrame(head, name, 1);
	FrameNode* copy = makeNewNode();
	int i = 0;
	int length = listLength(head);

	//in case that the given name does not exist in the list
	if (!toMove)
	{
		return head;
	}

	//in case that the index does not exist in the list
	while (newLocation < 1 || newLocation > length)
	{
		printf("The movie contains only %d frames!\n", length);
		newLocation = getNumber("Please try again", "", 0, length);
	}
	//making a copy of the frame to move
	copyFrame(toMove, copy);

	//removing the frame from its current location
	head = removeFrame(head, name);
	curr = head;

	//handeling edge case where we need to move the frame to the head of the line
	if (newLocation == 1)
	{
		copy->next = head;
		return copy;
	}

	//handeling all other cases
	for (i = 1; i < newLocation - 1; i++)
	{
		curr = curr->next;
	}
	copy->next = curr->next;
	curr->next = copy;
	return head;
}

void copyFrame(FrameNode* src, FrameNode* dst)
{
	dst->next = src->next;
	dst->frame->duration = src->frame->duration;
	strncpy_s(dst->frame->name, NAME_LEN, src->frame->name, NAME_LEN);
	strncpy_s(dst->frame->path, PATH_LEN, src->frame->path, PATH_LEN);
}

void changeDuration(FrameNode* head, char* name)
{
	FrameNode* toChange = findFrame(head, name, 1);

	if (toChange)
	{
		toChange->frame->duration = getNumber("Enter the new duration", "Invalid duration, please try again.", 0, INT_MAX);
	}
}

int listLength(FrameNode* head)
{
	int counter = 0;

	while (head)
	{
		head = head->next;
		counter++;
	}

	return counter;
}