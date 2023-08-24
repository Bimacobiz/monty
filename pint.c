#include "monty.h"
/**
 * pint - prints the value found at the top of the
 * stack followed by a new line
 * @stack: points to the stack data structure
 */
void pint(stack_t* data_stack, int line_number)
{
    if (data_stack->top != NULL)
    {
	    printf("%d\n", data_stack->top->data);
    }
    else
    {
     fprintf(stderr,"L%d: can't pint, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }
}
