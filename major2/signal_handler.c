#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include "shell.h"
#include <sys/types.h>
#include <bits/waitflags.h>
#include <asm/signal.h>

// Signal handler for child processes
void sigchld_handler(int signo) {
    // Reap terminated child processes
    while (waitpid(-1, NULL, WNOHANG) > 0);
}

// Setup signal handling for the shell
void handle_signals() {
    // Ignore SIGINT (Ctrl+C) and SIGTSTP (Ctrl+Z) for the shell
    signal(SIGINT, SIG_IGN);
    signal(SIGTSTP, SIG_IGN);

    // Handle SIGCHLD to reap child processes
    struct sigaction sa;
    sa.sa_handler = sigchld_handler;
    sa.sa_flags = SA_RESTART | SA_NOCLDSTOP; // Restart interrupted calls, no handling for stopped children
    sigemptyset(&sa.sa_mask);
    if (sigaction(SIGCHLD, &sa, NULL) < 0) {
        perror("sigaction");
    }
}

// Reset signal handling for child processes
void reset_signals_for_child() {
    signal(SIGINT, SIG_DFL);  // Reset SIGINT to default behavior
    signal(SIGTSTP, SIG_DFL); // Reset SIGTSTP to default behavior
}

// Set foreground process group
void set_foreground_process(pid_t pgid) {
    if (tcsetpgrp(STDIN_FILENO, pgid) == -1) {
        perror("tcsetpgrp");
    }
}

// Restore shell as foreground process group
void restore_shell_as_foreground(pid_t shell_pgid) {
    set_foreground_process(shell_pgid);
}
