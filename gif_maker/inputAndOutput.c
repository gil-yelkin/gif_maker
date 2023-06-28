

int isNumber(char* str)
{
	int i = 0;
	int len = strlen(str);

	//confirming that the ascii value of each character is indeed a numbers
	for (i = 0; i < len; i++)
	{
		if (!((int)str[i] >= 48 && (int)str[i] <= 57))
		{
			return 0;
		}
	}

	return 1;
}