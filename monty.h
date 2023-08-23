#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * struct stack_s - Structure to represent each element in the stack
 * @n: Integer value stored in the node
 * @prev: Pointer to the previous element
 * @next: Pointer to the next element
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;
int main(int arg_count, char *arg_vec[]);
void pall(stack_t *top);
void push(stack_t **top, int val);

#endif /* MONTY_H */
