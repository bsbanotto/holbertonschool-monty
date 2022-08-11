#ifndef MONTY_H
#define MONTY_H

/* C Libraries */
#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <ctype.h>

/* Data Structures */

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
		int n;
		struct stack_s *prev;
		struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
		char *opcode;
		void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* Extern Variable Declaration */

extern stack_t *head;

/* Typedef for opcode function */

typedef void (*op_func)(stack_t **stack, unsigned int line_number);

/* ---------- Function Prototypes ---------- */

/* Handle Nodes */

stack_t *createNode(int n);
void freeNodes(stack_t **stack);
void push(stack_t **newNode, unsigned int linenum);

/* Execute Commands */

void openOpcode(char *opcode);
void readFile(FILE *fileDescriptor);
int readLine(char *line, int linenum);
void findFunc(char *opcode, char *num, int line);
void runFunc(op_func f, char *opcode, char *num, int line);
void pall(stack_t **stack, unsigned int linenum);
void pint(stack_t **stack, unsigned int linenum);
void pop(stack_t **stack, unsigned int linenum);
void swap(stack_t **stack, unsigned int linenum);
void add(stack_t **stack, unsigned int linenum);
void nop(stack_t **stack, unsigned int linenum);
void sub(stack_t **stack, unsigned int linenum);
void divide(stack_t **stack, unsigned int linenum);
void multiply(stack_t **stack, unsigned int linenum);
void modulo(stack_t **stack, unsigned int linenum);

/* Errors */

void error(int errorCase, ...);
void error2(int errorCase, ...);
void error3(int errorCase, ...);

#endif
