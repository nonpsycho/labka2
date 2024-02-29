#include <stdio.h>
#include "unitTests.h"
#include "task1.h"
#include "task2.h"

void RunTests()
{
	int choice = 0;
	printf("Enter which task you want to test?\n");
	scanf_s("%d", &choice);
	switch (choice)
	{
	case 1:
	{
		printf("You choose tests for task 1\n");
		printf("Test empty file\n");
		FirstTask("empty.txt");
		printf("Test file with one word\n");
		FirstTask("oneword.txt");
		printf("Test file with two sequences\n");
		FirstTask("sequence.txt");
		printf("Test file with line break\n");
		FirstTask("mono.txt");

		break;
	}
	case 2:
	{
		printf("You choose tests for task 2\n");
		printf("Test file with words one size\n");
		SecondTask("onelength.txt", 6);
		printf("Test file with simple sentence\n");
		SecondTask("simplesentence.txt", 5);
		printf("Test with length smaller then words length\n");
		SecondTask("smallleng.txt", 1);
		printf("Test with length smaller then words length\n");
		SecondTask("bigleng.txt", 7);
		break;
	}
	default:
	{
		printf("\nInvalid number(( try again!\n");
		break;
	}
	}
}