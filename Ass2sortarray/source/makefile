made: mainsort.o sort.o
	gcc mainsort.o sort.o -o made

mainsort.o: mainsort.c
	gcc -Wall -c mainsort.c

sort.o: sort.c sort.h
	gcc -Wall -c sort.c

clean:
	rm-rf *.o made


