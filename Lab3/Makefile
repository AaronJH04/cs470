# Compiler and flags
CC = gcc
CFLAGS = -Wall -O2

# Default target: build and run both
all: SJF_initial_output RR_initial_output

# Compile and run SJF_initial
SJF_initial_output: SJF_initial.c
	$(CC) $(CFLAGS) -o SJF_initial SJF_initial.c -mconsole
	@echo "=== Running SJF_initial ==="
	@./SJF_initial

# Compile and run RR_initial
RR_initial_output: RR_initial.c
	$(CC) $(CFLAGS) -o RR_initial RR_initial.c -mconsole
	@echo "=== Running RR_initial ==="
	@./RR_initial

# Clean build files
clean:
	@rm -f SJF_initial RR_initial
