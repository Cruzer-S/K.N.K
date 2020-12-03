FLAGS = -std=c99

justify: justify.o word.o line.o
	gcc -o justify justify.o word.o line.o $(FLAGS)

justify.o: justify.c word.h line.h
	gcc -c justify.c -o justify.o $(FLAGS)

word.o: word.c word.h
	gcc -c word.c -o word.o $(FLAGS)

line.o: line.c line.h
	gcc -c line.c $(FLAGS)

debug: justify
debug: FLAGS += -DDEBUG

clean:
	rm *.o justify
