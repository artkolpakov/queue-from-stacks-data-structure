CC=gcc --std=c99 -g

all: test_queue_from_stacks

test_queue_from_stacks: test_queue_from_stacks.c queue_from_stacks.o stack.o list.o
	$(CC) test_queue_from_stacks.c queue_from_stacks.o stack.o list.o -o test_queue_from_stacks

list.o: list.c list.h
	$(CC) -c list.c

stack.o: stack.c stack.h
	$(CC) -c stack.c

queue_from_stacks.o: queue_from_stacks.c queue_from_stacks.h
	$(CC) -c queue_from_stacks.c

clean:
	rm -f *.o test_stack test_queue test_queue_from_stacks palindrome
