#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

int input_flag = 0;
char s[1000] = "";

void gogo(){
    if (strlen(s) == 0){
        printf("Time over\n");
        exit(1);
    }
		s[0] = '\0';
		return ;
}

void* get_input(void* arg){
	while(1){
		printf("input>> ");	
    	scanf("%s", s);
		printf("echo>> %s", s);
	}
}

void* watch_dog(void* arg){
	alarm(3);
}

int main(){
    signal(SIGALRM, gogo);
	pthread_t t_id[2];
	void* functions[2] = {get_input, watch_dog};


	for(int i=0; i<2; i++){
		pthread_create(&t_id[i], NULL, functions[i], NULL);
	}

	for (int i=0; i<2; i++){
 		pthread_join(t_id[i], NULL);
	}

		// pause();
    return 0;
}
