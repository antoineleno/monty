#include "monty.h"

/**
 * push_element - function to push an element to the stack
 * @n: value to be inserted in the new node
 */

void push_element(int n)
{
	stack_t *new_node;

	new_node = create_node(n);

	if (head == NULL)
	{
		head = new_node;
	}
	else
	{
		new_node->next = head;
		head->prev = new_node;
		head = new_node;
	}
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
 * @stack: Stack
 * @n: line number while reading
 */
void nop_function(stack_t **stack, int n)
{
	(void) n;
	(void) stack;
}

/**
 * print_top - Function to print the top of the stak
 * @stack: stack
 * @line_number: line number
 */

void print_top(stack_t **stack, unsigned int line_number)
{
	(void) line_number;
	printf("%d\n", (*stack)->n);
}


/**
 * create_node - Creates a node.
 * @n: Number to go inside the node.
 * Return: Upon sucess a pointer to the node. Otherwise NULL.
 */
stack_t *create_node(int n)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
	{
		printf("Antoine");
	}
	node->next = NULL;
	node->prev = NULL;
	node->n = n;
	return (node);
}
