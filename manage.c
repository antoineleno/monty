#include "monty.h"

void manage_functions(FILE *file)
{
    ssize_t read;
    size_t len = 0;
    char *all_lines = NULL;
    unsigned int line_number = 0;
    stack_t *stack = NULL;
    int mode = STACK_MODE;

    while ((read = getline(&all_lines, &len, file)) != -1)
    {
        line_number++;
        if (all_lines != NULL && all_lines[0] != '#')
        {
            char *opcode = strtok(all_lines, " \t\n");
            if (strcmp(opcode, "stack") == 0)
            {
                mode = STACK_MODE;
            }
            else if (strcmp(opcode, "queue") == 0)
            {
                mode = QUEUE_MODE;
            }
            else
            {
                if (strcmp(opcode, "push") == 0)
                {
                    char *args = strtok(NULL, " \t\n");
                    int n = atoi(args);

                    if (mode == STACK_MODE || mode == QUEUE_MODE)
                    {
                        if (mode == STACK_MODE)
						{
							push_element(&stack, n);
						}
                        else
						{
							printf("Antoine");
						}
                    }
                    else
                    {
                        fprintf(stderr, "L%d: Missing mode directive (stack or queue)\n", line_number);
                        exit(EXIT_FAILURE);
                    }
                }
                else if (strcmp(opcode, "pall") == 0)
                {
                    if (mode == STACK_MODE)
					{
						pall_elements(&stack, line_number);
					}
                    else
					{
						printf("Antoine");
					}
                }
                else if (strcmp(opcode, "nop") == 0)
                {
                    nop_function(&stack, line_number);
                }
            }
        }
    }
    free(all_lines);
}
