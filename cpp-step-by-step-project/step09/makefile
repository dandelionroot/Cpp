CC = g++
CFLAGS = -Wall -g -c
INCLUDE = -I.

OBJS = String.o AccountPtrArray.o Account.o NormalAccount.o HighCreditAccount.o AccountHandler.o main.o

all : main

%.o : %.cpp
	$(CC) $(INCLUDE) $(CFLAGS) $<

main : $(OBJS)
	$(CC) -o $@ $(OBJS)

clean :
	rm -rf main $(OBJS)
