#include <stdio.h>
#include <pthread.h>

pthread_t tid[4];
int cnt;

void* run()
{
    for (int i=0; i<10000; i++) 
        cnt++;
}

int main()
{
    for (int i=0; i<4; i++){
        pthread_create(&tid[i], NULL, run, NULL);
        // usleep(100); // solution(1) -> page 109
    }
    for (int i=0; i<4; i++)
        pthread_join(tid[i], NULL);
    
    printf("%d\n", cnt);

    return 0;
}