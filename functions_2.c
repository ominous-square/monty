#include "monty.h"
/**
 *op_swap - swaps top two elements of stack
 *@stack: pointer to the head node pointer
 *@line_number: the line number
 *Return: void
 */
void op_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr = *stack;
	int number, count = 0;

	while (ptr)
	{
		ptr = ptr->next;
		count++;
	}
	if (count < 2)
	{
		dprintf(2, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	ptr = *stack;
	number = ptr->n;
	ptr->n = ptr->next->n;
	ptr->next->n = number;
}
/**
 *op_add - Adds top two elements of the stack
 *@stack: pointer to the head node pointer
 *@line_number: the line number
 *Return: void
 */
void op_add(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr = *stack;
	int count = 0;

	while (ptr)
	{
		ptr = ptr->next;
		count++;
	}
	if (count < 2)
	{
		dprintf(2, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	ptr = *stack;
	ptr->next->n = ptr->n + ptr->next->n;
	*stack = ptr->next;
	(*stack)->prev = NULL;
	free(ptr);
}
/**
 * op_sub - subtracts the top element of the stack from the second top
 * @stack: pointer to the head node pointer
 * @line_number: the line number
 * Return: void
 */
void op_sub(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr = *stack;
	int count = 0;

	while (ptr)
	{
		ptr = ptr->next;
		count++;
	}
	if (count < 2)
	{
		dprintf(2, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	ptr = *stack;
	ptr->next->n = ptr->next->n - ptr->n;
	*stack = ptr->next;
	(*stack)->prev = NULL;
	free(ptr);
}
/**
 * op_div - divides the second top element of the stack by the top
 * @stack: pointer to the head node pointer
 * @line_number: the line number
 * Return: void
 */
void op_div(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr = *stack;
	int count = 0;

	while (ptr)
	{
		ptr = ptr->next;
		count++;
	}
	if (count < 2)
	{
		dprintf(2, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	ptr = *stack;
	if (ptr->n == 0)
	{
		dprintf(2, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	ptr->next->n = ptr->next->n / ptr->n;
	*stack = ptr->next;
	(*stack)->prev = NULL;
	free(ptr);
}
/**
 * op_mul - multiplies the second top element of the stack with the top
 * @stack: pointer to the head node pointer
 * @line_number: the line number
 * Return: void
 */
void op_mul(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr = *stack;
	int count = 0;

	while (ptr)
	{
		ptr = ptr->next;
		count++;
	}
	if (count < 2)
	{
		dprintf(2, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	ptr = *stack;
	ptr->next->n = ptr->next->n * ptr->n;
	*stack = ptr->next;
	(*stack)->prev = NULL;
	free(ptr);
}
