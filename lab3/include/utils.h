#ifndef __UTILS_H__
#define __UTILS_H__

#define NULL    0
#define true    1
#define false   0
#define CMDSIZE 32
#define BUFSIZE 256

void printdec(unsigned long value);
void printhex(unsigned long value);
int  atoid(const char *s, unsigned int size);
int  atoih(const char *s, unsigned int size);
int  strcmp(const char *l, const char *r);
int  strncmp(const char *l, const char *r, unsigned int size);
unsigned int strlen(const char *s);
char* strchr(const char *s, int c);
char* strtok(char *str, const char *delim);

#endif