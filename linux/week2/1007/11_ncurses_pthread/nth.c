#include <ncurses.h>
#include <pthread.h>
#include <stdlib.h>

pthread_mutex_t mlock;

void* abc(){
	int num2 = 0;
	while(1){
		pthread_mutex_lock(&mlock);
		mvprintw(10, 30, "        ");
		mvprintw(10, 30, "%d", num2);
		refresh();
		pthread_mutex_unlock(&mlock);
		num2--;
	}

}

int main(){
	initscr();

	clear();

	pthread_mutex_init(&mlock, NULL);//mutex init
	pthread_t tid; //thread define;
	pthread_create(&tid, NULL, abc, NULL); //create thread

	int num = 0;
	while(1){
		pthread_mutex_lock(&mlock); // lock the mutex
		mvprintw(10, 10, "       ");// mvprintw
		mvprintw(10, 10, "%d", num);
		refresh();
		pthread_mutex_unlock(&mlock);//unlock the mutex
		num++;
	}
	pthread_join(tid, NULL);

	getch();
	endwin();
	return 0;
}
