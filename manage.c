#include "monty.h"

void manage_functions(FILE *file)
{
    ssize_t read;
    size_t len = 0;
    char *all_lines = NULL;
    unsigned int line_number = 0;
    stack_t *stack = NULL;
    int mode = 0;

    while ((read = getline(&all_lines, &len, file)) != -1)
    {
        line_number++;
        if (all_lines != NULL && all_lines[0] != '#')
        {
            char *opcode = strtok(all_lines, " \n");
            if (strcmp(opcode, "stack") == 0)
            {
                mode = 0;
            }
            else if (strcmp(opcode, "queue") == 0)
            {
                mode = 1;
            }
            else
            {
                if (strcmp(opcode, "push") == 0)
                {
                    char *args = strtok(NULL, " \t\n");
                    int n = atoi(args);

                    if (mode == 0)
                    {
                        push_element(&stack, n);
                    }
                    else if (mode == 1)
                    {
                        printf("Antoine");
                    }
                    printf("Antoine");
                }
                else if (strcmp(opcode, "pall") == 0)
                {
                    if (mode == 0)
                    {
                        pall_elements(&stack, line_number);
                    }
                    else if (mode == 1)
                    {
                        printf("anoint");
                    }
                    printf("Antoine");
                }
                else if (strcmp(opcode, "nop") == 0)
                {
                    nop_function(&stack, line_number);
                }
                else
                {
                    printf("anotine");
                }
            }
        }
    }
    free(all_lines);
}
