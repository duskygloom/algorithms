CC		= gcc
ARGS	= -Wall -g
BUILD	= build
BINARY	= app
OBJECTS = $(BUILD)/binary_tree.o $(BUILD)/main.o

all: init $(OBJECTS)
	$(CC) $(OBJECTS) -o $(BINARY) $(ARGS)

$(BUILD)/%.o: %.c
	$(CC) $^ -o $@ $(ARGS) -c

init:
	mkdir -p $(BUILD)

run:
	./$(BINARY)

clean:
	rm -f $(BUILD)/*.o
	rm -f $(BINARY)
