#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

int num;

int main(int argc, char* argv[]){
	if (argc != 2){
		printf("Person program arguments need: ./person #PID\n");	
		exit(1);
	}

	int pid = atoi(argv[1]);
	int cmd = 0;

	setbuf(stdout, NULL);
	
	while(1){
		printf(">> ");
		scanf("%d", &cmd);
		if (cmd == 1)
			kill(pid, SIGUSR1); 
		else if (cmd == 2)
			kill(pid, SIGUSR2); 
		else if (cmd == 3)
			kill(pid, SIGTERM);
		else
			exit(1);
	}

	return 0;
}
