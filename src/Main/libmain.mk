CC= gcc
CFLAGS=  -Wall -g 
LIB= ../../lib
INC= ../../include
EXEC= libmain.a
SRC= main.c
OBJ= $(SRC:.c=.o)

all : $(EXEC)

main.o : main.c 
	@ $(CC) $(CFLAGS) `sdl2-config --cflags --libs` -lcrypt -ljson-c -c main.c -I $(INC)

$(EXEC) : $(OBJ) $(INC)/main.h
	@ ar rcs $(LIB)/libmain.a $(OBJ)
	@ ranlib $(LIB)/libmain.a

clean:
	@ rm $(LIB)/libmain.a main.o