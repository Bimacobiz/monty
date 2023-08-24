#include "monty.h"
/**
 * main - entry point
 * @arg_count: number of arguments
 * @arg_vec: argument vector
 * Return: 0 on success
 */
int main(int arg_count, char *arg_vec[])
{
	FILE *file;
	stack_t *stack = NULL;
	char opcode[100];
	int value;
	char *trimmed_opcode = opcode;

	if (arg_count != 2)
	{
		fprintf(stderr, "USAGE: %s file\n", arg_vec[0]);
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

		  while (*trimmed_opcode == ' ') trimmed_opcode++;

		 if (sscanf(trimmed_opcode, "push %d", &value) == 1)
		{
			push(&stack, value);
		}
		else if (strcmp(trimmed_opcode, "pall") == 0)
		{
			pall(stack);
		}
		else
		{
			fprintf(stderr, "Unknown opcode: %s\n", trimmed_opcode);
			fclose(file);
			return (EXIT_FAILURE);
		}
	}
	fclose(file);
	return (0);
}
