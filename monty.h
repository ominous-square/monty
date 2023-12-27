#ifndef MAIN_H
#define MAIN_H

#define _POSIX_C_SOURCE  200809L
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

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
char *value;
int status_stack;
char **split_line(char *line);
void (*check_instruction(char *s))(stack_t**, unsigned int);
void op_push(stack_t **stack, unsigned int line_number);
void op_pall(stack_t **stack, unsigned int line_number);
void op_pint(stack_t **stack, unsigned int line_number);
void op_pop(stack_t **stack, unsigned int line_number);
void op_nop(stack_t **stack, unsigned int line_number);
void op_swap(stack_t **stack, unsigned int line_number);
void free_stack(stack_t *head);
int _atoi(char *s);
void op_add(stack_t **stack, unsigned int line_number);
void op_mul(stack_t **stack, unsigned int line_number);
void op_sub(stack_t **stack, unsigned int line_number);
void op_mod(stack_t **stack, unsigned int line_number);
void op_div(stack_t **stack, unsigned int line_number);
void op_pchar(stack_t **stack, unsigned int line_number);
void op_pstr(stack_t **stack, unsigned int line_number);
void op_comment(stack_t **stack, unsigned int line_number);
void op_rotl(stack_t **stack, unsigned int line_number);
void op_rotr(stack_t **stack, unsigned int line_number);
void op_stack(stack_t **stack, unsigned int line_number);
void op_queue(stack_t **stack, unsigned int line_number);
#endif
