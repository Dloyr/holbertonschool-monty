#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - reading opcodes from a file
 * @argc: argument count
 * @argv: argument values
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure
 */
int main(int argc, char *argv[])
{
	FILE *file;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <file>\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((read = getline(&line, &len, file)) != -1)
	{
		char *opcode = strtok(line, " \n\t");
		if (opcode == NULL)
			continue;
		if (strcmp(opcode, "push") == 0)
			push(&stack, 0);
		else if (strcmp(opcode, "pall") == 0)
			pall(&stack, 0);
		else if (strcmp(opcode, "pop") == 0)
			pop(&stack, 0);
		else if (strcmp(opcode, "pint") == 0)
			pint(&stack, 0);
		else if (strcmp(opcode, "swap") == 0)
			swap(&stack, 0);
		else if (strcmp(opcode, "add") == 0)
			add(&stack, 0);
	}
	fclose(file);
	free(line);
	return (EXIT_SUCCESS);
}
