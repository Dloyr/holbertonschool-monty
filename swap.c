#include "monty.h"

/**
 * swap - swap the top two elements of the stack
 * @stack: pointer to the top of the stack
 * @line_number: line number in the file
 */

void swap(stack_t **stack, unsigned int line_number)
{
	int temp;

	stack_t *node = *stack;
	(void)line_number;

	if (node == NULL || node->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		EXIT_FAILURE;
	}

	temp = node->n;
	node->n = node->next->n;
	node->next->n = temp;
}