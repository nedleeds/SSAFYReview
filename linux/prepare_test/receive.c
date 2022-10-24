#include <stdio.h>
#include <signal.h>
#include <pthread.h>
#include <unistd.h>

int cnt = 1;

void recieve(){
	printf("GOOD\n");
	cnt = 1;
}

void* UpCount(void* arg){
	while(1){
		printf("Cnt: %d\n", cnt);
		cnt++;
		sleep(1);
	}
}

int main(){

	signal(SIGUSR1, recieve);
	
	pthread_t t;

	pthread_create(&t, NULL, UpCount, NULL);

	pthread_join(t, NULL);


	return 0;
}
