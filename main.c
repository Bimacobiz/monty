#include "monty.h"

<<<<<<< HEAD
instruction_t instructions[] = {
    {"push", push},
    {"pall", pall},
    {NULL, NULL}
};

=======
int main(int arg_count, char *arg_vec[]);
void process_opcode(stack_t **stack, const char *opcode);
void cleanup_and_exit(stack_t *stack, int exit_code);
>>>>>>> 3b69a534796171cf93cee5e1faa3c37d56114be0
/**
 * main - Entry point of the program
 * @arg_count: Number of arguments passed to the program
 * @arg_vec: Array of string arguments passed to the program
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure
 */
int main(int arg_count, char *arg_vec[])
{
	FILE *file;
	stack_t *stack = NULL;
	char opcode[100];
<<<<<<< HEAD
	unsigned int line_number = 1;
=======
	
	while (fgets(opcode, sizeof(opcode), stdin))
	{
        if (opcode[0] == '#')
	{
            continue;
        }
>>>>>>> 3b69a534796171cf93cee5e1faa3c37d56114be0

	if (arg_count != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	file = fopen(arg_vec[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", arg_vec[1]);
		return (EXIT_FAILURE);
	}

	while (fgets(opcode, sizeof(opcode), file) != NULL)
	{
		opcode[strcspn(opcode, "\n")] = '\0';
		process_opcode(&stack, opcode, line_number);
		line_number++;
	}

	fclose(file);

	cleanup_and_exit(stack, EXIT_SUCCESS);

	return (EXIT_SUCCESS);
}

/**
 * process_opcode - Process a single opcode line from the bytecode file
 * @stack: Pointer to the stack
 * @opcode: Opcode string to process
 */
void process_opcode(stack_t **stack, const char *opcode, unsigned int line_number)
{
	char trimmed_opcode[100];
	int i;

	if (sscanf(opcode, " %99s", trimmed_opcode) != 1)
	{
		fprintf(stderr, "Error: Failed to parse opcode\n");
		cleanup_and_exit(*stack, EXIT_FAILURE);
	}

	for (i = 0; instructions[i].opcode != NULL; i++)
	{
		if (strcmp(trimmed_opcode, instructions[i].opcode) == 0)
		{
			stack_t *temp_stack = *stack;
			instructions[i].f(&temp_stack, line_number);
			return;
		}
	}
	fprintf(stderr, "Unknown opcode: %s\n", trimmed_opcode);
	cleanup_and_exit(*stack, EXIT_FAILURE);
}

/**
 * cleanup_and_exit - Clean up resources and exit the program
 * @stack: Pointer to the stack
 * @exit_code: Exit code to be returned
 */
void cleanup_and_exit(stack_t *stack, int exit_code)
{
	while (stack != NULL)
	{
		stack_t *temp = stack;

		stack = stack->next;
		free(temp);
	}

	exit(exit_code);
}
