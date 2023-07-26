#include "shell.h"
/**
 * simple_shell - a function that creates the simple shell
 * @argc: number of arguments
 * @argv: array arguments pointer
 * @env:  enviromental variables pointer
 * Return: 0
 */
int simple_shell(int argc, char **argv, char **env)
{
	char **shell_input = NULL, *temp = NULL;
	size_t temp_bytes = 0;
	ssize_t nchars = 0;
	int counter = 0;

	if (argc > 1)
		*shell_input = argv[1];

	while (1)
	{
		counter++;
		if (!shell_input)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "($) ", 4);
		}
		signal(SIGINT, check_sig);
		nchars = getline(&temp, &temp_bytes, stdin);
		if (nchars && nchars == EOF)
			check_eof(temp);
		else if (*temp == '\n')
			free(temp);
		else
		{
			temp[_strlen(temp) - 1] = '\0';
			shell_input = tokenizer(temp, " \0");
			free(temp);
			if (_strcmp(shell_input[0], "exit") != 0)
				exit_shell(shell_input);
			else if (_strcmp(shell_input[0], "cd") != 0)
				handle_cd(shell_input[1]);
			else
				start_child(shell_input, argv[0], env, counter);
		}
		fflush(stdin);
		temp = NULL, temp_bytes = 0;
	}
	if (nchars == -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

/**
 * check_sig - check signal to handle CtrlD
 * @sig: signal
 * Return: Nothing
 */
void check_sig(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\n($) ", 5);
}

/**
 * check_eof - checks for End of file
 * @temp: input string pointer
 * Return: Nothing
 */
void check_eof(char *temp)
{
	if (temp)
	{
		free(temp);
		temp = NULL;
	}

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "\n", 1);
	free(temp);
	exit(EXIT_SUCCESS);
}


/**
 * exit_shell - Exits the simple shell
 * @shell_input: input command pointer
 * Return: Nothing
 */
void exit_shell(char **shell_input)
{
	int num = 0;

	if (shell_input[1] == NULL)
	{
		free_mem(shell_input);
		exit(EXIT_SUCCESS);
	}

	num = _atoi(shell_input[1]);
	free_mem(shell_input);
	exit(num);
}

