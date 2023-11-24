CC = gcc
CFLAGS = -Wall -Werror -std=c11
TARGET = start.exe
SRC_DIR = .
OBJ_DIR = obj

# List of all source files
SRC_FILES = $(shell find $(SRC_DIR) -name '*.c' -not -path './Driver/*')
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_FILES))

# List of driver source files
DRIVER_SRC_FILES = $(filter-out $(SRC_DIR)/main.c, $(wildcard $(SRC_DIR)/Driver/*.c))
DRIVER_OBJ_FILES = $(patsubst $(SRC_DIR)/Driver/%.c,$(OBJ_DIR)/Driver/%.o,$(DRIVER_SRC_FILES))

all: $(TARGET)

$(TARGET): $(OBJ_FILES)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJ_DIR):
	mkdir -p $@

clean:
	rm -rf $(TARGET) $(OBJ_DIR) driver_load

driver_load: $(filter-out $(OBJ_DIR)/main.o, $(OBJ_FILES)) $(OBJ_DIR)/Driver/driver_load.o
	$(CC) $(CFLAGS) -o driver_load $^
	./driver_load

driver_kicauan: $(filter-out $(OBJ_DIR)/main.o $(DRIVER_OBJ_FILES), $(OBJ_FILES)) $(OBJ_DIR)/Driver/driver_kicauan.o
	$(CC) $(CFLAGS) -o driver_kicauan $^
	./driver_kicauan

# Pattern rule for compiling driver files
$(OBJ_DIR)/Driver/%.o: $(SRC_DIR)/Driver/%.c | $(OBJ_DIR)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c -o $@ $<
