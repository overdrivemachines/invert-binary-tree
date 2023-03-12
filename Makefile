
# Variables to control Makefile operation

CC = g++
CFLAGS = -Wall -g

invert-binary-tree: invert-binary-tree.o
	$(CC) $(CFLAGS) -o invert-binary-tree invert-binary-tree.o

invert-binary-tree.o: invert-binary-tree.cpp
	$(CC) $(CFLAGS) -c invert-binary-tree.cpp

clean:
	rm -rf invert-binary-tree invert-binary-tree.o
