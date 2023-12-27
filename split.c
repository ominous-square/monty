#include "monty.h"
/**
 * split_line - splits string into words
 * @line: string
 * Return: array of strings
 */
char **split_line(char *line)
{
	char **token, *string;
	int j;

	token = malloc(sizeof(char *) * 3);
	for (j = 0, string = line; j < 3; j++, string = NULL)
	{
		token[j] = strtok(string, " ");
		if (token[j] == NULL)
			break;
	}

	return (token);

}
