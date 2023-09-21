#include "main.h"

/**
 * push - func that pushes an element to the stack.
 *
 * @stack: ptr to ptr to list.
 * @n: char ptr.
 * @line_number: num of line.
 *
 * Return: return void
*/
void push(stack_t **stack, char *n, unsigned int line_number)
{
	stack_t *h = NULL;
	int iter = 0;

	h = malloc(sizeof(stack_t));

	if (h == NULL)
	{
		fprintf(stderr, "Failure: malloc failure\n");
		exit(EXIT_FAILURE);
	}
	if (n == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	for (; n[iter]; iter++)
	{
		if (n[0] == '-' && iter == 0)
			continue;
		if (n[iter] < 48 || n[iter] > 57)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
	}
	h->n = atoi(n);
	h->prev = NULL;
	h->next = NULL;
	if (*stack != NULL)
	{
		h->next = *stack;
		(*stack)->prev = h;
	}
	*stack = h;
}
