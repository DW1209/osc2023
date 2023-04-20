#include "utils.h"
#include "muart.h"

void printdec(unsigned long value) {
    if (value == 0) {
        mini_uart_puts("0"); return;
    }

    char nums[20]; unsigned int len = 0;

    while (value) {
        unsigned int x = value % 10;
        nums[len++] = '0' + x;
        value /= 10;
    }

    for (int i = len - 1; i >= 0; i--) {
        mini_uart_putc(nums[i]);
    }
}

void printhex(unsigned long value) {
    char nums[9]; nums[8] = '\0';

    for (int i = 7; i >= 0; i--) {
        unsigned int x = value % 16; value >>= 4;
        switch (x) {
            case 10: nums[i] = 'A';     break;
            case 11: nums[i] = 'B';     break;
            case 12: nums[i] = 'C';     break;
            case 13: nums[i] = 'D';     break;
            case 14: nums[i] = 'E';     break;
            case 15: nums[i] = 'F';     break;
            default: nums[i] = '0' + x; break;
        }
    }

    mini_uart_puts("0x");
    mini_uart_puts(nums);
}

int atoid(const char *s, unsigned int size) {
    int num = 0;

    for (unsigned int i = 0; i < size && s[i] != '\0'; i++) {
        if ('0' <= s[i] && s[i] <= '9') {
            num = (10 * num) + (s[i] - '0');
        }
    }

    return num;
}

int atoih(const char *s, unsigned int size) {
    int num = 0;

    for (unsigned int i = 0; i < size && s[i] != '\0'; i++) {
        if ('0' <= s[i] && s[i] <= '9') {
            num = (num * 16) + (s[i] - '0');
        } else if ('A' <= s[i] && s[i] <= 'F') {
            num = (num * 16) + (s[i] - 'A' + 10);
        } else if ('a' <= s[i] && s[i] <= 'f') {
            num = (num * 16) + (s[i] - 'a' + 10);
        }
    }

    return num;
}

int strcmp(const char *l, const char *r) {
    while (*l && (*l == *r)) {
        l++; r++;
    }

    return (const char) *l - (const char) *r;
}

int strncmp(const char *l, const char *r, unsigned int size) {
    for (unsigned int i = 0; i < size; i++) {
        if (l[i] != r[i]) {
            return (const char) l[i] - (const char) r[i];
        }
    }

    return 0;
}

unsigned int strlen(const char *s) {
    unsigned int len = 0;

    while (*s != '\0') {
        len++; s++;
    }

    return len;
}

char* strchr(const char* s, int c) {
    while (*s != '\0') {
        if (*s == c) {
            return (char*) s;
        }
        s++;
    }

    if (c == '\0') {
        return (char*) s;
    }

    return NULL;
}

char* strtok(char *str, const char *delim) {
    int found = false;              // flag to indicate if delimeter is found;
    char *current_token = NULL;     // pointer to current token
    static char *last_token = NULL; // pointer to last token

    // if str is NULL, start searching from the last token
    if (str == NULL) {
        str = last_token;
    }

    // skip leading delimeters
    while (*str && strchr(delim, *str) != NULL) {
        str++;
    }

    // if end of string is reached, return NULL
    if (*str == '\0') {
        last_token = NULL;
        return NULL;
    }

    // search for the end of the token
    current_token = str;
    while (*current_token && !found) {
        if (strchr(delim, *current_token) != NULL) {
            found = true;
        } else {
            current_token++;
        }
    }

    // if end of string is reached, set last_token to NULL
    if (*current_token == '\0') {
        last_token = NULL;
    } else {
        *current_token = '\0';           // NULL-terminate the token
        last_token = current_token + 1; // update last_token to point to the next character
    }

    return str;
}