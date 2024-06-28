CC		= gcc
ARGS	= -Wall -g
BUILD	= build
BINARY	= app
OBJECTS	= $(BUILD)/matrix.o

all: init multiplication

multiplication: $(OBJECTS) $(BUILD)/matrix_multiplication.o
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
