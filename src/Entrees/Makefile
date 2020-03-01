CC= gcc
CFLAGS= -Wall -c
LDFLAGS= -lm
EXEC= prog.exe
OBJECTS= main.o entrees.o

$(EXEC): $(OBJECTS)
	$(CC) -o prog.exe $(OBJECTS) $(LDFLAGS)

main.o : main.c
	$(CC) $(CFLAGS) main.c

entrees.o : entrees.c
	$(CC) $(CFLAGS) entrees.c

clean:
	rm *.exe *.o
