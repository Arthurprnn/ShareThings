CC= gcc
CFLAGS=  -Wall -g #-std=c11
LIB= ../../lib
LDFLAGS= -lm 
INC= ../../include
EXEC= libprets.a
SRC= prets.c
OBJ= $(SRC:.c=.o)

all : $(EXEC)

prets.o : prets.c 
	@ $(CC) $(CFLAGS)  -c prets.c -I $(INC)

$(EXEC) : $(OBJ) $(INC)/prets.h
	@ ar rcs $(LIB)/libprets.a $(OBJ)
	@ ranlib $(LIB)/libprets.a

clean:
	@ rm $(LIB)/libprets.a prets.o