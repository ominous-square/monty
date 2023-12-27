#include "monty.h"

/**
 * free_stack - frees a stack_t list
 * @head: head of linked list
 */

void free_stack(stack_t *head)
{
	stack_t *current;
	stack_t *next;

	current = head;

	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
}
