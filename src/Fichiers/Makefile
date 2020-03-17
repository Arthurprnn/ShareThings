#Objet
CC= gcc
CFLAGS=  -Wall -g 
LIB= ../../lib
LDFLAGS= -lm -lfichier -lobjet -lentrees -ljson-c
INC= ../../include
EXEC= fichier.exe
SRC= main_fichier.c
OBJ= $(SRC:.c=.o)

all : $(EXEC)

$(EXEC): $(SRC)
	$(CC) $< -o $@ $(CFLAGS) $(LDFLAGS) -I $(INC) -L $(LIB)

clean:
	rm *.exe