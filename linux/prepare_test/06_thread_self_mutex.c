#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t mlock;

void* abc(void* arg){
    pthread_mutex_lock(&mlock);
    int t_id = *(int *)arg;
    char* s = NULL;
    
    if( t_id == 1 ){
        s = malloc(sizeof("ABC"));
        s = "ABC";
    }else if( t_id == 2 ){
        s = malloc(sizeof("MINMIN"));
        s = "MINMIN";
    }else if ( t_id == 3 ){
        s = malloc(sizeof("COCO"));
        s = "COCO";
    }else{
        s = malloc(sizeof("KFCKFC"));
        s = "KFCKFC";
    }
    printf("[%d]%s\n", t_id, s);
    pthread_mutex_unlock(&mlock);
    return 0;
}

int main(){
    pthread_t t_id[4];

    for (int i = 0; i < 4; i++){
        int thread_id = i + 1;
        pthread_create(&t_id[i], NULL, abc, &thread_id);
    }

    for (int i = 0; i < 4; i++){
        pthread_join(t_id[i], NULL);
    }


    return 0;
}
