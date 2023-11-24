CC = gcc
CFLAGS = -Wall -Werror -std=c11
TARGET = start.exe
SRC_DIR = .
OBJ_DIR = obj


# List of all source files
SRC_FILES = $(shell find $(SRC_DIR) -name '*.c' -not -path './Driver/*')
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_FILES))

all: $(TARGET)

$(TARGET): $(OBJ_FILES)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJ_DIR):
	mkdir -p $@

clean:
	rm -rf $(TARGET) $(OBJ_DIR)
