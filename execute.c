#include "shell.h"

/**
 * execute_cmd - function that executes command
 * @shell_input: tokenized command pointer
 * @shell_p: shell pointer
 * @env: enviromental variables pointer
 * @counter: execute counter
 * Return: Nothing
 */
void execute_cmd(char **shell_input, char *shell_p, char **env, int counter)
{
	char **shell_path = NULL, *conc_path = NULL;
	struct stat stru;
	unsigned int i = 0;

	if (_strcmp(shell_input[0], "env") != 0)
		print_env(env);
	if (stat(shell_input[0], &stru) == 0)
	{
		if (execve(shell_input[0], shell_input, env) < 0)
		{
			perror(shell_p);
			free_and_exit(shell_input);
		}
	}
	else
	{
		shell_path = _getPATH(env);
		while (shell_path[i])
		{
			conc_path = _strcat(shell_path[i], shell_input[0]);
			i++;
			if (stat(conc_path, &stru) == 0)
			{
				if (execve(conc_path, shell_input, env) < 0)
				{
					perror(shell_p);
					free_mem(shell_path);
					free_and_exit(shell_input);
				}
				return;
			}
		}
		printerror(shell_p, counter, shell_input);
		free_mem(shell_path);
	}
}

/**
 * _getPATH - Gets path from the
 * enviromental variable PATH
 * @env: enviromental variables pointer
 * Return: tokenized paths
 */
char **_getPATH(char **env)
{
	char *fpath = NULL, **shell_path = NULL;
	unsigned int i = 0;

	fpath = strtok(env[i], "=");
	while (env[i])
	{
		if (_strcmp(fpath, "PATH"))
		{
			fpath = strtok(NULL, "\n");
			shell_path = tokenizer(fpath, ":");

			return (shell_path);
		}
		i++;
		fpath = strtok(env[i], "=");
	}
	return (NULL);
}

/**
 * print_env - Prints all enviromental variables
 * @env: enviromental variables pointer
 * Return: Nothing.
 */
void print_env(char **env)
{
	size_t i = 0, evlen = 0;

	while (env[i])
	{
		evlen = _strlen(env[i]);
		write(STDOUT_FILENO, env[i], evlen);
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}

/**
 * handle_cd - Changes working directory
 * @path: current working directory
 * Return: 0 for success
 * else -1
 */
int handle_cd(const char *path)
{
	char *temp = NULL;
	size_t temp_size = 1024;


	if (path == NULL)
		path = getcwd(temp, temp_size);
	if (chdir(path) == -1)
	{
		perror(path);
		return (98);
	}
	write(STDOUT_FILENO, path, 40);
	write(STDOUT_FILENO, "($) ", 4);
	return (1);
}
