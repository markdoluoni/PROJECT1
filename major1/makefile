EXEC = major1
CFLAGS = -Wall -g
SRC = major1.c clz.c endian.c rotate.c parity.c
OBJ = $(SRC:.c=.o)
DEPS = major1.h

all: $(EXEC)

# Link the object files to create the executable
$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ)

# Rule to compile .o files, and specify that .o files depend on major1.h
%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up object files and the executable
clean:
	rm -f $(OBJ) $(EXEC)
