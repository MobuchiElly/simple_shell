#include "shell.h"

size_t _strcspn(const char *s, const char *reject)
{
    size_t len = 0;
    while (s[len] != '\0') {
        for (size_t i = 0; reject[i] != '\0'; i++) {
            if (s[len] == reject[i]) {
                return len;
            }
        }
        len++;
    }
    return len;
}
