#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>


#define ERROR_NONE 0
#define ERROR_FILE_OPEN 1
#define ERROR_INVALID_INSTRUCTION 2
#define ERROR_STACK_EMPTY 3

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */

typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;



/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *head;

void pall_elements(stack_t **stack, int line_number);
void nop_function(stack_t **stack, int n);
void free_nodes(void);
void manage_functions(FILE *file);
void call_function(char *function);
void push_element(int n);
void print_stack(stack_t **, unsigned int line_number);
void nop_function(stack_t **stack, int n);
void print_top(stack_t **stack, unsigned int line_number);
stack_t *create_node(int n);
#endif

