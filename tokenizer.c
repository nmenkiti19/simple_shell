#include "shell.h"

/**
 * tokenizer - function that tokenizes the input
 * @delim: delimiter
 * @temp: input pointer
 * Return: returns the input
 */
char **tokenizer(char *temp, const char *delim)
{
	char *token_str = NULL, **shell_input = NULL;
	size_t temp_size = 0;
	int i = 0;

	if (temp == NULL)
		return (NULL);

	temp_size = _strlen(temp);
	shell_input = malloc((temp_size + 1) * sizeof(char *));
	if (shell_input == NULL)
	{
		perror("Unable to allocate temp");
		free(temp);
		free_mem(shell_input);
		exit(EXIT_FAILURE);
	}

	token_str = strtok(temp, delim);
	while (token_str != NULL)
	{
		shell_input[i] = malloc(_strlen(token_str) + 1);
		if (shell_input[i] == NULL)
		{
			perror("Problem allocating memory");
			free_mem(shell_input);
			return (NULL);
		}
		_strcpy(shell_input[i], token_str);
		token_str = strtok(NULL, delim);
		i++;
	}
	shell_input[i] = NULL;
	return (shell_input);
}

/**
 * printerror - function that handles printing error message
 * @shell_p: shell pointer
 * @counter: executed counter
 * @shell_input: tokenized input pointer
 * Return: Nothing
 */
void printerror(char *shell_p, int counter, char **shell_input)
{
	char tmp;

	tmp = counter + '0';
	write(STDOUT_FILENO, shell_p, _strlen(shell_p));
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, &tmp, 1);
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, shell_input[0], _strlen(shell_input[0]));
	write(STDOUT_FILENO, ": not found\n", 12);
}
