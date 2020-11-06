output: inventory.o readline.o
	gcc -o output inventory.o readline.o

inventory.o: inventory.c readline.h
	gcc -c inventory.c -o inventory.o

readline.o: readline.c readline.h
	gcc -c readline.c -o readline.o

clean:
	rm *.o output
