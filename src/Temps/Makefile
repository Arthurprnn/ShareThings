temps: main_temps.o temps.o	
	gcc -Wall *.c -o temps.exe

main_temps.o: main_temps.c
	gcc main_temps.c -c
	mv main_temps.o ../../lib

temps.o: temps.c
	gcc temps.c -c 
	mv temps.o ../../lib

clean:
	rm ../../lib/main_temps.o ../../lib/temps.o *.exe 