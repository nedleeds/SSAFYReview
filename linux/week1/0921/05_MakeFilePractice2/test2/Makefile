CC = gcc
CFLAGS = -g -Wall -O2
SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)
SUFFIXES = .c.O 
TARGET = result

all : $(OBJS)
	@echo "==<FINISH>=="
	$(CC) -o $(TARGET) $^

test1.o : test1.c a.h b.h
	$(CC) $(CFLAGS) -c $<

test2.o : test2.c a.h c.h
	$(CC) $(CFLAGS) -c $<

test3.o : test3.c a.h b.h c.h
	$(CC) $(CFLAGS) -c $<

clean : 
	rm -rf $(OBJS) result

dep : 
	makedepend $(SRCS) -Y

# DO NOT DELETE
test1.o: a.h b.h
test2.o: a.h c.h
test3.o: a.h b.h c.h
