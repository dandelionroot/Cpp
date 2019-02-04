CC = g++
CFLAGS = -Wall -g -c
INCLUDE = -I.

OBJS = bank-account-system3.o main.o

all : main

%.o : %.cpp
	$(CC) $(INCLUDE) $(CFLAGS) $<

main : $(OBJS)
	$(CC) -o $@ $(OBJS)

clean :
	rm -rf main $(OBJS)
