#include "shell.h"

#define BUFF_SIZE 1024

/**
 * _getline - function that reads a line of input from stdin
 *
 * Return: returns line of input read from stdin plus newline character, or
 *         NULL if an error occurs or end-of-file is reached.
 */
char *_getline(void)
{
	static char buffer[BUFF_SIZE];
	static int buff_counter, n_chars;
	char *line = NULL, *temp;
	int line_ind = 0;

	while (1)
	{
		if (buff_counter >= n_chars)
		{
			n_chars = read(STDIN_FILENO, buffer, BUFF_SIZE);
			buff_counter = 0;
			if (n_chars == 0)
				return ((line != NULL) ? (line[line_ind] = '\0', line) : NULL);
			if (n_chars == -1)
				return (NULL);
		}
		while (buff_counter < n_chars)
		{
			if (buffer[buff_counter] == '\n')
				return ((line != NULL) ? (line[line_ind] = '\0', line) : NULL);
			temp = realloc(line, (line_ind + 1) * sizeof(char));
			if (temp == NULL)
			{
				perror("Error: Failed to allocate memory");
				exit(EXIT_FAILURE);
			}
			line = temp;
			line[line_ind++] = buffer[buff_counter++];
			if (line_ind >= BUFF_SIZE)
			{
				temp = realloc(line, (line_ind + 1) * sizeof(char));
				if (temp == NULL)
				{
					perror("Error: Failed to allocate memory");
					exit(EXIT_FAILURE);
				}
				line = temp;
			}
		}
	}
}
