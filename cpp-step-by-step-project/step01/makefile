CC = g++
CFLAGS = -Wall -g -c
INCLUDE = -I.

OBJS = main.o bank-account-system.o

all : main

%.o : %.cpp
	$(CC) $(INCLUDE) $(CFLAGS) $<

main : $(OBJS)
	$(CC) -o $@ $(OBJS)

clean :
	rm -f main $(OBJS)
