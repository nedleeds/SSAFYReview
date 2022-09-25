CC = gcc
CFLAGS = -g -Wall -O2
TARGET = test
SRCS = $(wildcard *.c) 
OBJS = $(SRCS:.c=.o)

all : $(OBJS)
	$(CC) $^ -o $(TARGET)

clean:
	rm $(OBJS) $(TARGET)

dep : makedepend $(SRCS) -Y
