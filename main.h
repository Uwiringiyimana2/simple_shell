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
int handle_builtin_cmd(char **args, char *input, char **env);
void print_env(char **env);
int exec_cmd(char **args, char **env);

#endif
