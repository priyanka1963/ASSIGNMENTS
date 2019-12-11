final:main.o lib.o
		gcc main.o lib.o -o final

main.o: main.c 
		gcc -Wall -c main.c

lib.o: lib.c lib.h
		gcc -Wall -c lib.c 
clean:
		rm-rf *.o final
