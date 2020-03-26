CC= gcc
CFLAGS=  -Wall -g #-std=c11
LIB= ../../lib
LDFLAGS= -lm 
INC= ../../include
EXEC= libobjet.a
SRC= objet.c
OBJ= $(SRC:.c=.o)

all : $(EXEC)

objet.o : objet.c 
	@ $(CC) $(CFLAGS)  -c objet.c -I $(INC)

$(EXEC) : $(OBJ) $(INC)/objet.h
	@ ar rcs $(LIB)/libobjet.a $(OBJ)
	@ ranlib $(LIB)/libobjet.a

clean:
	@ rm $(LIB)/libobjet.a objet.o