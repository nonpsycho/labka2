#include <stdio.h>
#include <stdlib.h>
#include "task2.h"



void SecondTask(char* file)
{

	FILE* inputFile = fopen(file, "r");
	if (inputFile == NULL)
	{
		printf("File openning error\n");
		exit(-1);
	}

	
	fclose(inputFile);
	return 0;
}