CC		= gcc
ARGS	= -Wall -g
BUILD	= build
BINARY	= app
OBJECTS	= $(BUILD)/matrix.o

addition: $(OBJECTS) $(BUILD)/matrix_addition.o
	$(CC) $^ -o $(BINARY) $(ARGS)

subtraction: $(OBJECTS) $(BUILD)/matrix_subtraction.o
	$(CC) $^ -o $(BINARY) $(ARGS)

multiplication: $(OBJECTS) $(BUILD)/matrix_multiplication.o
	$(CC) $^ -o $(BINARY) $(ARGS)

determinant: $(OBJECTS) $(BUILD)/matrix_determinant.o
	$(CC) $^ -o $(BINARY) $(ARGS)

$(BUILD)/%.o: %.c
	$(CC) $^ -o $@ -c $(ARGS)

init:
	mkdir -p $(BUILD)

run:
	./$(BINARY)

clean:
	rm -f $(BUILD)/*.o
