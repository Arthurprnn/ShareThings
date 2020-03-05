CC= gcc
CFLAGS=  -Wall -g #-std=c11
LIB= ../../lib
LDFLAGS= -lm
INC= ../../include
EXEC= users.exe
SRC= main_users.c users.c
OBJ= $(SRC:.c=.o)

all : $(EXEC)

$(EXEC): $(OBJ)
	@$(CC) -o $@ $^ $(LDFLAGS) $(CFLAGS) -I $(INC) -L $(LIB)

%.o: %.c 
	@$(CC) -o $@ -c $< $(CFLAGS) -I $(INC) -L $(LIB)

clean:
	rm *.exe *.o