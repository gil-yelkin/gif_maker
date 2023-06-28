#include "logic.h"

int isNumber(char* numberStr)
{
	int i = 0;

	if (!numberStr[0]) // checking manually if the string is empty - edge case
	{
		return 0;
	}

	for (i = 1; i < MAX_INT_LEN + 1; i++)
	{
		if (!numberStr[i])
		{
			return 1;
		}
		//checking for each character if it is a number
		else if ( (int)numberStr[i] < ASCII_OF_ZERO || (int)numberStr[i] > ASCII_OF_NINE)
		{
			return 0;
		}
	}
}

int checkFileExistence(char* path)
{
	FILE* file = NULL;
	fopen_s(&file, path, "r");

	if (file)
	{
		fclose(path);
		return 1;
	}
	else
	{
		return 0;
	}
}