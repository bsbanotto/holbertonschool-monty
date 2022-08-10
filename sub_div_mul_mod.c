#include "monty.h"

/**
 * sub - Subtracts top element from the second element of the stack
 * @stack: double pointer to stack
 * @linenum: Integer value for line in bytecode file
 *
 * Return: Void
 */

void sub(stack_t **stack, unsigned int linenum)
{
	int delta;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		error2(5, linenum);
	}

	(*stack) = (*stack)->next;
	delta = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = delta;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * divide - Divides second element by first element in the stack
 * @stack: double pointer to stack
 * @linenum: Integer value for line in bytecode file
 *
 * Return: Void
 */

void divide(stack_t **stack, unsigned int linenum)
{
	int answer;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		error3(2, linenum);
	}

	if ((*stack)->n == 0)
		error3(1, linenum);

	(*stack) = (*stack)->next;
	answer = ((*stack)->n) / ((*stack)->prev->n);
	(*stack)->n = answer;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * multiply - Divides second element by first element in the stack
 * @stack: double pointer to stack
 * @linenum: Integer value for line in bytecode file
 *
 * Return: Void
 */

void multiply(stack_t **stack, unsigned int linenum)
{
	int answer;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		error3(3, linenum);
	}

	(*stack) = (*stack)->next;
	answer = ((*stack)->n) * ((*stack)->prev->n);
	(*stack)->n = answer;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * modulo - Divides second element by first element in the stack
 * @stack: double pointer to stack
 * @linenum: Integer value for line in bytecode file
 *
 * Return: Void
 */

void modulo(stack_t **stack, unsigned int linenum)
{
	int answer;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		error3(4, linenum);
	}

	if ((*stack)->n == 0)
	{
		error3(1, linenum);
	}

	(*stack) = (*stack)->next;
	answer = ((*stack)->n) % ((*stack)->prev->n);
	(*stack)->n = answer;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
