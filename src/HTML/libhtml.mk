CC= gcc
CFLAGS=  -Wall -g #-std=c11
LIB= ../../lib
LDFLAGS= -lm 
INC= ../../include
EXEC= libhtml.a
SRC= html.c
OBJ= $(SRC:.c=.o)

all : $(EXEC)

html.o : html.c 
	@ $(CC) $(CFLAGS)  -c html.c -I $(INC)

$(EXEC) : $(OBJ) $(INC)/html.h
	@ ar rcs $(LIB)/libhtml.a $(OBJ)
	@ ranlib $(LIB)/libhtml.a

clean:
	@ rm $(LIB)/libhtml.a html.o