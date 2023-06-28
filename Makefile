NASM = nasm
CC = clang

NASM_FLAGS = -f macho64
CC_FLAGS = -o

LIBRARY_NAME = libasm.a

SRC_DIR = src
OBJ_DIR = obj
INC_DIR = inc

ASSEMBLY_FILES = $(wildcard $(SRC_DIR)/*.s)
OBJECT_FILES = $(patsubst $(SRC_DIR)/%.s, $(OBJ_DIR)/%.o, $(ASSEMBLY_FILES))

MAIN_FILE = main.c
NAME = main

all: $(LIBRARY_NAME) $(MAIN_FILE:.c=)

test: all
	./$(NAME)

$(LIBRARY_NAME): $(OBJECT_FILES)
	ar rcs $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.s $(INC_DIR)/libasm.h
	$(NASM) $(NASM_FLAGS) $< -o $@

$(MAIN_FILE:.c=): $(MAIN_FILE) $(INC_DIR)/libasm.h
	$(CC) -c $(MAIN_FILE) -o $(MAIN_FILE:.c=.o)
	$(CC) -o $@ $(MAIN_FILE:.c=.o) -L. -lasm

clean:
	rm -f $(OBJECT_FILES) $(LIBRARY_NAME) $(MAIN_FILE:.c=.o) $(MAIN_FILE:.c=)

re: clean all

.PHONY: clean re
