#include "monty.h"

/**
 * pint - Prints the value at the top of the stack
 * @stack: Pointer to the top of the stack
 * @line_number: Line number in the bytecode file
 * where the pint instruction is encountered.
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		cleanup_and_exit(*stack, EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
