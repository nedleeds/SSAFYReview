#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void ISR1(){
	printf("Button Clicked\n");
}

void ISR2(){
	system("clear");
	printf("RESET\n");
}

void ISR3(){
	printf("BYE\n");
	exit(1);
}

int main(){
	setbuf(stdout, NULL);
	signal(SIGUSR1, ISR1);
	signal(SIGUSR2, ISR2);
	signal(SIGTERM, ISR3);

	while(1){
		for (int i=0; i<26; i++){
			printf("%c", (char)('A'+i));
			usleep(100*1000);
		}
		for (int i=0; i<26; i++){
			printf("%c", (char)('Z'-i));
			usleep(100*1000);
		}
	}

	return 0;
}
