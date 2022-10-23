#include <stdio.h>
#include <pthread.h>

void* VVCC(void* arg){
    int value = *(int*)arg;
    printf("%d ", value);
    return 0;
}

int main(){
    int values[37];
    pthread_t t_id[37];

    for (int i=0; i<37; i++){
        values[i] = i+1;
        pthread_create(&t_id[i], NULL, VVCC, &values[i]);
    }

    for (int i=0; i<37; i++){
        pthread_join(t_id[i], NULL);
    }

    printf("VVCC END\n");

    return 0;
}
