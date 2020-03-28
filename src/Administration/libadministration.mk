CC= gcc
CFLAGS=  -Wall -g #-std=c11
LIB= ../../lib
LDFLAGS= -lm 
INC= ../../include
EXEC= libadministration.a
SRC= administration.c
OBJ= $(SRC:.c=.o)

all : $(EXEC)

administration.o : administration.c 
	@ $(CC) $(CFLAGS)  -c administration.c -I $(INC)

$(EXEC) : $(OBJ) $(INC)/administration.h
	@ ar rcs $(LIB)/libadministration.a $(OBJ)
	@ ranlib $(LIB)/libadministration.a

clean:
	@ rm $(LIB)/libadministration.a administration.o