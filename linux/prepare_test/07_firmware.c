#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int n = 1;

void Function1(){
    printf("[Button Clicked]\n");
}

void Function2(){
    system("clear");
    printf("RESET\n");
}

void Function3(){
    printf("BYE\n");
    n = 0;
}

void firmware(){
    for (char c='A'; c<='Z'; c++){
        printf("%c\n", c);
        usleep(100*1000);
    }

    for (char c = 'Z'; c >= 'A'; c--){
        printf("%c\n", c);
        usleep(100*1000);
    }
}

int main(int argc, char* argv[]){
    signal(SIGUSR1, Function1);
    signal(SIGUSR2, Function2);
    signal(SIGTERM, Function3);

    while(n) 
        firmware();

    return 0;
}
