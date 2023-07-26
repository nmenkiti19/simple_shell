#ifndef _SHELL_H
#define _SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <limits.h>
#include <sys/wait.h>
#include <signal.h>

void check_sig(int sig);
void check_eof(char *temp);
void exit_shell(char **input_cmd);
void handle_exit(void);
void execute_cmd(char **input_cmd, char *shel, char **env, int counter);
char **_getPATH(char **env);
void print_env(char **env);
char **tokenizer(char *temp, const char *delim);
void printerror(char *shel, int counter, char **input_cmd);

unsigned int _strlen(const char *s);
int _strcmp(char *str1, char *str2);
int _strncmp(char *str1, char *str2, size_t n);
char *_strcpy(char *str1, char *str2);
char *_strcat(char *str1, char *str);
int _atoi(char *str);

void start_child(char **input_cmd, char *shel, char **env, int counter);
void free_mem(char **input_cmd);
void free_and_exit(char **input_cmd);
int simple_shell(int argc, char **argv, char **env);
int handle_cd(const char *path);

#endif /*_SHELL_H */
