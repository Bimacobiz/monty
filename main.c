#include "monty.h"

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
	unsigned int line_number = 1;

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
 * @line_number: Line number in the bytecode file
 */
void process_opcode(stack_t **stack, const char *opcode,
		unsigned int line_number)
{
	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{NULL, NULL}
	};

	char trimmed_opcode[100];
	int i;
	stack_t *temp_stack = *stack;

	if (sscanf(opcode, " %99s", trimmed_opcode) != 1)
	{
		fprintf(stderr, "L%d: Failed to parse opcode\n", line_number);
		cleanup_and_exit(*stack, EXIT_FAILURE);
	}

	for (i = 0; instructions[i].opcode != NULL; i++)
	{
		if (strcmp(trimmed_opcode, instructions[i].opcode) == 0)
		{
			instructions[i].f(&temp_stack, line_number);
			return;
		}
	}
	fprintf(stderr, "L%d: Unknown opcode: %s\n", line_number, trimmed_opcode);
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
