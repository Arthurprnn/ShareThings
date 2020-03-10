prets: main_prets.o prets.o	temps.o users.o objet.o 
	gcc -Wall *.c -o prets.exe

main_prets.o: main_prets.c
	gcc main_prets.c -c
	mv main_prets.o ../../lib

prets.o: prets.c
	gcc prets.c -c 
	mv prets.o ../../lib

users.o: ../Comptes/users.c
	gcc users.c -c 
	mv users.o ../../lib

objet.o: ../Objets/objet.c
	gcc objet.c -c 
	mv objet.o ../../lib

temps.o: ../Temps/temps.c
	gcc temps.c -c 
	mv temps.o ../../lib