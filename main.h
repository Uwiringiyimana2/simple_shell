#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

char *get_file_path(char *filename);
char *get_file_loc(char *path, char *filename);
int forward_slash(const char *str);
void handle_exit(char *input, int exit_status);
int exit_shell(char **args, char *input);
void print_env(char **env);
int exec_cmd(char *input, char **args, char **env);
int handle_builtin_cmd(char **args, int argc, char *input, char **env);
void change_dir(char **argv, int argc);
char *_getenv(char *name);
char *_strchr(char *s, char c);

/*tokenization functions*/
size_t tokenize(char *str, char *delim);
char **word_list(char *str, char *delim, ssize_t read);

/*string functions*/
char *_strcpy(char *dest, char *src);
int _strlen(char *s);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strdup(char *str);

#endif
