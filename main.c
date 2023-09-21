#include "main.h"
#include <stdio.h>

/**
 * get_opcode - func that get the opcode.
 *
 * @stack: stack ptr.
 * @opcode: the input opcode.
 * @line_number: the line num.
 *
 * Return: return 1 if success otherwise the error.
*/

int get_opcode(stack_t **stack, char *opcode, int line_number)
{
	instruction_t opcodes[] = {
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{NULL, NULL}
	};
	int i = 0;

	for (; opcodes[i].opcode; i++)
	{
		if (strcmp(opcode, opcodes[i].opcode) == 0)
		{
			(opcodes[i].f)(stack, line_number);
			return (EXIT_SUCCESS);
		}
	}
	fprintf(stderr, "L%d: Failed instruction %s\n", line_number, opcode);
	exit(EXIT_FAILURE);
}

/**
 * main - func that procees the monty
 *
 * @argc: is an integer that indicates how many arguments were entered on.
 * @argv: is an array of pointers to arrays of character objects.
 *
 * Return: return exit success if success otherwise exit failuer
*/
int main(__attribute__((unused)) int argc, char const *argv[])
{
	FILE *file;
	char *buffer = NULL, *opcode, *n;
	int line_number;
	size_t size = 0;
	stack_t *stack = NULL, *current;

	if (argc != 1)
	{
		fprintf(stderr, "Monty: monty\n");
		return (EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: open file is not exist %s\n", argv[1]);
		exit(1);
	}
	while ((getline(&buffer, &size, file)) != -1)
	{
		line_number++;
		opcode = strtok(buffer, DIL);
		if (opcode == NULL || opcode[0] == '#')
			continue;
		if (!strcmp(opcode, "nop"))
			continue;
		else if (!strcmp(opcode, "push"))
		{
			n = strtok(NULL, DIL);
			push(&stack, n, line_number);
		}
		else
			get_opcode(&stack, opcode, line_number);
	}
	fclose(file);
	free(buffer);
	while (stack != NULL)
	{
		current = stack;
		stack = stack->next;
		free(current);
	}
	return (0);
}
/**
 * free_stack - func that free stack memory
 *
 * @stack: stack ptr.
*/
void free_stack(stack_t *stack)
{
	stack_t *next;

	for (; stack != NULL; stack = next)
	{
		next = stack->next;
		free(stack);
	}
}
