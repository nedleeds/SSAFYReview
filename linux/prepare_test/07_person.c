#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

int main(int argc, char* argv[]){
    int pid = atoi(argv[1]);
    int cmd = 0;
    
    setbuf(stdout, NULL);
    while(1){
        printf("cmd(1/2/3): ");
        scanf("%d", &cmd);

        if (cmd == 1){
            kill(pid, SIGUSR1);
        }
        else if (cmd == 2){
            kill(pid, SIGUSR2);
        }
        else if (cmd == 3){
            kill(pid, SIGTERM);
        }
        else{
            break;
        }
    }

    return 0;
}
