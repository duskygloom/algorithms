CC		= gcc
ARGS	= -Wall -g
BUILD	= build
BINARY	= app
OBJECTS = $(BUILD)/list.o $(BUILD)/bucket_sort.o

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
