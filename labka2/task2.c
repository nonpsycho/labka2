#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "task2.h"
#include "array.h"

#define MAX_LENGTH 256


typedef struct 
{
	int idx;
	char* word;
}Word;

static void SwapWords(FILE* inputFile, Vector* words)
{
	for (int i = 0; i < words->count / 2; i++)
	{
		int j = words->count - i - 1;
		Word* lWord = (Word*)AtVec(words, i);
		Word* rWord = (Word*)AtVec(words, j);

		fseek(inputFile, lWord->idx, SEEK_SET);
		fwrite(rWord->word, strlen(rWord->word), 1, inputFile); 
		fseek(inputFile, rWord->idx, SEEK_SET);
		fwrite(lWord->word, strlen(lWord->word), 1, inputFile);
	}
}
	
static void FindWords(FILE* inputFile, int length, Vector* words)
{
	char currWord[MAX_LENGTH];
	
	while (fscanf(inputFile, "%s", currWord) != EOF)
	{
		if (strlen(currWord) == length)
		{
			Word w = { .idx = ftell(inputFile) - length, .word = malloc(length + 1)};
			strcpy(w.word, currWord); 
			PushBackVec(words, &w);
		}

	}
}

void SecondTask(char* file, int length)
{

	FILE* inputFile = fopen(file, "r+");
	if (inputFile == NULL)
	{
		printf("File openning error\n");
		exit(-1);
	}

	Vector words = ConstructVec(sizeof(Word));
	FindWords(inputFile, length, &words);
	SwapWords(inputFile, &words);

	for (int i = 0; i < words.count; i++)
	{
		Word* w = (Word*)AtVec(&words, i);
		free(w->word);
	}
	DestructVec(&words);

	fclose(inputFile);

}