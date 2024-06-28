CC		= gcc
BUILD 	= build
BINARY	= app
SOURCES	= $(BUILD)/main.o $(BUILD)/heap.o

all: init $(BINARY)

$(BINARY): $(SOURCES)
	$(CC) $(SOURCES) -o $(BINARY) -g

$(BUILD)/%.o: %.c
	$(CC) $^ -o $@ -c -g

init:
	mkdir -p $(BUILD)

clean:
	rm $(BUILD)/*.o
