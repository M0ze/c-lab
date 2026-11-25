# Makefile for wordcount

CC      ?= gcc
CFLAGS  ?= -Wall -Wextra -Werror -O2
SRC     := src/wordcount.c
OBJ_DIR := build
BIN     := $(OBJ_DIR)/wordcount

.PHONY: all clean run

all: $(BIN)

$(BIN): $(SRC) | $(OBJ_DIR)
	$(CC) $(CFLAGS) -o $@ $(SRC)

$(OBJ_DIR):
	mkdir -p $@

clean:
	rm -rf $(OBJ_DIR)

run: $(BIN)
	./$(BIN) wordcount.c
