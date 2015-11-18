OBJET = jeu_2048.o interface_2048.o fonctions_2048.o
CC = gcc

jeu_2048_curse : jeu_2048_curse.o interface_2048_curse.o fonctions_2048.o
	gcc -o jeu_2048_curse jeu_2048_curse.o interface_2048_curse.o fonctions_2048.o -lncurses
jeu_2048 : jeu_2048.o interface_2048.o fonctions_2048.o
	gcc -o jeu_2048 jeu_2048.o interface_2048.o fonctions_2048.o
jeu_2048.o : jeu_2048.c constante.h
	gcc -c -Wall jeu_2048.c
jeu_2048_curse.o : jeu_2048_curse.c constante.h
	gcc -c -Wall jeu_2048_curse.c
interface_2048.o : interface_2048.c constante.h
	gcc -c -Wall interface_2048.c 
interface_2048_curse.o : interface_2048_curse.c constante.h
	gcc -c -Wall interface_2048_curse.c 
fonctions_2048.o : fonctions_2048.c constante.h
	gcc -c -Wall fonctions_2048.c
clean : 
	rm *.o