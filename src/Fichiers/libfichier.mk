CC= gcc
CFLAGS=  -Wall -g #-std=c11
LIB= ../../lib
LDFLAGS= -lm 
INC= ../../include
EXEC= libfichier.a
SRC= fichier.c
OBJ= $(SRC:.c=.o)

all : $(EXEC)

fichier.o : fichier.c 
	@ $(CC) $(CFLAGS)  -c fichier.c -I $(INC)

$(EXEC) : $(OBJ) $(INC)/fichier.h
	@ ar rcs $(LIB)/libfichier.a $(OBJ)
	@ ranlib $(LIB)/libfichier.a

clean:
	@ rm $(LIB)/libfichier.a fichier.o