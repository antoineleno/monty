#include "monty.h"
/**
 * pall_elements - Function to print elements of the stack
 * @stack: stack
 * @line_number: Line number of the file
 */

void pall_elements(stack_t **stack, int line_number)
{
	stack_t *current = *stack;

	(void) line_number;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

