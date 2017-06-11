CC      = gcc
CFLAGS  = -c -g -pedantic -Wall
LDFLAGS = 
OBJFILES = BFS.o DFS.o Graph.o Tests.o
SOURCES = 

TARGET  = Tests

all: $(TARGET) 

$(TARGET): $(OBJFILES)
	$(CC) $(OBJFILES) -o $@

.c.o: 
	$(CC) $(CFLAGS) $< -o $@
 
clean:
	rm -rf *.o