#include "monty.h"

/**
 * push - Adds a node to the stack
 * @newNode: Pointer to added node
 * @linenum: line number in bytecode file
 *
 * Return: Void
 */

void push(stack_t **newNode, __attribute__((unused))unsigned int linenum)
{
	stack_t *temp;

	if (newNode == NULL || *newNode == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head =  *newNode;
		return;
	}
	temp = head;
	head = *newNode;
	head->next = temp;
	temp->prev = head;
}

/**
 * pop - Removes a node from the top of the stack
 * @stack: Double pointer tostack
 * @linenum: line number in bytecode file
 *
 * Return: Void
 */

void pop(stack_t **stack, unsigned int linenum)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL)
	{
		error2(2, linenum);
	}

	temp = *stack;
	*stack = temp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(temp);
}

/**
 * swap - Swaps top two nodes on the top of the stack
 * @stack: Double pointer tostack
 * @linenum: line number in bytecode file
 *
 * Return: Void
 */

void swap(stack_t **stack, unsigned int linenum)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		error2(3, linenum);
	}

	temp = (*stack)->next;
	(*stack)->next = temp->next;
	if (temp->next != NULL)
		temp->next->prev = *stack;
	temp->next = *stack;
	(*stack)->prev = temp;
	temp->prev = NULL;
	*stack = temp;
}

/**
 * add - Adds the top two nodes on the top of the stack
 * @stack: Double pointer tostack
 * @linenum: line number in bytecode file
 *
 * Return: Void
 */

void add(stack_t **stack, unsigned int linenum)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		error2(4, linenum);
	}

	(*stack) = (*stack)->next;
	sum = (*stack)->prev->n + (*stack)->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * nop - Does nothing, nothing at all
 * @stack: Double pointer tostack
 * @linenum: line number in bytecode file
 *
 * Return : Void
 */

void nop(stack_t **stack, unsigned int linenum)
{
	(void)stack;
	(void)linenum;
}
