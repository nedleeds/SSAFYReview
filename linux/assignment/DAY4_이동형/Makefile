CC = gcc
SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)
CFLAGS = -g -Wall -O2
SUFFIXES = .c.O2
TARGET = result

all: $(OBJS)
	@echo "==<FINISH>=="
	$(CC) -o $(TARGET) $^

.c.o:
	@echo "==[READY]=="
	$(CC) $(CFLAGS) -c $<

clean:
	rm -rf $(OBJS) result

dep:
	makedepend $(SRCS) -Y
