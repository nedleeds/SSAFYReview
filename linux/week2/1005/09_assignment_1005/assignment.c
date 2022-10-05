#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* abc(void* arg){
    int* num = (int *)arg;
    if (*num == 1){
        printf("ABC\n");
    }else if (*num == 2){
        printf("MINMIN\n");
    }else if (*num == 3){
        printf("COCO\n");
    }else if (*num == 4){
        printf("KFCKFC\n");
    }else{
        printf("NUM is wrong!!\n");
        exit(1);
    }
}

int main()
{
    pthread_t tread[4];
    int indices[4];
    for (int i=0; i<4; i++){
        indices[i] = i + 1;
        pthread_create(&tread[i], NULL, abc, &indices[i]);
    }
    for (int i=0; i<4; i++){
        pthread_join(tread[i], NULL);
    }

    
    return 0;
}