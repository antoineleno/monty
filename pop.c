#include "monty.h"
/**
 * delete_dnodeint_at_index - Function to delete a node
 * at index
 * @head: head of the node
 * @index: index to delete the node
 * Return: 1 if success otherwise -1
 */

int delete_dnodeint_at_index(stack_t **head, unsigned int index)
{
	stack_t *first;
	stack_t *second;
	unsigned int i;

	first = *head;

	if (first != NULL)
		while (first->prev != NULL)
			first = first->prev;

	i = 0;

	while (first != NULL)
	{
		if (i == index)
		{
			if (i == 0)
			{
				*head = first->next;
				if (*head != NULL)
					(*head)->prev = NULL;
			}
			else
			{
				second->next = first->next;

				if (first->next != NULL)
					first->next->prev = second;
			}

			free(first);
			return (1);
		}
		second = first;
		first = first->next;
		i++;
	}

	return (-1);
}

