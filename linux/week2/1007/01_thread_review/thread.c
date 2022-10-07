#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

typedef struct _NODE_ {
	int y;
	int x;
}Node;

void* abc(void *p){
	Node* a = (Node *)p;

	while(1){
		printf("y:%d x:%d\n", a->y, a->x);
		sleep(1);
	}
}

void* bts(){
	while(1){
		printf("BTS\n");
		sleep(1);
	}
}

int main(){
	pthread_t t1, t2;

	Node n = {3, 4};

	pthread_create(&t1, NULL, abc, &n);
	pthread_create(&t2, NULL, bts, NULL);

	// join은 thread의 종료를 기다렸다 종료되면 동작
	// t1의 함수 종료를 기다렸다가 메모리를 비워준다
	pthread_join(t1, NULL);
	// t2의 함수 종료를 기다렸다가 메모리를 비워준다
	pthread_join(t2, NULL);
	return 0;
}
