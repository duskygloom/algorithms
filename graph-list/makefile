CC		= gcc
ARGS	= -Wall -g
BUILD	= build
BINARY	= app
OBJECTS	= $(BUILD)/vertex.o $(BUILD)/list.o $(BUILD)/graph.o

all: test

test: $(OBJECTS) $(BUILD)/test.o
	$(CC) $^ -o $(BINARY) $(ARGS)

$(BUILD)/%.o: %.c
	$(CC) $^ -o $@ -c $(ARGS)

init:
	mkdir -p $(BUILD)

clean:
	rm -f $(BUILD)/*.o

run:
	./$(BINARY)
