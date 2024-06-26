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
 * manage_functions - Function to manage all the case
 * @file: file
 */
void manage_functions(FILE *file)
{
	ssize_t read;
	size_t len = 0;
	char *lines = NULL;
	unsigned int line_number = 0;
	stack_t *stack = NULL;

	while ((read = getline(&lines, &len, file)) != -1)
	{
		line_number++;
		if (lines != NULL && lines[0] != '#')
		{
			char *opcode = strtok(lines, " \n");

			if (strcmp(opcode, "push") == 0)
			{
				char *args = strtok(NULL, " \n");
				int n = atoi(args);

				if (!isAllDigits(args))
				{
					fprintf(stderr, "L%d: usage: push integer\n", line_number);
					exit(EXIT_FAILURE);
				}
				push_element(n);
			}
			else if (strcmp(opcode, "pall") == 0)
				print_stack(&head, line_number);
			else if (strcmp(opcode, "nop") == 0)
				nop_function(&stack, line_number);
			else if (strcmp(opcode, "pint") == 0)
				print_top(&stack, line_number);
			else
			{
				fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
				exit(EXIT_FAILURE);
			}
		}
	}
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
/**
 * isAllDigits - Function
 * @string: string
 * Return:  Boll
 */

bool isAllDigits(char *string)
{
	while (*string)
	{
		if (!isdigit(*string))
		{
			return (false);
		}
		string++;
	}
	return (true);
}

