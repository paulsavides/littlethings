REMOVE=rm -rf
OBJ_DIR=bin
PROG_NAME=jarvis
MKDIR=mkdir -p

# compiler
CC=gcc

# flags
CFLAGS=-std=c99

all: clean directory program

clean:
	$(REMOVE) $(OBJ_DIR)

directory:
	$(MKDIR) $(OBJ_DIR)

program:
	$(CC) $(CFLAGS) $(PROG_NAME).c $(PROG_NAME).h -o $(OBJ_DIR)/$(PROG_NAME)
	cp $(PROG_NAME).conf $(OBJ_DIR) 
