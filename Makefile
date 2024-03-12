CC = gcc

CFLAGS  = -g

SRC = $(wildcard *.c)

OBJ = $(SRC:.c=.o)

all : puissance4


%.o : %.c
	$(CC) -c $< -o $@ $(CFLAGS)

puissance4 : $(OBJ)
	$(CC) -o $@ $^


clean :
	rm -rf *.o