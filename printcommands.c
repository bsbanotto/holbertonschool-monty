#include "monty.h"

/**
 * pall - Prints the entire stack
 * @stack: Double pointer to top of stack
 * @linenum: Integer value of line in the bytecode file
 *
 * Return: Void
 */

void pall(stack_t **stack, unsigned int linenum)
{
	stack_t *temp;

	(void) linenum;
/*
*	if (stack == NULL)
*		exit(EXIT_FAILURE);
*/
	temp = *stack;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * pint - prints the value at the top of the stack, followed by a new line
 * @stack: Double pointer to top of stack
 * @linenum: Integer value fot eh line in the bytecode file
 *
 * Return: Void
 */

void pint(stack_t **stack, unsigned int linenum)
{
	if (stack == NULL || *stack == NULL)
		error2(1, linenum);
	printf("%d\n", (*stack)->n);
}
