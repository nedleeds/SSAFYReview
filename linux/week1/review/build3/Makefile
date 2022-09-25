CC = gcc
CFLAGS = -g -Wall -O2
SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)
TARGET = result

all: $(OBJS)
	@echo "==<FINISH>=="
	$(CC) -o $(TARGET) $^

.c.o:
	@echo "==[READY]=="
	$(CC) $(CFLAGS) -c $<

temp:
	@echo ${SRCS}
	@echo ${OBJS}

result: ${OBJS}
	${CC} $^ -o $@

test1.o: test1.c a.h b.h
	${CC} ${CFLAGS} -c $<

test2.o: test2.c a.h c.h
	${CC} $(CFLAGS) -c $<

test3.o: test3.c a.h b.h c.h
	${CC} $(CFLAGS) -c $<

clean:
	rm ${OBJS} $(TARGET)

dep:
	makedepend $(SRCS) -Y

# DO NOT DELETE

test2.o: a.h c.h
test3.o: a.h b.h c.h
test1.o: a.h b.h
