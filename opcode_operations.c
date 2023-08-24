#include "monty.h"
/**
* push - adds an element onto the stack
* @top: A pointer to a pointer to the top of the stack.
* @val: interger value to be pushed to the stack
*/
void push(stack_t **top, int val)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failure\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = val;
	new_node->prev = NULL;
	new_node->next = *top;

	if (*top != NULL)
	{
		(*top)->prev = new_node;
	}
	*top = new_node;
}

/**
* pall - Prints stack values
* @top: A pointer to the top of the stack.
*/
void pall(stack_t *top)
{
	while (top != NULL)
	{
		printf("%d\n", top->n);
		top = top->next;
	}
}
