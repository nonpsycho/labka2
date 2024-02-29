#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "task1.h"

#define MAX_LENGTH 256

static int WordCounter(FILE* inputFile)
{
	char currWord[MAX_LENGTH];
	char prevWord[MAX_LENGTH];
	int currCounter = 0;
	int maxCounter = 0; 

	if (fscanf(inputFile, "%s", currWord) != EOF)
	{
		strcpy(prevWord, currWord); 
		currCounter = 1; 
		maxCounter = currCounter;

	}
	
	
	while (fscanf(inputFile, "%s", currWord) != EOF)
	{
		

		if (strcmp(currWord, prevWord) == 0)
		{
			currCounter++; 
		}
		else
		{
			currCounter = 1; 
		}
		if (currCounter >= maxCounter)
		{
			maxCounter = currCounter;
		}
		strcpy(prevWord, currWord); 
	}
	return maxCounter; 
}

void FirstTask(char* file)
{
	FILE* inputFile = fopen(file, "r");
	if (inputFile == NULL)
	{
		printf("File openning error\n");
		exit(-1);
	}

	int numberOfWords = WordCounter(inputFile);
	printf("The number of words in the longest sequence of words: %d\n", numberOfWords);

	fclose(inputFile); 
	return 0;
}