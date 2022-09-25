CC = gcc 
RESULT = go

${RESULT}: go.o hi.o
	${CC} $^ -o $@

go.o: go.c
	${CC} -c $^

hi.o: hi.c
	${CC} -c $^

clean:
	rm ./*.o ./$(RESULT)
