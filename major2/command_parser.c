//funcctions to parse command line and manage arguments
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"

void parse_and_execute(const char *command) {
    // Tokenize ocmmand line
    char *args[MAX_ARGS];
    char *token = strtok(command, " \t\n");
    int i =0;

    while(token && i < MAX_ARGS -1) {
        args[i++] = token;
        token = strtok(NULL, " \t\n");
    }
    args[i] = NULL;
    
    if (args[0] == NULL) { 
        return;
    }

    //check for built-in commands
    if (strcmp(args[0], "cd") == 0 || strcmp(args[0], "exit") == 0 || strcmp(args[0], "path") == 0 || strcmp(args[0], "myhistory") == 0) {
    execute_builtin(args[0], args);
    }else{
        // Handle non built-in commands
        pid_t pid = fork();
        if (pid == 0) {
            execvp(args[0], args);
            perror("Command execution failed");
            exit(EXIT_FAILURE);
        } else if (pid > 0) {
            wait(NULL);
        } else {
            perror("Fork failed");
        }
    }
    
       
    }

