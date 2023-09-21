#include "main.h"

/**
 * length - funct that get the len of the stack.
 *
 * @stack: ptr to ptr that point to the stack.
 *
 * Return: return the intger len.
*/
unsigned int length(stack_t **stack)
{
	stack_t *current;
	unsigned int l = 0;

	for (current = *stack; current != NULL; current = current->next)
	{
		l++;
	}
	return (l);
}
