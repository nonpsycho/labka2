#include <stdio.h>
#include "task1.h"
#include "task2.h"
#include "unitTests.h"

int main(int argc, char* argv[])
{
	char* file; 
	if (argc < 2)
	{
		file = "example.txt";
	}
	else
	{
		file = argv[1]; 
	}
	int choice;
	do
	{
		printf("\n\tMenu:\n");
		printf("1 - Task 1: Calculate the number of words in the longest sequence of words\n");
		printf("2 - Task 2: Reverse the order of words of the specified length\n");
		printf("3 - Tests for tasks\n");
		printf("0 - Finish the program\n"); 
		printf("Choose a task: \n");
		scanf_s("%d", &choice);

		switch (choice)
		{
		case 0:
		{
			printf("The program is completed!");
			break;
		}
		case 1:
		{
			printf("You choose a task 1\n");
			FirstTask(file);
			break;
		}
		case 2:
		{
			printf("You choose a task 2\n");
			int length;
			printf("Enter the length of the word:\n");
			scanf_s("%d", &length);
			SecondTask(file, length);
			printf("Check file\n");
			break;
		}
		case 3:
		{
			printf("You choose tests for tasks\n");
			RunTests();
			break;
		}
		default:
		{
			printf("\nInvalid number(( try again!\n");
			break;
		}
		}

	} while (choice != 0);

	return 0;
}