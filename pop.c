#include "monty.h"

/**
 * pop - removes the top element of the stack
 * @stack: points to top of the given stack
 * @line_number: the number of the line which the error occured
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		cleanup_and_exit(*stack, EXIT_FAILURE);
	}

	*stack = (*stack)->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;

	free(temp);
}
