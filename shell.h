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
#include <malloc.h>

void executecmd(const char *cmd);
ssize_t custom_getline(char **lineptr, size_t *n);
char *my_strtok(char *str, const char *delim);
int path(const char *cmd);
int my_strcmp(const char *s1, const char *s2);
void change_directory(const char *path);
char *my_getenv(const char *name);
bool logicalAnd(bool a, bool b);
bool logicalOr(bool a, bool b);
int my_printf(const char *format, ...);
int my_snprintf(char *str, size_t size, const char *format, ...);
int my_atoi(const char *str);
size_t my_strlen(const char *s);
bool logicalAnd(bool a, bool b);
int my_strncmp(const char *s1, const char *s2, size_t n);
bool logicalOr(bool a, bool b);
char *my_strchr(const char *s, int c);
char *my_strcpy(char *des, const char *src);
void printEnvironment(void);
void set_env(const char *var, const char *val);
void unset_env(const char *var);
extern char **environ;
void free_memory(char *lineptr);
void *my_realloc(void *ptr, size_t size);

#endif
