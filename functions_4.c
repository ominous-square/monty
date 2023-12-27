#include "monty.h"
/**
 * op_rotr - rotates stack to the bottom
 * @stack: pointer to the head node pointer
 * @line_number: the line number
 * Return: void
 */
void op_rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr = *stack, *hld;

	(void)line_number;
	if (ptr && ptr->next)
	{
		hld = ptr;
		while (ptr->next)
			ptr = ptr->next;
		ptr->next = hld;
		hld->prev = ptr;
		ptr->prev->next = NULL;
		ptr->prev = NULL;
		*stack = ptr;
	}
}
/**
 * op_stack - sets format of data to stack(LIFO)
 * @stack: pointer to the head node pointer
 * @line_number: the line number
 * Return: void
 */
void op_stack(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	status_stack = 1;
}
/**
 * op_queue - sets format of data to queue(FIFO)
 * @stack: pointer to the head node pointer
 * @line_number: the line number
 * Return: void
 */
void op_queue(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	status_stack = 0;
}
