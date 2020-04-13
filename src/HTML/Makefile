#Administration
CC= gcc
CFLAGS=  -Wall -g 
LIB= ../../lib
LDFLAGS= -lm -ladministration -lhtml -lusers  -lobjet -lentrees -lcrypt -ljson-c
INC= ../../include
EXEC= html.exe
SRC= main_html.c
OBJ= $(SRC:.c=.o)

all : $(EXEC)

$(EXEC): $(SRC)
	@ $(CC) $< -o $@ $(CFLAGS) $(LDFLAGS) -I $(INC) -L $(LIB)

clean:
	@ rm *.exe