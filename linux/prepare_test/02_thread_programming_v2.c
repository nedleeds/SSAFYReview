#include <stdio.h>
#include <pthread.h>

typedef struct _Node_{
    int y, x;
}Node;

void* abc(void *p){
    Node* pN = (Node*)p;

    printf("y: %d, x: %d\n", pN->y, pN->x);
    return 0;
}

int main(){
    pthread_t t;
    Node n = {123, 456};

    pthread_create(&t, NULL, abc, &n);
    pthread_join(t, NULL);

    return 0;
}
