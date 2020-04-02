#users
CC= gcc
CFLAGS=  -Wall -g 
LIB= ../../lib
LDFLAGS= -lm -lusers -lentrees -lcrypt -lobjet -ljson-c
INC= ../../include
EXEC= users.exe
SRC= main_users.c
OBJ= $(SRC:.c=.o)

all : $(EXEC)

$(EXEC): $(SRC)
	@ $(CC) $< -o $@ $(CFLAGS) $(LDFLAGS) -I $(INC) -L $(LIB)

clean:
	@ rm *.exe