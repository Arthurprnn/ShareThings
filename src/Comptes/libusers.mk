CC= gcc
CFLAGS=  -Wall -g #-std=c11
LIB= ../../lib
LDFLAGS= -lm
INC= ../../include
EXEC= libusers.a
SRC= users.c
OBJ= $(SRC:.c=.o)

all : $(EXEC)

users.o : users.c 
	@ $(CC) $(CFLAGS)  -c users.c -I $(INC)

$(EXEC) : $(OBJ) $(INC)/users.h
	@ ar rcs $(LIB)/libusers.a $(OBJ)
	@ ranlib $(LIB)/libusers.a

clean:
	@ rm $(LIB)/libusers.a users.o