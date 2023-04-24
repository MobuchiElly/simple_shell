#ifndef SHELL_H
#define SHELL_H

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
int _strcmp(const char *s1, const char *s2);
size_t _strcspn(const char *s, const char *reject);

#endif
