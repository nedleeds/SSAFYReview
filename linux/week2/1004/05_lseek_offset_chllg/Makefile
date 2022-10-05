CC=gcc
OBJS=test.o 
SBJS=test.c 

test: $(OBJS) $(SBJS)
	$(CC) -c $(SBJS)
	$(CC) $< -o $@

clear:
	rm -rf $(OBJS) test
