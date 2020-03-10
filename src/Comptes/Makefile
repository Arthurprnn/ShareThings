users: main_users.o users.o	
	gcc -Wall *.c -o users.exe

main_users.o: main_users.c
	gcc main_users.c -c
	mv main_users.o ../../lib

users.o: users.c
	gcc users.c -c 
	mv users.o ../../lib

clean:
	rm ../../lib/main_users.o ../../lib/users.o *.exe 