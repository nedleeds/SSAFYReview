#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void gogo(){
	printf("SYSTEM ERROR\n");
	exit(1);
}


int main(){
	signal(SIGALRM, gogo);
	char str[100] = "";
	while (1) {
		alarm(3);
		printf("Please enter command: ");
		scanf("%s", str);
		printf("%s\n", str);
	}

	return 0;
}
