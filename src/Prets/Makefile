CC= gcc
CFLAGS=  -Wall -g #-std=c11
LIB= ../../lib
LDFLAGS= -lm
INC= ../../include
EXEC= prets.exe
SRC= main_prets.c prets.c
OBJ= $(SRC:.c=.o)

all : $(EXEC)

$(EXEC): $(OBJ)
	@$(CC) -o $@ $^ $(LDFLAGS) $(CFLAGS) -I $(INC) -L $(LIB)

%.o: %.c 
	@$(CC) -o $@ -c $< $(CFLAGS) -I $(INC) -L $(LIB)

clean:
	rm *.exe *.o