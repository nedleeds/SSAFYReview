CC = gcc

problem_A: main.o  
	$(CC) $^  -o $@

problem_B: run.o
	$(CC) $^ -o $@ 

main.o: main.c
	$(CC) -c $^

run.o: run.c run.h
	$(CC) -c $<

