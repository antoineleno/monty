#include "monty.h"

/**
 * manage_functions - function to mannage all the functions
 * @file: File name
 */

void manage_functions(FILE *file)
{
	ssize_t read;
	size_t len = 0;
	char *all_lines = NULL;
	unsigned int line_number = 0;
	stack_t *stack = NULL;

	while ((read = (getline(&all_lines, &len, file)) != -1))
	{
		if (read == -1)
		{
			fprintf(stderr, "Error reading file\n");
			free(all_lines);
			exit(EXIT_FAILURE);
		}
		line_number++;
		if (all_lines != NULL && all_lines[0] != '#')
		{
			char *opcode = strtok(all_lines, " \t\n");

			if (strcmp(opcode, "push") == 0)
			{
				char *args = strtok(NULL, " \t\n");
				int n = atoi(args);

				push_element(&stack, n);
			}
			else if (strcmp(opcode, "pall") == 0)
			{
				pall_elements(&stack, line_number);
			}
		}
	}
	free(all_lines);
}


