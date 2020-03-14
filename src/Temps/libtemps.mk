CC= gcc
CFLAGS=  -Wall -g #-std=c11
LIB= ../../lib
LDFLAGS= -lm 
INC= ../../include
EXEC= libtemps.a
SRC= temps.c
OBJ= $(SRC:.c=.o)

all : $(EXEC)

temps.o : temps.c 
	$(CC) $(CFLAGS)  -c temps.c -I $(INC)

$(EXEC) : $(OBJ) $(INC)/temps.h
	ar rcs $(LIB)/libtemps.a $(OBJ)
	ranlib $(LIB)/libtemps.a

clean:
	rm $(LIB)/libtemps.a temps.o