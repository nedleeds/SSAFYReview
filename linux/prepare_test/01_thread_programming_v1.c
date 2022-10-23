#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void* DD1(void* arg){
    char s[4] = "ABC";
    int i = 0;
    while (1){
        int idx = i % 3;
        printf("[DD1] %c\n", s[idx]);
        usleep(300*1000);
        i += 1;
    }
    return 0;
}

void* DD2(void* arg){
    int i = 0;
    while(1){
        int idx = i % 6;
        printf("[DD2] %d\n", idx);
        usleep(200*1000);
        i++;
    }
    return 0;
}


void* DD3(void* arg){
    int i = 0;
    while(1){
        char c = 'A' + (i)%26;
        printf("[DD3] %c\n", c);
        usleep(300*1000);
        i++;
    }
    return 0;
}

int main(){
    pthread_t t_id[3];
    void* functions[3] = {DD1, DD2, DD3};

    for (int i=0; i<3; i++){
        pthread_create(&t_id[i], NULL, functions[i], NULL);
    }

    for (int i=0; i<3; i++){
        pthread_join(t_id[i], NULL);
    }

    return 0;
}
