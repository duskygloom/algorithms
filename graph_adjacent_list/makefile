CC = gcc
ARGS = -Wall -g
BUILD = build
BINARY = app
OBJECTS = $(BUILD)/list.o $(BUILD)/vertex.o $(BUILD)/graph.o

all: init main

main: $(OBJECTS) $(BUILD)/main.o
	$(CC) $^ -o $(BINARY) $(ARGS)

bfs: $(OBJECTS) $(BUILD)/bfs.o
	$(CC) $^ -o $(BINARY) $(ARGS)

dfs: $(OBJECTS) $(BUILD)/dfs.o
	$(CC) $^ -o $(BINARY) $(ARGS)

$(BUILD)/%.o: %.c
	$(CC) $^ -o $@ -c $(ARGS)

init:
	mkdir -p $(BUILD)

run:
	./$(BINARY)

clean:
	rm $(BUILD)/*.o
