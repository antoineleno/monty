#include "monty.h"
/**
 * pint_element - Function to print elements of a doubly list
 * @stack: stack
 */

void pint_element(stack_t **stack)
{
	const stack_t *current;

	if (*stack == NULL)
	{
		printf("The list is empty");
		return;
	}
	current = *stack;
	printf("%d\n", current->n);
}

