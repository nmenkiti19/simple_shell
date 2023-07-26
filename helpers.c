#include "shell.h"

/**
 * _strlen - Returns the lenght of a string.
 * @s: Type char pointer
 * Return: String length
 */
unsigned int _strlen(const char *s)
{
	unsigned int len;

	for (len = 0; s[len] != 0; len++)
	{
	}
	return (len);
}

/**
 * _strcmp - Compares two strings
 *  @str1: string 1
 *  @str2: string 2
 *  Return: 1 if strings are the same
 *  else 0
 */
int _strcmp(char *str1, char *str2)
{
	unsigned int i = 0;


	while (str1[i])
	{
		if (str1[i] != str2[i])
			return (0);
		i++;
	}
	return (1);
}

/**
 * _strcpy - Copies a string to another string
 * @str1: copied string pointer
 * @str2: pointer to string to copy from
 * Return: copied string pointer
 */
char *_strcpy(char *str1, char *str2)
{
	char *cop = str1;

	while (*str2)
		*str1++ = *str2++;
	*str1 = '\0';
	return (cop);
}

/**
* _strcat - Concatenates 2 strings
* @str1: an input string
* @str: an input string
* Return: A pointer to the resulting string
*/
char *_strcat(char *str1, char *str)
{
	char *conc = str1;

	while (*str1)
		str1++;
	*str1++ = '/';
	while (*str)
		*str1++ = *str++;
	return (conc);
}

/**
 * _atoi - Converts string to integer
 * @str: string pointer
 * Return: converted integer
 */
int _atoi(char *str)
{
	int sign = 1;
	unsigned int num = 0;
	char nullstr = 0;

	if (str == NULL)
		return (0);
	while (*str)
	{
		if (*str == '-')
			sign *= -1;
		if (*str >= '0' && *str <= '9')
		{
			nullstr = 1;
			num = num * 10 + (*str - '0');
		}
		else if (*str < '0' || *str > '9')
		{
			if (nullstr == 1)
				break;
		}
		str++;
	}
	if (sign < 0)
		num = (-1 * (num));
	return (num);
}

