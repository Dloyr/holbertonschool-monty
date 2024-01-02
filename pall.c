#include "monty.h"

/**
 * pall - prints all the values on the stack
 * @stack: pointer to the top of the stack
 * @line_number: line number in the file
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *node = *stack;
	(void)line_number;

	if (node == NULL)
	{
		fprintf(stderr, "L%d: can't pall, stack empty\n", line_number);
		EXIT_FAILURE;
	}

	while (node != NULL)
	{
		printf("%d\n", node->n);
		node = node->next;
	}
}
