#include "monty.h"

stack_t *head = NULL;

/**
 * main - Main function for ac *av[]
 * @ac: ArgCount - Count of arguments passed
 * @av: ArgValues - Array of arguments
 *
 * Return: Zero on success
 */

int main(int ac, char *av[])
{
	if (ac != 2)
		error(1);

	openOpcode(av[1]);
	freeNodes(&head);
	return (0);
}

/**
 * createNode - Creates and populates a node
 * @n: Number to be stored in the node
 *
 * Return: Pointer to node when successful, or NULL on failure
 */

stack_t *createNode(int n)
{
	stack_t *newNode;

	newNode = malloc(sizeof(stack_t));
	if (newNode == NULL)
		error(2);
	newNode->next = NULL;
	newNode->prev = NULL;
	newNode->n = n;
	return (newNode);
}

/**
 * freeNodes - Free nodes in stack
 * @stack: double pointer to stack of nodes
 */

void freeNodes(stack_t **stack)
{
	if (stack == NULL || *stack == NULL)
	{
		return;
	}

	freeNodes(&((*stack)->next));
	free(*stack);
	*stack = NULL;
}
