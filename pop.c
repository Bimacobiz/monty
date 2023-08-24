/**
 * pop - removes the top element of the stack
 * @top: points to top of the given stack
 * @line_number: the number of the line which the error occured
 * Return: pointer to the new top
 */
stack_t *pop(stack_t **top, unsigned int line_number)
{
    stack_t *stack_head;

    if (*top == NULL)
    {
        fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
        exit(EXIT_FAILURE);
    }

    stack_head = *top;
    *top = stack_head->next;
    free(stack_head);

    return (*top);
}
