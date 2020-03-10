objet: main_objet.o objet.o	
	gcc -Wall *.c -o objet.exe

main_objet.o: main_objet.c
	gcc main_objet.c -c
	mv main_objet.o ../../lib

objet.o: objet.c
	gcc objet.c -c 
	mv objet.o ../../lib

clean:
	rm ../../lib/*.o *.exe 