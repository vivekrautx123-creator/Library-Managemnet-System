CC     = gcc
CFLAGS = -Wall -Wextra -Iinclude
SRC    = src/main.c src/book.c src/member.c src/issue.c
TARGET = library

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)

run: all
	./$(TARGET)
