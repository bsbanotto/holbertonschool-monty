#include "monty.h"

/**
 * openOpcode - Opens file associated with Opcode
 * @opcode: opcode string from bytecode file
 *
 * Return: Void
 */

void openOpcode(char *opcode)
{
	int verify;
	FILE *fileDescriptor;

	if (opcode == NULL)
		error(3, opcode);

	verify = access(opcode, R_OK);

	if (verify == -1)
		error(3, opcode);

	fileDescriptor = fopen(opcode, "r");

	if (fileDescriptor == NULL)
		error(3, opcode);

	readFile(fileDescriptor);

	fclose(fileDescriptor);
}

/**
 * readFile - Reads the bytecode file one line at a time
 * @fileDescriptor: pointer to fileDescriptor
 *
 * Return: Void
 */

void readFile(FILE *fileDescriptor)
{
	int linenum;
	char *line;
	size_t i;

	line = NULL;
	i = 0;

	if (fileDescriptor == NULL)
		error(3, "opcode");

	for (linenum = 1; getline(&line, &i, fileDescriptor) != EOF; linenum++)
	{
		readLine(line, linenum);
	}
	free(line);
}

/**
 * readLine - Tokenizes line to find function
 * @line: string line from bytecode file
 * @linenum: line number in bytedcode file
 *
 * Return: 0 on success
 */

int readLine(char *line, int linenum)
{
	char *opcode;
	char *value;

	if (line == NULL)
		error(2);

	opcode = strtok(line, " \t\n\a");

	if (opcode == NULL)
		return (0);

	value = strtok(NULL, " \t\a\n");

	findFunc(opcode, value, linenum);
	return (0);
}

/**
 * findFunc - Finds function that coresponds to opcode
 * @opcode: opcode from bytecode file
 * @num: number passed in to operation(only push)
 * @line: Line number in bytecode file
 *
 * Return: Void
 */

void findFunc(char *opcode, char *num, int line)
{
	int i, errorFlag;

	instruction_t funcList[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", divide},
		{"mul", multiply},
		{"mod", modulo},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (errorFlag = 1, i = 0; funcList[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, funcList[i].opcode) == 0)
		{
			runFunc(funcList[i].f, opcode, num, line);
			errorFlag = 0;
		}
	}
	if (errorFlag == 1)
		error(4, line, opcode);
}

/**
 * runFunc - Calls and executes function
 * @f: pointer to function that is called
 * @opcode: opcode string
 * @num: String for numeric value to be used in function
 * @line: Current line number of bytecode file
 *
 * Return: Void
 */

void runFunc(op_func f, char *opcode, char *num, int line)
{
	stack_t *newNode;
	int flag;
	int i;

	flag = 1;
	if (strcmp(opcode, "push") == 0)
	{
		if (num != NULL && num[0] == '-')
		{
			num = num + 1;
			flag = -1;
		}

		if (num == NULL)
			error(5, line);

		for (i = 0; num[i] != '\0'; i++)
		{
			if (isdigit(num[i]) == 0)
				error(5, line);
		}
		newNode = createNode(atoi(num) * flag);
		f(&newNode, line);
	}
	else
		f(&head, line);
}
