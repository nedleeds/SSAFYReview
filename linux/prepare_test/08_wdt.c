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
        printf("pass\n");
    }
}

int main(){
    signal(SIGALRM, gogo);

    printf("input>> ");
    alarm(3);
    scanf("%s", s);
    if (strlen(s) != 0){
        input_flag = 1;
    }

    while(1) sleep(1);
    return 0;
}
