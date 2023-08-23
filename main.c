#include "monty.h"
/**
 * main - entry point
 * @arg_count: number of arguments
 * @arg_vec: argument vector
 * Return: 0 on success
 */
int main(int arg_count, char *arg_vec[])
{
	char *k;
	FILE *file;
	char read_bytes[1024];

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
	while (1)
	{
		k = fgets(read_bytes, sizeof(read_bytes), file);
				if (k == NULL)
				{
				break;
				}

				printf("%s", read_bytes);
	}
				fclose(file);
				return (0);
}

