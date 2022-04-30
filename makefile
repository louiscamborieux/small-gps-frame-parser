all:
	gcc -o affichage affichage.c frameparser.c

affichage: affichage.o frameparser.o
	gcc -o affichage affichage.o frameparser.o

frameparser.o: frameparser.c frameparser.h
	gcc -c frameparser.c

clean:
	rm affichage && clear
