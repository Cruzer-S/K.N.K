output: main.o queue_list.o
	gcc -o output  main.o queue.o $(FLAGS)

main.o: main.c queue.h
	gcc -o main.o -c main.c $(FLAGS)

queue.o: queue_list.c queue.h
	gcc -o queue.o -c queue_list.c $(FLAGS)

clean:
	rm *.o output

debug: output
debug: FLAGS += -DDEBUG -g
