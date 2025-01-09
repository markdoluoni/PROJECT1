//header for shared constants, functions, etc
#ifndef SHELL_H
#define SHELL_H

#define MAX_COMMAND_LENGTH 512
#define MAX_ARGS 128

//Function prototypes
void parse_and_execute(const char *command);
void execute_builtin(const char *command, char **args);
void handle_redirection(char **args);
void handle_pipeline(char **args);
void handle_signals();
void alias_command(const char *command);

#endif