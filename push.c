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

