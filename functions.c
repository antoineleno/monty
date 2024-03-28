#include "monty.h"

/**
 * push_element - function to push an element to the stack
 * @stack: stack
 * @n: value to be inserted in the new node
 */
void push_element(stack_t **stack, int n)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		exit(EXIT_FAILURE);
	}

	new_node->n = n;

	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
	{
		(*stack)->prev = new_node;
	}
	*stack = new_node;
}

/**
 * print_stack - Function to print all the elements of the stack
 * @stack: pointer to the stack
 * @line_number: line number
 */

void print_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	(void) line_number;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	tmp = *stack;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}


/**
 * nop_function - Function that does nothing
 * @stact: Stack
 * @n: line number while reading
 */
void nop_function(stack_t **stack, int n)
{
	(void) n;
	(void) stack;
}
