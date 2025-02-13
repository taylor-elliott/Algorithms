# Detect the Operating System
ifeq ($(OS),Windows_NT)
    DEL = del
else
    DEL = rm -f
endif

HEADERS = ./include/*.h
BIN = ./bin
SRC = ./src

OBJECTS = *.o
SOURCES = *.c

EXEC = final

CFLAGS = -Wall -std=c99 -I.${HEADERS}

$(EXEC): $(OBJECTS)
	@gcc $(CFLAGS) $(OBJECTS) -o $(EXEC)

# Rule for compiling .c files to .o files
%.o: %.c
	@gcc $(CFLAGS) -c $<

# Clean up (removes the object files and the executable)
clean:
	@$(DEL) $(OBJECTS) $(EXEC).exe