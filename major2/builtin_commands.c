// built in commands for cd, exit, path etc, split between us 4
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
#include "shell.h"

void execute_builtin(const char *command, char **args) {
    if (strcmp(command, "cd") == 0) {
       const char *dir = args[1] ? args[1] : getenv("HOME");
       if (chdir(dir) != 0) {
           perror("cd failed");
       }
    } else if (strcmp(command, "exit") == 0) {
        exit(0);
    } else if (strcmp(command, "path") == 0) {
        //TODO: implement path command
    } else if (strcmp(command, "myhistory") == 0) {
        //TODO: implement history management
    }
}