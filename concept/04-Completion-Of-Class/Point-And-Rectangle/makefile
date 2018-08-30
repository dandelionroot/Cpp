CC = g++
CFLAGS = -Wall -g -c
INCLUDE = -I.
OBJS = Point.o Rectangle.o RectangleConstructor.o

all : RectangleConstructor

%.o : %.cpp
	$(CC) $(CFLAGS) $(INCLUDE) $<

RectangleConstructor : $(OBJS)
	$(CC) -o RectangleConstructor $(OBJS)

clean :
	rm -f RectangleConstructor $(OBJS)
