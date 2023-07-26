#include "shell.h"

/**
 * start_child - function that creates child process
 * @shell_input: input command pointer
 * @shell_p:  the shell pointer
 * @env: enviromental variables pointer
 * @counter: counter
 * Return: Nothing
 */
void start_child(char **shell_input, char *shell_p, char **env, int counter)
{
	int pid = 0;
	int status = 0;
	int werror = 0;

	pid = fork();
	if (pid < 0)
	{
		perror("Error occured: ");
		free_and_exit(shell_input);
	}
	else if (pid == 0)
	{
		execute_cmd(shell_input, shell_p, env, counter);
		free_mem(shell_input);
	}
	else
	{
		werror = waitpid(pid, &status, 0);
		if (werror < 0)
		{
			free_and_exit(shell_input);
		}
		free_mem(shell_input);
	}
}

/**
 * free_mem - frees memory allocated for input command
 * @shell_input: allocated memory pointer
 * Return: Nothing
 */
void free_mem(char **shell_input)
{
	size_t i = 0;

	if (shell_input == NULL)
		return;

	while (shell_input[i])
	{
		free(shell_input[i]);
		i++;
	}

	if (shell_input[i] == NULL)
		free(shell_input[i]);
	free(shell_input);
}


/**
 * free_and_exit - frees memory allocated and exits
 * @shell_input: allocated memory pointer
 * Return: Nothing
 */
void free_and_exit(char **shell_input)
{
	free_mem(shell_input);
	exit(EXIT_FAILURE);
}
