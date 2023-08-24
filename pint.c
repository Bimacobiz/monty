#include "monty.h"

/**
 * pint - prints the value found at the top of the
 * stack followed by a new line
 * @top: points to the top of the stack data structure
 * @line_number: current line number in the script
 * Return: Pointer to the top node of the stack
 */
stack_t *pint(stack_t **top, unsigned int line_number)
{
	stack_t *stack_head;

	stack_head = *top;

	if (stack_head != NULL)
	{
		printf("%d\n", stack_head->n); 
	}
	else
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	return (stack_head); 
}
