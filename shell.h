#ifndef SHELL_H
#define SHELL_H

#define MAX_INPUT_SIZE 1024

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>
#include <stddef.h>

int _strlen(const char *s);
size_t _strcspn(const char *s, const char *reject);
char *_getenv(const char *name);
char *_strcat(char *dest, const char *src);
int _strcmp(const char *a, const char *b);
char *_strcpy(char *dest, const char *src);
size_t _strcspn(const char *a, const char *b);
int _strncmp(const char *s1, const char *s2, size_t n);

#endif
