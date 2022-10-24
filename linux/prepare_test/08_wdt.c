#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int input_flag = 0;
char s[1000] = "";

void gogo(){
    if (input_flag == 0){
        printf("Time over\n");
        exit(1);
    }
    else{
		s[0] = '\0';
		alram(3);
    }
}

int main(){
    signal(SIGALRM, gogo);

	while(1){
    	alarm(3);
    	printf("input>> ");
    	scanf("%s", s);
    	if (strlen(s) != 0){
        	input_flag = 1;
    	}
	}

    return 0;
}
