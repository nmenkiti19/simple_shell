#include "shell.h"
/**
* main - this is the main entry point of the simple shell
* @ac: number of arguments
* @av: array arguments pointer
* @env: enviromental variables pointer
* Return: 0
*/
int main(int ac, char **av, char **env)
{
	simple_shell(ac, av, env);
	return (0);
}

