CC		= gcc
ARGS	= -Wall -g
BUILD	= build
BINARY	= graph
OBJECTS	= $(BUILD)/vertex.o $(BUILD)/vertex_list.o $(BUILD)/adjmatrix.o $(BUILD)/graph.o

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
