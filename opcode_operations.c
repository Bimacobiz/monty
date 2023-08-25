#include "monty.h"
#define UNUSED(x) (void)(x)

/**
 * push - adds an element onto the stack
 * @stack: A pointer to a pointer to the top of the stack.
 * @line_number: Line number in the bytecode file
 * where the push instruction is encountered.
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;
	char *opera;
	int nu;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failure\n");
		cleanup_and_exit(*stack, EXIT_FAILURE);
	}

	opera = strtok(NULL, DELIMS);
	if (opera == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		cleanup_and_exit(*stack, EXIT_FAILURE);
	}

	nu = atoi(opera);

	new_node->n = nu;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
	{
		(*stack)->prev = new_node;
	}
	*stack = new_node;
}

/**
 * pall - Prints stack values
 * @stack: A pointer to the top of the stack
 * @line_number: Line number in the bytecode file
 * where the pall instruction is encountered.
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	UNUSED(line_number);

	temp = *stack;

	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
