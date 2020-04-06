#Main
CC= gcc
CFLAGS=  -Wall -g `sdl2-config --cflags --libs` -lSDL2 -lSDL2_ttf 
LIB= ../../lib
LDFLAGS= -lm -ladministration -lentrees -lusers -lobjet -lprets -ltemps -ljson-c -lcrypt
INC= ../../include
EXEC= ShareThings.exe
SRC= main.c
OBJ= $(SRC:.c=.o)

all : $(EXEC)

$(EXEC): $(OBJ)
	@ $(CC) $< -o $@ $(CFLAGS) $(LDFLAGS) -I $(INC) -L $(LIB)

clean:
	@ rm *.exe