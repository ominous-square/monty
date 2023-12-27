#include "monty.h"
/**
 * check_instruction - checks if command is valid
 * @s: instruction
 * Return: function
 */
void (*check_instruction(char *s))(stack_t**, unsigned int)
{
	int i = 0;
	instruction_t ops[] = {
		{"push", op_push},
		{"pall", op_pall},
		{"pint", op_pint},
		{"nop", op_nop},
		{"pop", op_pop},
		{"swap", op_swap},
		{"add", op_add},
		{"sub", op_sub},
		{"div", op_div},
		{"mul", op_mul},
		{"mod", op_mod},
		{"pchar", op_pchar},
		{"pstr", op_pstr},
		{"#", op_comment},
		{"rotl", op_rotl},
		{"rotr", op_rotr},
		{"stack", op_stack},
		{"queue", op_queue},
		{NULL, NULL}
	};

	while (ops[i].opcode)
	{
		if (!strcmp(ops[i].opcode, s))
			return (ops[i].f);
		i++;
	}
	return (NULL);
}
