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

#endif
