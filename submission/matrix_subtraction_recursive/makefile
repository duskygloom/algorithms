CC		= gcc
ARGS	= -Wall -g
BUILD	= build
BINARY	= app
OBJECTS	= $(BUILD)/matrix.o

all: init subtraction

subtraction: $(OBJECTS) $(BUILD)/matrix_subtraction.o
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
