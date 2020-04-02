#Main
CC= gcc
CFLAGS=  -Wall -g 
LIB= ../../lib
LDFLAGS= -lm -lSDL2 -ljson-c -lcrypt -ladministration -lentrees -lobjet -lusers -ltemps -lprets 
INC= ../../include
EXEC= ShareThings.exe
SRC= main.c
OBJ= $(SRC:.c=.o)

all : $(EXEC)

$(EXEC): $(SRC)
	@ $(CC) `sdl2-config --cflags --libs` $< -o $@ $(CFLAGS) $(LDFLAGS) -I $(INC) -L $(LIB)

clean:
	@ rm *.exe