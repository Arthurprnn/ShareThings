#Objet
CC= gcc
CFLAGS=  -Wall -g 
LIB= ../../lib
LDFLAGS= -lm -lfichier -lobjet -lentrees -lusers -ljson-c -lcrypt
INC= ../../include
EXEC= fichier.exe
SRC= main_fichier.c
OBJ= $(SRC:.c=.o)

all : $(EXEC)

$(EXEC): $(SRC)
	$(CC) $< -o $@ $(CFLAGS) $(LDFLAGS) -I $(INC) -L $(LIB)

clean:
	rm *.exe