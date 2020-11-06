output: main.o stack.o
	gcc main.o stack.o -o output

main.o: main.c stack.h
	gcc -c main.c -o main.o

stack.o: stack.c stack.h
	gcc -c stack.c -o stack.o

clean:
	rm *.o output
