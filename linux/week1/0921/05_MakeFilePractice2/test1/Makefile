CC = gcc
RESULT = go

go: go.o hi.o
	$(CC) -o go $@ $^ 

go.o: go.c
	$(CC) -c $^

hi.o: hi.c
	$(CC) -c $^

clean:
	rm ./*.o ./$(RESULT)
