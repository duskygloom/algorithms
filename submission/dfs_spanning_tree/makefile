CC = gcc
ARGS = -Wall -g
BUILD = build
BINARY = app
OBJECTS = $(BUILD)/list.o $(BUILD)/vertex.o $(BUILD)/graph.o

all: init dfs

dfs: $(OBJECTS) $(BUILD)/dfs.o
	$(CC) $^ -o $(BINARY) $(ARGS)

$(BUILD)/%.o: %.c
	$(CC) $^ -o $@ -c $(ARGS)

init:
	mkdir -p $(BUILD)

run:
	./$(BINARY)

clean:
	rm -f $(BUILD)/*.o
	rm -f $(BINARY)
