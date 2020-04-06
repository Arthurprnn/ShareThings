#Main
CC= gcc
CFLAGS= -Wall -g `sdl2-config --cflags --libs`
LIB= ../../lib
LDFLAGS= -lm -lSDL2 -ladministration -lusers -lobjet -lprets -ltemps -lentrees -ljson-c -lcrypt
INC= ../../include
EXEC= ShareThings.exe
SRC= main.c

all : $(EXEC)

$(EXEC): $(SRC)
	@ $(CC) $< -o $@ $(CFLAGS) $(LDFLAGS) -I $(INC) -L $(LIB)

clean:
	@ rm *.exe