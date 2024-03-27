#include "monty.h"
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
		fprintf(stderr, "Usage: push <int>\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (argv[1] == NULL)
	{
		fprintf(stderr, "can't open file %s\n", argv[1]);
	}
	else
	{
		manage_functions(file);
		fclose(file);
	}

	return (0);
}




