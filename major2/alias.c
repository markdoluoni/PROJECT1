#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "shell.h"

#define MAX_ALIASES 100
#define MAX_ALIAS_NAME 50
#define MAX_ALIAS_CMD 512

typedef struct {
    char name[MAX_ALIAS_NAME];
    char command[MAX_ALIAS_CMD];
} Alias;

static Alias alias_table[MAX_ALIASES];
static int alias_count = 0;

void add_alias(const char *name, const char *command) {
    for (int i = 0; i < alias_count; i++) {
        if (strcmp(alias_table[i].name, name) == 0) {
            strncpy(alias_table[i].command, command, MAX_ALIAS_CMD - 1);
            alias_table[i].command[MAX_ALIAS_CMD - 1] = '\0';
            return;
        }
    }
    if (alias_count < MAX_ALIASES) {
        strncpy(alias_table[alias_count].name, name, MAX_ALIAS_NAME - 1);
        alias_table[alias_count].name[MAX_ALIAS_NAME - 1] = '\0';
        strncpy(alias_table[alias_count].command, command, MAX_ALIAS_CMD - 1);
        alias_table[alias_count].command[MAX_ALIAS_CMD - 1] = '\0';
        alias_count++;
    } else {
        fprintf(stderr, "Error: Alias table is full.\n");
    }
}

void remove_alias(const char *name) {
    for (int i = 0; i < alias_count; i++) {
        if (strcmp(alias_table[i].name, name) == 0) {
            for (int j = i; j < alias_count - 1; j++) {
                alias_table[j] = alias_table[j + 1];
            }
            alias_count--;
            return;
        }
    }
    fprintf(stderr, "Error: Alias '%s' not found.\n", name);
}

void clear_aliases() {
    alias_count = 0;
}

void print_aliases() {
    for (int i = 0; i < alias_count; i++) {
        printf("alias %s='%s'\n", alias_table[i].name, alias_table[i].command);
    }
}

void alias_command(const char *command) {
    char *input = strdup(command);
    if (!input) {
        perror("strdup");
        return;
    }

    char *token = strtok(input, " ");
    token = strtok(NULL, " "); // Skip "alias"

    if (!token) {
        print_aliases(); // No arguments: print all aliases
        free(input);
        return;
    }

    if (strcmp(token, "-r") == 0) { // Remove alias
        char *alias_name = strtok(NULL, " ");
        if (alias_name) {
            remove_alias(alias_name);
        } else {
            fprintf(stderr, "Usage: alias -r <alias_name>\n");
        }
    } else if (strcmp(token, "-c") == 0) { // Clear all aliases
        clear_aliases();
    } else if (strchr(token, '=')) { // Add or update alias
        char *name = strtok(token, "=");
        char *cmd = strtok(NULL, "'");
        if (name && cmd) {
            add_alias(name, cmd);
        } else {
            fprintf(stderr, "Usage: alias alias_name='command'\n");
        }
    } else {
        fprintf(stderr, "Invalid alias command.\n");
    }

    free(input);
}
