#include "main.h"

/**
 * pint - func prints the value at the top of the stack.
 *
 * @stack: ptr to ptr to the list
 * @line_number: will use __attribute__((unused) instead.
 *
 * Return: return void
*/
void pint(stack_t **stack, unsigned int __attribute__((unused)) line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: stack doesn't exist\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
