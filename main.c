#include "monty.h"
/**
 * check_arguments - checks if arguments are enough
 * @ac: argument count
 * Return: void
 */
void check_arguments(int ac)
{
	if (ac != 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
}
/**
 * open_file - opens monty file
 * @av: argument vector
 * Return: file stream
 */
FILE *open_file(char **av)
{
	FILE *fd;

	fd = fopen(av[1], "r");
	if (fd == NULL)
	{
		dprintf(2, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}

	return (fd);
}
/**
 * main - entry point
 * @ac: argument count
 * @av: argument vector
 * Return: Always 0
 */
int main(int ac, char **av)
{
	FILE *fd;
	size_t n = 0, line_number = 1;
	stack_t *stack = NULL;
	char *lineptr = NULL, **line;
	int length;
	void (*result)(stack_t**, unsigned int);

	check_arguments(ac);
	fd = open_file(av);
	status_stack = 1;

	while ((getline(&lineptr, &n, fd)) != -1)
	{
		length = strlen(lineptr);
		lineptr[length - 1] = '\0';
		line = split_line(lineptr);
		if (*line == NULL || lineptr[0] == '\n' || lineptr[0] == '#')
		{
			free(line);
			line_number++;
			continue;
		}
		result = check_instruction(line[0]);
		value = line[1];
		if (*result == NULL)
		{
			dprintf(2, "L%ld: unknown instruction %s\n", line_number, lineptr);
			exit(EXIT_FAILURE);
		}
		result(&stack, line_number);
		free(line);
		line_number++;
	}
	free_stack(stack);
	free(lineptr);
	fclose(fd);
	return (0);
}
