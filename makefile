all : tp6 clean

tp6 : fonctions.o main.o fonctions.h
	gcc fonctions.o main.o -o tp6

fonctions.o : fonctions.c fonctions.h 
	gcc -c fonctions.c -o fonctions.o

main.o : main.c fonctions.h
	gcc -c main.c -o main.o

.PHONY : clean 
clean :
	rm fonctions.o main.o
