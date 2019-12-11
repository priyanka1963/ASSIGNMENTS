output: main.o ring.o
	gcc main.o ring.o -o output 

main.o: main.c
	gcc -c main.c

ring.o: ring.c ring.h
	gcc -c ring.c 
 
clean:
	rm *.o output
