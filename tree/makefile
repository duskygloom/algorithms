CC		= gcc
ARGS	= -Wall -g
BUILD	= build
BINARY	= tree
OBJECTS	= $(BUILD)/node.o $(BUILD)/binary_tree.o

test: $(BUILD)/test.o $(OBJECTS)
	$(CC) $^ -o $(BINARY) $(ARGS)

$(BUILD)/%.o: %.c
	$(CC) $^ -o $@ -c $(ARGS)

init:
	mkdir -p $(BUILD)

run:
	./$(BINARY)

clean:
	rm $(BUILD)/*.o
