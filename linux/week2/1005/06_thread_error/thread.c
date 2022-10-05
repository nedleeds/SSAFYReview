#include <stdio.h>
#include <pthread.h>

pthread_t tid[4];

void* run(void *arg){
    int a = *(int *)arg;
    printf("%d\n", a);
}

int main(){
    int arr[4];
    for (int i=0; i<4; i++){
        arr[i] = i;
        pthread_create(&tid[i], NULL, run, &arr[i]);
    }
    
    for (int i=0; i<4; i++) pthread_join(tid[i], NULL);

    return 0;
}