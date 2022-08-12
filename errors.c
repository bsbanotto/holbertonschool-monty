#include "monty.h"

/**
 * error - Handles error messages and exit
 * @errorCase: Different cases for errors
 * (1) - User did not give valid command
 * (2) - malloc failed
 * (3) - File provided invalid instruction
 * (4) - File could not be open or read
 * (5) - User did not provide in integer to push
 *
 * Return: Void
 */

void error(int errorCase, ...)
{
	va_list ag;
	char *op;
	int linenum;

	va_start(ag, errorCase);
	switch (errorCase)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 3:
			fprintf(stderr, "Error: Can't open file %s\n", va_arg(ag, char *));
			break;
		case 4:
			linenum = va_arg(ag, int);
			op = va_arg(ag, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", linenum, op);
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(ag, int));
			break;
	}
	freeNodes(&head);
	exit(EXIT_FAILURE);
}

/**
 * error2 - Handles additional error messages and exit
 * @errorCase: Different cases for errors
 * (1) - pint error - stack empty
 * (2) - pop error - stack empty
 * (3) - swap error - stack too short
 * (4) - add error - stack too short
 * (5) - sub error - stack too short
 *
 * Return: Void
 */

void error2(int errorCase, ...)
{
	va_list ag;
	int linenum;

	va_start(ag, errorCase);
	switch (errorCase)
	{
		case 1:
			linenum = va_arg(ag, int);
			fprintf(stderr, "L%d: can't pint, stack empty\n", linenum);
			break;
		case 2:
			linenum = va_arg(ag, int);
			fprintf(stderr, "L%d: can't pop an empty stack\n", linenum);
			break;
		case 3:
			linenum = va_arg(ag, int);
			fprintf(stderr, "L%d: can't swap, stack too short\n", linenum);
			break;
		case 4:
			linenum = va_arg(ag, int);
			fprintf(stderr, "L%d: can't add, stack too short\n", linenum);
			break;
		case 5:
			linenum = va_arg(ag, int);
			fprintf(stderr, "L%d: can't sub, stack too short\n", linenum);
			break;
	}
	freeNodes(&head);
	exit(EXIT_FAILURE);
}

/**
 * error3 - Handles more additional error messages and exit
 * @errorCase: Different cases for errors
 * (1) - divide/modulo error - can't divide by zero (0)
 * (2) - divide error - stack too short
 * (3) - multiply error - stack too short
 * (4) - modulo error - stack too short
 *
 * Return: Void
 */

void error3(int errorCase, ...)
{
	va_list ag;
	int linenum;

	va_start(ag, errorCase);
	switch (errorCase)
	{
		case 1:
			linenum = va_arg(ag, int);
			fprintf(stderr, "L%d: division by zero\n", linenum);
			break;
		case 2:
			linenum = va_arg(ag, int);
			fprintf(stderr, "L%d: can't div, stack too short\n", linenum);
			break;
		case 3:
			linenum = va_arg(ag, int);
			fprintf(stderr, "L%d: can't mul, stack too short\n", linenum);
			break;
		case 4:
			linenum = va_arg(ag, int);
			fprintf(stderr, "L%d: can't mod, stack too short\n", linenum);
			break;
	}
	freeNodes(&head);
	exit(EXIT_FAILURE);
}

