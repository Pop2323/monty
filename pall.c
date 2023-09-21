#include "main.h"

/**
 * pall - func prints all the values on the stack,
 * starting from the top of the stack.
 *
 * @stack: ptr point to the head
 * @line_number: use __attribute__((unused)) instead
 *
 * Return: return void or nothing
*/
void pall(stack_t **stack, unsigned int __attribute__((unused)) line_number)
{
	if (stack == NULL || *stack == NULL)
		return;

	stack_t *current = *stack;

	for (; current != NULL; current = current->next)
	{
		printf("%d\n", current->n);
	}
}
