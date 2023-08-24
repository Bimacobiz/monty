#ifndef MONTY_H
#define MONTY_H

#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

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

/**
 * struct instruction_s - struc definition rep an instruction
 * @opcode: the opcode of the instruction
 * @f: pointer to the implementation of the instruction
 * Description: opcode of the function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

int main(int arg_count, char *arg_vec[]);
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void cleanup_and_exit(stack_t *stack, int exit_code);
void process_opcode(stack_t **stack, const char *opcode, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);

#endif /* MONTY_H */
