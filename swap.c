#include "main.h"

/**
 * swap - swaps the top two elements of the stack.
 *
 * @stack: ptr to ptr to the list.
 * @line_number: num of line
 *
 * Return: return void.
*/
void swap(stack_t **stack, unsigned int line_number)
{
	int head;

	if (length(stack) < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	head = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = head;
}
