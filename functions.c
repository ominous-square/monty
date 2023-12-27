#include "monty.h"
/**
 * op_push - adds elements to a stack
 * @stack: pointer to the first node/element in a stack
 * @line_number: the line within the stuck
 * Return: nothing
 */
void op_push(stack_t **stack, unsigned int line_number)
{
	stack_t *new, *ptr = *stack;
	int n;

	n = _atoi(value);
	if (stack == NULL)
	{
		dprintf(2, "L%d: stack not found\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (value == NULL || (n == -1 && value[0] != '-'))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		dprintf(2, "Error: malloc failed\n");
		free(*stack);
		exit(EXIT_FAILURE);
	}
	new->n = n;
	new->next = NULL;
	if (!(*stack))
		*stack = new;
	else if (status_stack)
	{
		new->next = *stack;
		new->prev = NULL;
		(*stack)->prev = new;
		*stack = new;
	}
	else
	{
		while (ptr->next)
			ptr = ptr->next;
		ptr->next = new;
		new->prev = ptr;
	}
}

/**
 *op_pall - prints the data of all nodes in a stack
 *@stack: pointer to the head node pointer
 *@line_number: the line number
 *Return: void
 */
void op_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	(void)line_number;

	temp = *stack;
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 *op_pint -  prints the value at the top of the stack, followed by a new line
 *@stack: pointer to the head node pointer
 *@line_number: the line number
 *Return: void
 */
void op_pint(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	(void)line_number;
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	printf("%d\n", temp->n);
}
/**
 *op_nop - does nothing
 *@stack: pointer to the head node pointer
 *@line_number: the line number
 *Return: void
 */
void op_nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
/**
 *op_pop - does nothing
 *@stack: pointer to the head node pointer
 *@line_number: the line number
 *Return: void
 */
void op_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (temp == NULL)
	{
		dprintf(2, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (temp->next == NULL)
	{
		free(temp);
		*stack = NULL;
	}
	else
	{
		*stack = temp->next;
		temp->next = NULL;
		(*stack)->prev = NULL;
		free(temp);
	}

}
