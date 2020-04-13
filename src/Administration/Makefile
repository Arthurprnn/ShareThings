#Administration
CC= gcc
CFLAGS=  -Wall -g 
LIB= ../../lib
LDFLAGS= -lm -ladministration -lcrypt -ltemps -lentrees -lusers -lobjet -lprets -ljson-c
INC= ../../include
EXEC= administration.exe
SRC= main_administration.c
OBJ= $(SRC:.c=.o)

all : $(EXEC)

$(EXEC): $(SRC)
	@ $(CC) $< -o $@ $(CFLAGS) $(LDFLAGS) -I $(INC) -L $(LIB)

clean:
	@ rm *.exe