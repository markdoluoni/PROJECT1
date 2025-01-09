CC = gcc
CFLAGS = -Wall -g
OBJS = main.o command_parser.o builtin_commands.o redirection.o pipelining.o signal_handler.o alias.o 

newshell: $(OBJS)
	$(CC) $(CFLAGS) -o newshell $(OBJS)

clean:
	rm -f *.o newshell