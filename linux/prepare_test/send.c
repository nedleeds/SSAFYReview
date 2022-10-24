#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>
#include <math.h>
#include <time.h>

char s[1000] = "";

void gogo(){
	if (strlen(s) != 1){
		printf("TIME OVER\n");
	}
	exit(1);
}

int main(){
	setbuf(stdin, NULL);
	signal(SIGALRM, gogo);

	char pid[1000] = "";
	printf("PID: ");
	scanf("%s", pid);
	printf("your PID is : %s\n", pid);

	int t = (int)random()*1000 % 4 + 1;
 	printf("random time: %d\n", t);
	sleep(t);
	kill(atoi(pid), SIGUSR1);
	printf("signal has been sent\n");

	while(1){
		alarm(5);
		printf("Enter any string(within 5 sec): ");
		scanf("%s", s);

		for (int i = 1000; i>=0; i--){
			if(s[i] != 0)
				printf("%c", s[i]);
		}
		memset(s, '\0', sizeof(s));
		printf("\n");
	}

	return 0;
}
