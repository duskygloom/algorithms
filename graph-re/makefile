CC		= gcc
ARGS	= -Wall -g
BUILD	= build
BINARY	= app
OBJECTS	= $(BUILD)/graph.o $(BUILD)/list.o

test: $(BUILD)/test.o $(OBJECTS)
	$(CC) $^ -o $(BINARY) $(ARGS)

main: $(BUILD)/main.o $(OBJECTS)
	$(CC) $^ -o $(BINARY) $(ARGS)

$(BUILD)/%.o: %.c
	$(CC) $^ -o $@ -c $(ARGS)

init:
	mkdir -p $(BUILD)

run:
	./$(BINARY)

clean:
	rm $(BUILD)/*.o
