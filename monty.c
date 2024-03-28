#include "monty.h"
stack_t *head = NULL;
/**
 * main - Entry point
 * @argc: Number of arguments enter
 * @argv: Arguments enterd
 * Return: Always 0 (Success)
 */

int main(int argc, char *argv[])
{
	FILE *file;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	manage_functions(file);
	free_nodes();
	fclose(file);

	return (0);
}

/**
 * manage_functions - Function to manage all the cases
 * @file: File
 */

void manage_functions(FILE *file)
{
	printf("Antoine");
}


/**
 * free_nodes - Function to free the stack
 */

void free_nodes(void)
{
	stack_t *tmp;

	if (head == NULL)
	{
		return;
	}
	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}

