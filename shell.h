#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdbool.h>
#include <stdarg.h>

void executecmd(const char *cmd);
char *custom_getline(void);
char *my_strtok(char *str, const char *delim);
int path(const char *cmd);
int my_strcmp(const char *s1, const char *s2);
void change_directory(const char *path);
char *my_getenv(const char *name);

#endif
