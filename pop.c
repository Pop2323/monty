#include "main.h"

/**
 * pop - removes the top element of the stack.
 *
 * @stack: ptr to ptr to the list.
 * @line_number: num of line
 *
 * Return: return void
*/
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *lo;

	if (stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	else if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		lo = *stack;
		*stack = (*stack)->next;
		free(lo);
	}
	return;
}
