// entry point for shell program
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "shell.h"

#define PROMPT "newshell> "

int main(int argc, char *argv[]) {
    if(argc > 2) {
        fprintf(stderr, "Usage: %s [batch_file]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    FILE *input = (argc == 2) ? fopen(argv[1], "r") : stdin;
    if (!input) {
        perror("Error opening batch file");
        exit(EXIT_FAILURE);
    }

    char command[MAX_COMMAND_LENGTH];
    while (1) {
        if(input == stdin) {
            printf(PROMPT);
        }
        if(!fgets(command, MAX_COMMAND_LENGTH, input)) {
            break;
        }

        //parse and execute command
        parse_and_execute(command);

    }
    if(input != stdin) {
        fclose(input);
    }
    return 0;
}

