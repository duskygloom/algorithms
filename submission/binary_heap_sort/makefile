CC		= gcc
ARGS	= -Wall -g
BUILD 	= build
BINARY	= app
OBJECTS	= $(BUILD)/heap_sort.o $(BUILD)/heap.o

all: init $(BINARY)

$(BINARY): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(BINARY) $(ARGS)

$(BUILD)/%.o: %.c
	$(CC) $^ -o $@ -c $(ARGS)

init:
	mkdir -p $(BUILD)

clean:
	rm -f $(BUILD)/*.o
	rm -f $(BINARY)
