inventory: inventory.o readline.o
	gcc -o inventory inventory.o readline.o $(FLAGS)

inventory.o: inventory.c readline.h
	gcc -c inventory.c -o inventory.o $(FLAGS)

readline.o: readline.c readline.h
	gcc -c readline.c -o readline.o $(FLAGS)

clean:
	rm *.o inventory

debug: FLAGS = -g -DDEBUG
debug: inventory
